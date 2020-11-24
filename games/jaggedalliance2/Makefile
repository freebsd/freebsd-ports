# Created by: Christoph Mallon <christoph.mallon@gmx.de>
# $FreeBSD$

PORTNAME=	ja2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
PORTREVISION=	3
CATEGORIES=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of "Jagged Alliance 2" using SDL

LICENSE=		PD SFI-SCLA
LICENSE_COMB=		multi
LICENSE_NAME_SFI-SCLA=	Strategy First Inc. Source Code License Agreement
LICENSE_FILE_SFI-SCLA=	${WRKSRC}/SFI\ Source\ Code\ license\ agreement.txt
LICENSE_PERMS_SFI-SCLA=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell \
			auto-accept

# Ignore this if you feel adventurous
ONLY_FOR_ARCHS=		aarch64 amd64 arm armv6 armv7 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	Needs a little endian environment

BUILD_DEPENDS=	string_theory>=3.3:devel/string_theory
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		cargo cmake compiler:c++11-lang pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	ja2-stracciatella
GH_PROJECT=	ja2-stracciatella
USE_LDCONFIG=	yes
USE_SDL=	sdl2

CMAKE_ARGS=	-DEXTRA_DATA_DIR:PATH="${DATADIR}"
CMAKE_OFF=	LOCAL_STRING_THEORY_LIB WITH_UNITTESTS

CARGO_CRATES=	aho-corasick-0.7.10 \
		ansi_term-0.11.0 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		base64-0.11.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		block-buffer-0.7.3 \
		block-padding-0.1.5 \
		byte-tools-0.3.1 \
		byteorder-1.3.4 \
		caseless-0.2.1 \
		cbindgen-0.13.2 \
		cfg-if-0.1.10 \
		chrono-0.4.11 \
		clap-2.33.0 \
		constant_time_eq-0.1.5 \
		crossbeam-deque-0.7.3 \
		crossbeam-epoch-0.8.2 \
		crossbeam-queue-0.2.1 \
		crossbeam-utils-0.7.2 \
		digest-0.8.1 \
		dirs-1.0.5 \
		dunce-1.0.0 \
		either-1.5.3 \
		generic-array-0.12.3 \
		getopts-0.2.21 \
		getrandom-0.1.14 \
		hermit-abi-0.1.10 \
		hex-0.3.2 \
		indexmap-1.3.2 \
		itoa-0.4.5 \
		json_comments-0.2.0 \
		lazy_static-1.4.0 \
		libc-0.2.68 \
		log-0.4.8 \
		maybe-uninit-2.0.0 \
		md-5-0.8.0 \
		memchr-2.3.3 \
		memoffset-0.5.4 \
		num-integer-0.1.42 \
		num-traits-0.2.11 \
		num_cpus-1.12.0 \
		opaque-debug-0.2.3 \
		ppv-lite86-0.2.6 \
		proc-macro2-1.0.10 \
		quote-1.0.3 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rayon-1.3.0 \
		rayon-core-1.7.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.4 \
		regex-1.3.6 \
		regex-syntax-0.6.17 \
		remove_dir_all-0.5.2 \
		rust-argon2-0.7.0 \
		ryu-1.0.3 \
		scopeguard-1.1.0 \
		serde-1.0.105 \
		serde_derive-1.0.105 \
		serde_json-1.0.50 \
		simplelog-0.6.0 \
		smallvec-1.2.0 \
		strsim-0.8.0 \
		syn-1.0.17 \
		tempfile-3.1.0 \
		term-0.5.2 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.42 \
		toml-0.5.6 \
		typenum-1.11.2 \
		unicode-normalization-0.1.12 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0
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

.include <bsd.port.mk>
