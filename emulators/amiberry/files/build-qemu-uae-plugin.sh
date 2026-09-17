#!/bin/sh
set -eu

qemu_version="11.0.1"
qemu_archive="qemu-${qemu_version}.tar.xz"
qemu_url_default="https://download.qemu.org/${qemu_archive}"
qemu_sha256="0d235f5820278d914a3155ec27af8e4258d697ea892895570807d69c0cb8cd64"

script_dir="$(cd "$(dirname "$0")" && pwd)"
patch_dir="${QEMU_UAE_PATCH_DIR:-${script_dir}/patches}"
patch_file="${QEMU_UAE_PATCH:-}"
work_dir="${QEMU_UAE_WORK_DIR:-${script_dir}/build}"
qemu_url="${QEMU_UAE_QEMU_URL:-${qemu_url_default}}"
tarball="${QEMU_UAE_TARBALL:-}"
source_dir="${QEMU_UAE_SOURCE_DIR:-}"
output_plugin="${QEMU_UAE_OUTPUT_PLUGIN:-}"
deps_prefix="${QEMU_UAE_DEPS_PREFIX:-}"
jobs="${QEMU_UAE_JOBS:-}"
clean=0
verify=1
strip_plugin="${QEMU_UAE_STRIP:-1}"
static_deps="${QEMU_UAE_STATIC_DEPS:-0}"
host_system="$(uname -s)"

case "${host_system}" in
    Darwin*)
        plugin_extension="dylib"
        ;;
    MINGW*|MSYS*|CYGWIN*)
        plugin_extension="dll"
        ;;
    *)
        plugin_extension="so"
        ;;
esac
plugin_name="qemu-uae.${plugin_extension}"

usage() {
    cat <<EOF
Usage: $0 [options] [-- configure-arg ...]

Download QEMU ${qemu_version}, apply the QEMU-UAE patch deck, and build
the native qemu-uae plugin artifact.

Options:
  --work-dir DIR       Working directory. Default: ./build next to script.
  --source-dir DIR     Patched QEMU source directory.
  --tarball FILE       Use an existing QEMU ${qemu_version} tarball.
  --url URL            Download URL. Default: ${qemu_url_default}
  --output FILE        Copy the finished qemu-uae plugin to FILE.
  --patch-dir DIR      Directory containing ordered *.patch files.
  -j, --jobs N         Ninja parallelism.
  --clean              Remove the source directory before extracting.
  --no-verify          Skip tarball SHA-256 verification.
  --no-strip           Keep debug/local symbols in the output plugin.
  --static-deps        Link external dependencies statically. Windows only.
  -h, --help           Show this help.

Environment:
  QEMU_UAE_PATCH       Single patch file override.
  QEMU_UAE_PATCH_DIR   Directory containing ordered *.patch files.
  QEMU_UAE_DEPS_PREFIX  Prefix containing dependency pkg-config files.
  QEMU_UAE_NINJA        Ninja executable. Defaults to ninja in PATH.
  QEMU_UAE_STATIC_DEPS  Set to 1/true/yes/on to enable --static-deps.
  QEMU_UAE_STRIP        Set to 0/false/no/off to keep symbols.
  QEMU_UAE_STRIP_TOOL   Strip executable. Defaults to llvm-strip or strip.
  MACOSX_DEPLOYMENT_TARGET
                         macOS deployment target. Default on Darwin: 13.0.
EOF
}

die() {
    echo "error: $*" >&2
    exit 1
}

while [ $# -gt 0 ]; do
    case "$1" in
        --work-dir)
            [ $# -ge 2 ] || die "--work-dir requires an argument"
            work_dir="$2"
            shift 2
            ;;
        --source-dir)
            [ $# -ge 2 ] || die "--source-dir requires an argument"
            source_dir="$2"
            shift 2
            ;;
        --tarball)
            [ $# -ge 2 ] || die "--tarball requires an argument"
            tarball="$2"
            shift 2
            ;;
        --url)
            [ $# -ge 2 ] || die "--url requires an argument"
            qemu_url="$2"
            shift 2
            ;;
        --output)
            [ $# -ge 2 ] || die "--output requires an argument"
            output_plugin="$2"
            shift 2
            ;;
        --patch-dir)
            [ $# -ge 2 ] || die "--patch-dir requires an argument"
            patch_dir="$2"
            shift 2
            ;;
        -j|--jobs)
            [ $# -ge 2 ] || die "$1 requires an argument"
            jobs="$2"
            shift 2
            ;;
        --clean)
            clean=1
            shift
            ;;
        --no-verify)
            verify=0
            shift
            ;;
        --no-strip)
            strip_plugin=0
            shift
            ;;
        --static-deps)
            static_deps=1
            shift
            ;;
        -h|--help)
            usage
            exit 0
            ;;
        --)
            shift
            break
            ;;
        *)
            die "unknown option: $1"
            ;;
    esac
done

case "${strip_plugin}" in
    0|false|False|FALSE|no|No|NO|off|Off|OFF)
        strip_plugin=0
        ;;
    *)
        strip_plugin=1
        ;;
esac

case "${static_deps}" in
    1|true|True|TRUE|yes|Yes|YES|on|On|ON)
        static_deps=1
        ;;
    0|false|False|FALSE|no|No|NO|off|Off|OFF)
        static_deps=0
        ;;
    *)
        die "invalid QEMU_UAE_STATIC_DEPS value: ${static_deps}"
        ;;
esac

if [ "${static_deps}" = "1" ]; then
    case "${host_system}" in
        MINGW*|MSYS*|CYGWIN*)
            ;;
        *)
            die "--static-deps is currently supported only on Windows/MSYS2 hosts"
            ;;
    esac
fi

download_dir="${work_dir}/downloads"
if [ -z "${tarball}" ]; then
    tarball="${download_dir}/${qemu_archive}"
fi
if [ -z "${source_dir}" ]; then
    source_dir="${work_dir}/qemu-${qemu_version}-uae"
fi
if [ -z "${output_plugin}" ]; then
    output_plugin="${work_dir}/${plugin_name}"
fi

if [ -z "${jobs}" ]; then
    if command -v sysctl >/dev/null 2>&1; then
        jobs="$(sysctl -n hw.ncpu 2>/dev/null || true)"
    fi
    if [ -z "${jobs}" ] && command -v nproc >/dev/null 2>&1; then
        jobs="$(nproc)"
    fi
    jobs="${jobs:-4}"
fi

if [ -n "${deps_prefix}" ]; then
    [ -d "${deps_prefix}" ] || die "dependency prefix does not exist: ${deps_prefix}"
    deps_prefix="$(cd "${deps_prefix}" && pwd)"
    export PATH="${deps_prefix}/bin:${PATH}"
    export PKG_CONFIG_LIBDIR="${deps_prefix}/lib/pkgconfig:${deps_prefix}/share/pkgconfig${PKG_CONFIG_LIBDIR:+:${PKG_CONFIG_LIBDIR}}"
fi

if [ "${host_system}" = "Darwin" ]; then
    export MACOSX_DEPLOYMENT_TARGET="${MACOSX_DEPLOYMENT_TARGET:-13.0}"
fi

download_qemu() {
    if [ -f "${tarball}" ]; then
        return
    fi

    mkdir -p "$(dirname "${tarball}")"
    local tmp="${tarball}.tmp"
    rm -f "${tmp}"

    if command -v curl >/dev/null 2>&1; then
        curl -L --fail -o "${tmp}" "${qemu_url}"
    elif command -v wget >/dev/null 2>&1; then
        wget -O "${tmp}" "${qemu_url}"
    else
        die "curl or wget is required to download ${qemu_url}"
    fi

    mv "${tmp}" "${tarball}"
}

sha256_file() {
    if command -v sha256sum >/dev/null 2>&1; then
        sha256sum "$1" | awk '{print $1}'
    elif command -v shasum >/dev/null 2>&1; then
        shasum -a 256 "$1" | awk '{print $1}'
    else
        return 1
    fi
}

verify_qemu() {
    [ "${verify}" = "1" ] || return

    local actual
    actual="$(sha256_file "${tarball}")" || die "no SHA-256 tool found; use --no-verify to skip"
    [ "${actual}" = "${qemu_sha256}" ] || die "SHA-256 mismatch for ${tarball}"
}

extract_qemu() {
    if [ "${clean}" = "1" ]; then
        rm -rf "${source_dir}"
    fi
    if [ -d "${source_dir}" ]; then
        return
    fi

    mkdir -p "${work_dir}" "$(dirname "${source_dir}")"
    local extract_dir="${work_dir}/.extract.$$"
    rm -rf "${extract_dir}"
    mkdir -p "${extract_dir}"

    case "${host_system}" in
        MINGW*|MSYS*|CYGWIN*)
            tar -xf "${tarball}" -C "${extract_dir}" \
                --exclude="qemu-${qemu_version}/roms" \
                --exclude="qemu-${qemu_version}/roms/*" \
                --exclude="qemu-${qemu_version}/tests/lcitool" \
                --exclude="qemu-${qemu_version}/tests/lcitool/*"
            ;;
        *)
            tar -xf "${tarball}" -C "${extract_dir}"
            ;;
    esac

    mv "${extract_dir}/qemu-${qemu_version}" "${source_dir}"
    rm -rf "${extract_dir}"
}

apply_qemu_patch_file() {
    local patch_file="$1"
    local patch_name
    patch_name="$(basename "${patch_file}")"
    local forward_output
    local reverse_output
    forward_output="$(mktemp)"
    reverse_output="$(mktemp)"

    # Using -C instead of --dry-run for FreeBSD patch compatibility
    if (cd "${source_dir}" && patch -p1 -C -f < "${patch_file}" >"${forward_output}" 2>&1); then
        rm -f "${forward_output}" "${reverse_output}"
        echo "applying ${patch_name}"
        (cd "${source_dir}" && patch -p1 -f < "${patch_file}")
    elif (cd "${source_dir}" && patch -p1 -R -C -f < "${patch_file}" >"${reverse_output}" 2>&1); then
        rm -f "${forward_output}" "${reverse_output}"
        echo "${patch_name} already applied"
    else
        echo "${patch_name} forward check failed:" >&2
        cat "${forward_output}" >&2
        echo "${patch_name} reverse check failed:" >&2
        cat "${reverse_output}" >&2
        rm -f "${forward_output}" "${reverse_output}"
        die "${patch_name} does not apply cleanly to ${source_dir}"
    fi
}

apply_qemu_patches() {
    if [ -n "${patch_file}" ]; then
        [ -f "${patch_file}" ] || die "patch not found: ${patch_file}"
        apply_qemu_patch_file "${patch_file}"
    else
        [ -d "${patch_dir}" ] || die "patch directory not found: ${patch_dir}"

        # POSIX safe iteration of sorted files
        for patch in $(ls "${patch_dir}"/*.patch 2>/dev/null | sort); do
            [ -f "${patch}" ] || continue
            apply_qemu_patch_file "${patch}"
        done
    fi

    chmod +x "${source_dir}/configure-qemu-uae"
}

find_ninja() {
    if [ -n "${QEMU_UAE_NINJA:-}" ]; then
        echo "${QEMU_UAE_NINJA}"
    elif command -v ninja >/dev/null 2>&1; then
        command -v ninja
    elif command -v ninja-build >/dev/null 2>&1; then
        command -v ninja-build
    else
        return 1
    fi
}

find_strip() {
    if [ -n "${QEMU_UAE_STRIP_TOOL:-}" ]; then
        command -v "${QEMU_UAE_STRIP_TOOL}" || return 1
    elif command -v llvm-strip >/dev/null 2>&1; then
        command -v llvm-strip
    elif command -v strip >/dev/null 2>&1; then
        command -v strip
    else
        return 1
    fi
}

file_size_bytes() {
    stat -c '%s' "$1" 2>/dev/null || stat -f '%z' "$1" 2>/dev/null || wc -c < "$1" | awk '{print $1}'
}

strip_qemu_uae_plugin() {
    local plugin="$1"
    [ "${strip_plugin}" = "1" ] || return

    local strip_tool
    if ! strip_tool="$(find_strip)"; then
        echo "warning: no strip tool found; leaving ${plugin_name} unstripped" >&2
        return
    fi

    local before
    local after
    before="$(file_size_bytes "${plugin}")"
    case "${host_system}" in
        Darwin*)
            "${strip_tool}" -S -x "${plugin}"
            ;;
        *)
            "${strip_tool}" --strip-unneeded "${plugin}"
            ;;
    esac
    after="$(file_size_bytes "${plugin}")"
    echo "stripped ${plugin_name}: ${before} -> ${after} bytes"
}

build_qemu_uae() {
    local ninja
    ninja="$(find_ninja)" || die "ninja not found; set QEMU_UAE_NINJA"

    if [ "${static_deps}" = "1" ]; then
        local pkg_config_tool="${PKG_CONFIG:-}"
        if [ -z "${pkg_config_tool}" ]; then
            pkg_config_tool="$(command -v pkg-config || command -v pkgconf || true)"
            [ -n "${pkg_config_tool}" ] || die "pkg-config not found"
        fi
        if command -v cygpath >/dev/null 2>&1; then
            local pkg_config_exe="${pkg_config_tool%% *}"
            local pkg_config_args=""
            if [ "${pkg_config_tool}" != "${pkg_config_exe}" ]; then
                pkg_config_args="${pkg_config_tool#${pkg_config_exe}}"
            fi
            pkg_config_exe="$(cygpath -m "${pkg_config_exe}")"
            pkg_config_tool="${pkg_config_exe}${pkg_config_args}"
        fi
        case " ${pkg_config_tool} " in
            *" --static "*)
                export PKG_CONFIG="${pkg_config_tool}"
                ;;
            *)
                export PKG_CONFIG="${pkg_config_tool} --static"
                ;;
        esac
        # Inject standard static flags alongside whatever user args are in $@
        set -- ./configure-qemu-uae --ninja="${ninja}" --static --extra-ldflags=-static "$@"
    else
        # Prepend configure script and ninja explicitly to user args
        set -- ./configure-qemu-uae --ninja="${ninja}" "$@"
    fi

    (
        cd "${source_dir}" || exit 1
        "$@"
    )
    "${ninja}" -C "${source_dir}/build" -j "${jobs}" "${plugin_name}"

    local built_plugin="${source_dir}/build/${plugin_name}"
    [ -f "${built_plugin}" ] || die "${plugin_name} was not produced"
    mkdir -p "$(dirname "${output_plugin}")"
    cp "${built_plugin}" "${output_plugin}"
    strip_qemu_uae_plugin "${output_plugin}"
}

download_qemu
verify_qemu
extract_qemu
apply_qemu_patches

# $@ at this point contains only the leftover configure arguments
build_qemu_uae "$@"

echo "${output_plugin}"
