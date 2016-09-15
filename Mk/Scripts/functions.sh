#!/bin/sh
# $FreeBSD$
# This file for common functions used for port scripts.
#
# MAINTAINER: portmgr@FreeBSD.org

# Expand TMPPLIST to absolute paths, splitting files and dirs into separate
# descriptors.
# Input:
#  fd:0 - plist to parse
# Required params:
#  PREFIX
#  parse_comments: Whether to parse and include commented files.
# Output:
#  fd:1 - list of files
#  fd:2 - stderr
#  fd:3 - list of directories
parse_plist() {
	local cwd cwd_save commented_cwd comment line newcwd parse_comments \
	    PREFIX

	PREFIX="${1}"
	parse_comments="${2:-1}"

	cwd=${PREFIX}
	cwd_save=
	commented_cwd=
	while read -r line; do
		# Handle deactivated OPTIONS. Treat "@comment file" as being in
		# the plist so it does not show up as an orphan. PLIST_SUB uses
		# a @comment to deactive files. XXX: It would be better to
		# make all ports use @ignore instead of @comment.
		if [ ${parse_comments} -eq 1 -a -z "${line%%@comment *}" ]; then
			line="${line##*@comment }"
			# Remove @comment so it can be parsed as a file,
			# but later prepend it again to create a list of
			# all files commented and uncommented.
			comment="@comment "
			# Only consider comment @cwd for commented lines
			if [ -n "${commented_cwd}" ]; then
				[ -z "${cwd_save}" ] && cwd_save=${cwd}
				cwd=${commented_cwd}
			fi
		else
			comment=
			# On first uncommented line, forget about commented
			# @cwd
			if [ -n "${cwd_save}" ]; then
				cwd=${cwd_save}
				cwd_save=
				commented_cwd=
			fi
		fi

		# Strip (owner,group,perm) from keywords
		line="$(printf %s "$line" \
		    | sed -Ee 's/^@\([^)]*\)[[:space:]]+//' \
			-e 's/^(@[[:alpha:]]+)\([^)]*\)[[:space:]]+/\1 /')"
		case $line in
		@dir*|'@unexec rmdir'*|'@unexec /bin/rmdir'*)
			line="$(printf %s "$line" \
			    | sed -Ee 's/\|\|.*//;s|[[:space:]]+[0-9]*[[:space:]]*>[&]?[[:space:]]*[^[:space:]]+||g' \
			        -e "/^@unexec[[:space:]]+(\/bin\/)?rmdir( -p)?/s|([^%])%D([^%])|\1${cwd}\2|g" \
			        -e '/^@unexec[[:space:]]+(\/bin\/)?rmdir( -p)?/s|"(.*)"[[:space:]]*|\1|g' \
			        -e 's/@unexec[[:space:]]+(\/bin\/)?rmdir( -p)?[[:space:]]+//' \
				-e 's/@dir(rm|rmtry)?[[:space:]]+//' \
				-e 's/[[:space:]]+$//')"
			case "$line" in
			/*) echo >&3 "${comment}${line%/}" ;;
			*)  echo >&3 "${comment}${cwd}/${line%/}" ;;
			esac
		;;
		# Handle [file] Keywords
		@info\ *|@shell\ *|@xmlcatmgr\ *)
			set -- $line
			shift
			case "$@" in
			/*) echo "${comment}$@" ;;
			*) echo "${comment}${cwd}/$@" ;;
			esac
		;;
		@sample\ *)
			set -- $line
			shift
			sample_file=$1
			target_file=${1%.sample}
			if [ $# -eq 2 ]; then
				target_file=$2
			fi
			case "${sample_file}" in
			/*) ;;
			*) sample_file=${cwd}/${sample_file} ;;
			esac
			case "${target_file}" in
			/*) ;;
			*) target_file=${cwd}/${target_file} ;;
			esac
			# Ignore the actual file if it is in stagedir
			echo "@comment ${target_file}"
			echo "${comment}${sample_file}"
		;;
		# Handle [dir] Keywords
		@fc\ *|@fcfontsdir\ *|@fontsdir\ *)
			set -- $line
			shift
			case "$@" in
			/*)
			echo >&3 "${comment}$@"
			;;
			*)
			echo >&3 "${comment}${cwd}/$@"
			;;
			esac
		;;

		# order matters here - we must check @cwd first because
		# otherwise the @cwd* would also match it first, shadowing the
		# @cwd) line.
		@cwd|@cd)
			# Don't actually reset cwd for commented @cwd
			if [ -n "${comment}" ]; then
				commented_cwd=${PREFIX}
			else
				cwd=${PREFIX}
			fi
			;;
		@cwd*|@cd*)
			set -- $line
			newcwd=$2
			# Don't set cwd=/ as it causes // in plist and
			# won't match later.
			[ "${newcwd}" = "/" ] && newcwd=
			# Don't actually reset cwd for commented @cwd
			if [ -n "${comment}" ]; then
				commented_cwd=${newcwd}
			else
				cwd=${newcwd}
			fi
			unset newcwd
			;;
		@*) ;;
		/*) echo "${comment}${line}" ;;
		*)  echo "${comment}${cwd}/${line}" ;;
		esac
	done
}

validate_env() {
	local envfault
	for i ; do
		if ! (eval ": \${${i}?}" ) >/dev/null; then
			envfault="${envfault}${envfault:+" "}${i}"
		fi
	done
	if [ -n "${envfault}" ]; then
		echo "Environment variable ${envfault} undefined. Aborting." \
		| fmt >&2
		exit 1
	fi
}

export_ports_env() {
	local export_vars make_cmd make_env var results value uses

	validate_env MAKE PORTSDIR

	uses="python"

	make_env="\
		_PORTS_ENV_CHECK=1 \
		PACKAGE_BUILDING=1 \
		GNU_CONFIGURE=1 \
		USE_JAVA=1 \
		USE_LINUX=1 \
	"

	make_cmd="${make_env}"

	export_vars="\
		ARCH \
		CONFIGURE_MAX_CMD_LEN \
		HAVE_COMPAT_IA32_KERN \
		OPSYS \
		OSREL \
		OSVERSION \
		PYTHONBASE \
		UID \
		_JAVA_OS_LIST_REGEXP \
		_JAVA_PORTS_INSTALLED \
		_JAVA_VENDOR_LIST_REGEXP \
		_JAVA_VERSION_LIST_REGEXP \
		_OSRELEASE \
		_PERL5_FROM_BIN \
		_PKG_CHECKED \
		_PYTHON_DEFAULT_VERSION \
		_SMP_CPUS \
	"

	for var in ${export_vars}; do
		make_cmd="${make_cmd}${make_cmd:+ }-V ${var}=\${${var}:Q}"
	done

	# Bring in all the vars, but not empty ones.
	eval $(${MAKE} -f ${PORTSDIR}/Mk/bsd.port.mk ${make_cmd} \
	    USES="${uses}" | grep -v '=$')
	for var in ${export_vars}; do
		# Export and display non-empty ones.  This is not redundant
		# with above since we're looping on all vars here; do not
		# export a var we didn't eval in.
		value="$(eval echo \$${var})"

		if [ -n "${value}" ]; then
			export ${var}
			echo "export ${var}=\"${value}\""
		fi
	done
}

distinfo_data() {
	local alg file

	alg=$1
	file=$2

	if [ \( -n "${dp_DISABLE_SIZE}" -a -n "${dp_NO_CHECKSUM}" \) -o ! -f "${dp_DISTINFO_FILE}" ]; then
		exit
	fi
	awk -v alg="$alg" -v file="${file}" \
		'$1 == alg && $2 == "(" file ")" {print $4}' "${dp_DISTINFO_FILE}"
}

check_checksum_algorithms() {
	for alg in ${dp_CHECKSUM_ALGORITHMS}; do
		eval "alg_executable=\$dp_$alg"
		if [ -z "$alg_executable" ]; then
			${dp_ECHO_MSG} "Checksum algorithm $alg: Couldn't find the executable."
			${dp_ECHO_MSG} "Set $alg=/path/to/$alg in /etc/make.conf and try again."
			exit 1
		elif [ ! -x "$alg_executable" ]; then
			${dp_ECHO_MSG} "Checksum algorithm $alg: $alg_executable is not executable."
			${dp_ECHO_MSG} "Fix modes, or change $alg=$alg_executable in /etc/make.conf and try again."
			exit 1
		fi
	done
}
escape() {
	echo "$1" | sed -e 's/[&;()!#]/\\&/g'
}
unescape() {
	echo "$1" | sed -e 's/\\//g'
}

# Fetch vars from the Makefile and set them locally.
# port_var_fetch ports-mgmt/pkg "" PKGNAME pkgname PKGBASE pkgbase ...
# the 2nd variable is for passing any wanted make arguments, such as
# DEPENDS_ARGS.
port_var_fetch() {
	local origin="$1"
	local make_args="$2"
	local _makeflags _vars
	local _portvar _var _line

	_makeflags=
	_vars=
	shift 2
	while [ $# -ge 2 ]; do
		_portvar="$1"
		_var="$2"
		_makeflags="${_makeflags}${_makeflags:+ }-V${_portvar}"
		_vars="${_vars}${_vars:+ }${_var}"
		shift 2
	done
	set -- ${_vars}
	while read -r _line; do
		setvar "$1" "${_line}"
		shift
	done <<-EOF
	$(${dp_MAKE} -C "${origin}" ${make_args} ${_makeflags} || echo)
	EOF
}
