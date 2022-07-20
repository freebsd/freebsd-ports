PORTNAME=	ja2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.1
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	timp87@gmail.com
COMMENT=	Port of "Jagged Alliance 2" using SDL

LICENSE=		PD SFI-SCLA
LICENSE_COMB=		multi
LICENSE_NAME_SFI-SCLA=	Strategy First Inc. Source Code License Agreement
LICENSE_FILE_SFI-SCLA=	${WRKSRC}/SFI\ Source\ Code\ license\ agreement.txt
LICENSE_PERMS_SFI-SCLA=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell \
			auto-accept

# Ignore this if you feel adventurous
ONLY_FOR_ARCHS=		aarch64 amd64 arm armv6 armv7 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	requires little endian environment

BUILD_DEPENDS=	string_theory>=3.1:devel/string_theory \
		rapidjson>=1.1.0:devel/rapidjson \
		sol2>=3.2.2:devel/sol2 \
		miniaudio>=0.10.36<0.11:audio/miniaudio
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		cargo cmake compiler:c++17-lang pkgconfig sdl xorg gl lua:53
USE_GITHUB=	yes
GH_ACCOUNT=	ja2-stracciatella
GH_PROJECT=	ja2-stracciatella
USE_SDL=	sdl2
USE_GL=		gl
USE_XORG=	ice sm x11 xext

CMAKE_ARGS=	-DEXTRA_DATA_DIR:PATH="${DATADIR}" -DMINIAUDIO_INCLUDE_DIR="${PREFIX}/include/miniaudio"
CMAKE_OFF=	LOCAL_STRING_THEORY_LIB WITH_UNITTESTS LOCAL_RAPIDJSON_LIB LOCAL_LUA_LIB LOCAL_SOL_LIB LOCAL_MINIAUDIO_LIB

CARGO_CRATES=	ahash-0.7.6 \
		aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		block-buffer-0.9.0 \
		byteorder-1.4.3 \
		caseless-0.2.1 \
		cbindgen-0.20.0 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.4 \
		crossbeam-channel-0.5.4 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-utils-0.8.8 \
		deunicode-0.4.3 \
		digest-0.9.0 \
		dirs-4.0.0 \
		dirs-sys-0.3.7 \
		dunce-1.0.2 \
		either-1.6.1 \
		fastrand-1.7.0 \
		generic-array-0.14.5 \
		getopts-0.2.21 \
		getrandom-0.2.6 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		indexmap-1.8.1 \
		instant-0.1.12 \
		itoa-1.0.1 \
		json_comments-0.2.1 \
		lazy_static-1.4.0 \
		libc-0.2.121 \
		linked-hash-map-0.5.4 \
		log-0.4.16 \
		lru-0.7.5 \
		md-5-0.9.1 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		once_cell-1.10.0 \
		opaque-debug-0.3.0 \
		proc-macro2-1.0.37 \
		quote-1.0.17 \
		rayon-1.5.1 \
		rayon-core-1.9.1 \
		redox_syscall-0.2.13 \
		redox_users-0.4.3 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		remove_dir_all-0.7.0 \
		ryu-1.0.9 \
		scopeguard-1.1.0 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		serde_yaml-0.8.23 \
		simplelog-0.10.2 \
		slug-0.1.4 \
		strsim-0.8.0 \
		syn-1.0.91 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		textwrap-0.11.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		time-0.1.43 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		toml-0.5.8 \
		typenum-1.15.0 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.5

CARGO_CARGOLOCK=	${WRKSRC}/rust/Cargo.lock
CARGO_CARGOTOML=	${WRKSRC}/rust/Cargo.toml
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TEST=		no

MAKE_ENV=	${CARGO_ENV:NCARGO_TARGET_DIR=*}
LDFLAGS+=	-Wl,--as-needed

post-patch:
	@${REINPLACE_CMD} -e 's|/some/place/where/the/data/is|${DATADIR}|' \
		${WRKSRC}/rust/stracciatella/src/stracciatella.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ja2 \
		${STAGEDIR}${PREFIX}/bin/ja2-launcher \
		${STAGEDIR}${PREFIX}/bin/ja2-resource-pack

.include <bsd.port.pre.mk>

# Compilation with clang's broken in 14-CURRENT
.if ${OSVERSION} >= 1400000
# See https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=236344
# Copy-pasted gcc-c++11-lib from Mk/Uses/compiler.mk
USE_GCC=	yes
CHOSEN_COMPILER_TYPE=	gcc
CXXFLAGS+=	-nostdinc++ -isystem /usr/include/c++/v1
LDFLAGS+=	-L${WRKDIR}
_USES_configure+=	200:gcc-libc++-configure
gcc-libc++-configure:
	@${LN} -fs /usr/lib/libc++.so ${WRKDIR}/libstdc++.so
.endif

.include <bsd.port.post.mk>
