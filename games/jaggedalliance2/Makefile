# Created by: Christoph Mallon <christoph.mallon@gmx.de>

PORTNAME=	ja2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
PORTREVISION=	6
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
		sol2>=3.2.2:devel/sol2
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		cargo cmake compiler:c++17-lang pkgconfig sdl xorg gl lua:53
USE_GITHUB=	yes
GH_ACCOUNT=	ja2-stracciatella
GH_PROJECT=	ja2-stracciatella
USE_SDL=	sdl2
USE_GL=		gl
USE_XORG=	ice sm x11 xext
GH_TUPLE=	mackron:miniaudio:634cdb028f340075ae8e8a1126620695688d2ac3:miniaudio

CMAKE_ARGS=	-DEXTRA_DATA_DIR:PATH="${DATADIR}"
CMAKE_OFF=	LOCAL_STRING_THEORY_LIB WITH_UNITTESTS LOCAL_RAPIDJSON_LIB LOCAL_LUA_LIB LOCAL_SOL_LIB LOCAL_MINIAUDIO_LIB

CARGO_CRATES=	aho-corasick-0.7.13 \
		ansi_term-0.11.0 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.12.3 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		byte-tools-0.3.1 \
		byteorder-1.3.4 \
		caseless-0.2.1 \
		cbindgen-0.13.2 \
		cfg-if-0.1.10 \
		chrono-0.4.15 \
		clap-2.33.3 \
		constant_time_eq-0.1.5 \
		crossbeam-channel-0.4.4 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-utils-0.7.2 \
		digest-0.8.1 \
		dirs-1.0.5 \
		dunce-1.0.1 \
		either-1.6.1 \
		generic-array-0.12.3 \
		getopts-0.2.21 \
		getrandom-0.1.15 \
		hashbrown-0.9.0 \
		hermit-abi-0.1.15 \
		hex-0.3.2 \
		indexmap-1.6.0 \
		itoa-0.4.6 \
		json_comments-0.2.0 \
		lazy_static-1.4.0 \
		libc-0.2.77 \
		log-0.4.11 \
		maybe-uninit-2.0.0 \
		md-5-0.8.0 \
		memchr-2.3.3 \
		memoffset-0.5.5 \
		num-integer-0.1.43 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		opaque-debug-0.2.3 \
		ppv-lite86-0.2.9 \
		proc-macro2-1.0.21 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rayon-1.4.0 \
		rayon-core-1.8.0 \
		redox_syscall-0.1.57 \
		redox_users-0.3.5 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		remove_dir_all-0.5.3 \
		rust-argon2-0.8.2 \
		ryu-1.0.5 \
		scopeguard-1.1.0 \
		serde-1.0.116 \
		serde_derive-1.0.116 \
		serde_json-1.0.57 \
		simplelog-0.6.0 \
		strsim-0.8.0 \
		syn-1.0.41 \
		tempfile-3.1.0 \
		term-0.5.2 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.44 \
		tinyvec-0.3.4 \
		toml-0.5.6 \
		typenum-1.12.0 \
		unicode-normalization-0.1.13 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

CARGO_CARGOLOCK=	${WRKSRC}/rust/Cargo.lock
CARGO_CARGOTOML=	${WRKSRC}/rust/Cargo.toml
CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TEST=		no

MAKE_ENV=	${CARGO_ENV:NCARGO_TARGET_DIR=*}
LDFLAGS+=	-Wl,--as-needed

pre-patch:
	@${REINPLACE_CMD} -e 's|https://github.com/mackron/miniaudio/archive/634cdb028f340075ae8e8a1126620695688d2ac3.zip|${DISTDIR}/mackron-miniaudio-634cdb028f340075ae8e8a1126620695688d2ac3_GH0.tar.gz|' \
		-e 's|b30045e95cec65bfe1d9fe3639f480a2|975a4d15815118a7ded8fbc7d3de68f6|' \
		${WRKSRC}/dependencies/lib-miniaudio/getter/CMakeLists.txt.in

post-patch:
	@${REINPLACE_CMD} -e 's|/some/place/where/the/data/is|${DATADIR}|' \
		${WRKSRC}/rust/stracciatella/src/stracciatella.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ja2 \
		${STAGEDIR}${PREFIX}/bin/ja2-launcher \
		${STAGEDIR}${PREFIX}/bin/ja2-resource-pack

.include <bsd.port.mk>
