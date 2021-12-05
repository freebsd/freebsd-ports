# Created by: Pav Lucistnik <pav@FreeBSD.org>

PORTNAME=	libopenraw
PORTVERSION=	0.3.0
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://libopenraw.freedesktop.org/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	https://gitlab.freedesktop.org/${PORTNAME}/${PORTNAME}/-/commit/
PATCHFILES=	6d447e3feb6d47f958c786eb8ab40b0a7a535818.patch:-p1 # Include <sys/endian.h>

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for camera RAW files decoding

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${LOCALBASE}/include/boost/variant.hpp:devel/boost-libs
TEST_DEPENDS=	curl:ftp/curl

USES=		cargo compiler:c++14-lang gnome jpeg libtool localbase pkgconfig \
		tar:bz2
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost=${LOCALBASE}/include \
		--disable-silent-rules
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CARGO_CRATES=	ahash-0.3.8 \
		aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		bitreader-0.3.2 \
		byteorder-1.3.4 \
		cbindgen-0.14.3 \
		cfg-if-0.1.10 \
		clap-2.33.3 \
		env_logger-0.7.1 \
		getrandom-0.1.15 \
		hashbrown-0.7.2 \
		heck-0.3.1 \
		hermit-abi-0.1.17 \
		humantime-1.3.0 \
		itoa-0.4.6 \
		lazy_static-1.4.0 \
		libc-0.2.81 \
		log-0.4.11 \
		memchr-2.3.4 \
		num-traits-0.2.14 \
		ppv-lite86-0.2.10 \
		proc-macro2-1.0.24 \
		quick-error-1.2.3 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		regex-1.4.2 \
		regex-syntax-0.6.21 \
		remove_dir_all-0.5.3 \
		ryu-1.0.5 \
		serde-1.0.118 \
		serde_derive-1.0.118 \
		serde_json-1.0.60 \
		static_assertions-1.1.0 \
		strsim-0.8.0 \
		syn-1.0.54 \
		tempfile-3.1.0 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		toml-0.5.7 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CARGOTOML=${WRKSRC}/lib/mp4/Cargo.toml
CARGO_CARGOLOCK=${WRKSRC}/lib/mp4/mp4parse_capi/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

PLIST_SUB=	VER=${PORTVERSION:R}

OPTIONS_DEFINE=		GNOME TEST
OPTIONS_DEFAULT=	GNOME
OPTIONS_SUB=		yes

GNOME_CONFIGURE_ENABLE=	gnome
GNOME_USES=		gettext-runtime
GNOME_USE=		GNOME=glib20,gdkpixbuf2

TEST_BUILD_DEPENDS=	curl:ftp/curl

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|\{libdir\}/pkgconfig|{prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/configure

post-patch-TEST-off:
	@${REINPLACE_CMD} -e 's|testsuite ||' ${WRKSRC}/Makefile.in

pre-configure:
	@${CARGO_CARGO_RUN} update \
		--manifest-path ${WRKSRC}/lib/mp4/mp4parse_capi/Cargo.toml \
		--verbose

.include <bsd.port.mk>
