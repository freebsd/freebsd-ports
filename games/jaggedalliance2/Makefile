PORTNAME=	ja2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
PORTREVISION=	15
CATEGORIES=	games

MAINTAINER=	timp87@gmail.com
COMMENT=	Port of "Jagged Alliance 2" using SDL
WWW=		https://ja2-stracciatella.github.io/

LICENSE=		PD SFI-SCLA
LICENSE_COMB=		multi
LICENSE_NAME_SFI-SCLA=	Strategy First Inc. Source Code License Agreement
LICENSE_FILE_SFI-SCLA=	${WRKSRC}/SFI\ Source\ Code\ license\ agreement.txt
LICENSE_PERMS_SFI-SCLA=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell \
			auto-accept
LICENSE_DISTFILES_SFI-SCLA=	${DISTNAME}${EXTRACT_SUFX}

# Ignore this if you feel adventurous
ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	requires little endian environment
BROKEN_FreeBSD_15=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276701

BUILD_DEPENDS=	string_theory>=3.8:devel/string_theory \
		magic_enum>-0.8.2:devel/magic_enum \
		sol2>=3.2.2:devel/sol2 \
		miniaudio>=0.11:audio/miniaudio
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		cargo cmake compiler:c++20-lang pkgconfig sdl xorg gl lua:53+
USE_GITHUB=	yes
GH_ACCOUNT=	ja2-stracciatella
GH_PROJECT=	ja2-stracciatella
USE_SDL=	sdl2
USE_GL=		gl
USE_XORG=	ice sm x11 xext

CARGO_CRATES=	addr2line-0.17.0 \
		adler-1.0.2 \
		ahash-0.7.6 \
		aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		anyhow-1.0.69 \
		ascii-0.9.3 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		backtrace-0.3.65 \
		base64-0.13.1 \
		bit-set-0.5.3 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		block-buffer-0.10.3 \
		bytecount-0.6.3 \
		byteorder-1.4.3 \
		bytes-1.4.0 \
		caseless-0.2.1 \
		cbindgen-0.20.0 \
		cc-1.0.73 \
		cesu8-1.1.0 \
		cfg-if-1.0.0 \
		clap-2.33.4 \
		combine-3.8.1 \
		combine-4.6.4 \
		crossbeam-channel-0.5.4 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		crypto-common-0.1.6 \
		cty-0.2.2 \
		deunicode-0.4.3 \
		digest-0.10.6 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		dunce-1.0.2 \
		either-1.6.1 \
		error-chain-0.12.4 \
		fancy-regex-0.8.0 \
		fastrand-1.7.0 \
		form_urlencoded-1.1.0 \
		fraction-0.10.0 \
		generic-array-0.14.5 \
		getopts-0.2.21 \
		getrandom-0.2.6 \
		gimli-0.26.1 \
		hashbrown-0.12.3 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		idna-0.3.0 \
		indexmap-1.9.2 \
		instant-0.1.12 \
		iso8601-0.4.2 \
		itoa-1.0.1 \
		json_comments-0.2.1 \
		jsonschema-0.16.0 \
		lazy_static-1.4.0 \
		libc-0.2.124 \
		lock_api-0.4.9 \
		log-0.4.16 \
		lru-0.8.1 \
		md-5-0.10.5 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.5.1 \
		nom-7.1.3 \
		num-0.2.1 \
		num-bigint-0.2.6 \
		num-cmp-0.1.0 \
		num-complex-0.2.4 \
		num-integer-0.1.45 \
		num-iter-0.1.43 \
		num-rational-0.2.4 \
		num-traits-0.2.15 \
		num_cpus-1.13.1 \
		num_enum-0.5.7 \
		num_enum_derive-0.5.7 \
		num_threads-0.1.6 \
		object-0.28.3 \
		once_cell-1.10.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.7 \
		percent-encoding-2.2.0 \
		proc-macro-crate-1.1.3 \
		proc-macro2-1.0.51 \
		quote-1.0.18 \
		raw-window-handle-0.5.0 \
		rayon-1.6.1 \
		rayon-core-1.10.2 \
		redox_syscall-0.2.13 \
		redox_users-0.4.3 \
		regex-1.7.1 \
		regex-syntax-0.6.28 \
		remove_dir_all-0.5.3 \
		rustc-demangle-0.1.21 \
		ryu-1.0.9 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.152 \
		serde_derive-1.0.152 \
		serde_json-1.0.93 \
		serde_yaml-0.9.17 \
		simplelog-0.12.0 \
		slug-0.1.4 \
		smallvec-1.10.0 \
		strsim-0.8.0 \
		syn-1.0.107 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		textwrap-0.11.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		time-0.3.15 \
		time-macros-0.2.4 \
		tinyvec-1.6.0 \
		tinyvec_macros-0.1.1 \
		toml-0.5.9 \
		typenum-1.15.0 \
		unicode-bidi-0.3.10 \
		unicode-ident-1.0.6 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.9 \
		unreachable-1.0.0 \
		unsafe-libyaml-0.2.5 \
		url-2.3.1 \
		uuid-0.8.2 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		void-1.0.2 \
		walkdir-2.3.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.45.0 \
		windows-targets-0.42.1 \
		windows_aarch64_gnullvm-0.42.1 \
		windows_aarch64_msvc-0.42.1 \
		windows_i686_gnu-0.42.1 \
		windows_i686_msvc-0.42.1 \
		windows_x86_64_gnu-0.42.1 \
		windows_x86_64_gnullvm-0.42.1 \
		windows_x86_64_msvc-0.42.1

CARGO_CARGOLOCK=	${WRKSRC}/rust/Cargo.lock
CARGO_CARGOTOML=	${WRKSRC}/rust/Cargo.toml
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TEST=		no

MAKE_ENV=	${CARGO_ENV:NCARGO_TARGET_DIR=*}
LDFLAGS+=	-Wl,--as-needed

CMAKE_OFF=	LOCAL_LUA_LIB \
		LOCAL_MAGICENUM_LIB \
		LOCAL_MINIAUDIO_LIB \
		LOCAL_SOL_LIB \
		LOCAL_STRING_THEORY_LIB \
		WITH_UNITTESTS

CMAKE_ARGS=	-DEXTRA_DATA_DIR:PATH="${DATADIR}" \
		-DMAGICENUM_INCLUDE_DIR="${PREFIX}/include/magic_enum" \
		-DMINIAUDIO_INCLUDE_DIR="${PREFIX}/include/miniaudio"

post-patch:
	@${REINPLACE_CMD} -e 's|/some/place/where/the/data/is|${DATADIR}|' \
		${WRKSRC}/rust/stracciatella/src/config/ja2_json.rs \
		${WRKSRC}/rust/stracciatella/src/config/engine_options.rs

.include <bsd.port.mk>
