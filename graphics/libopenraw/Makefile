PORTNAME=	libopenraw
PORTVERSION=	0.3.7
PORTREVISION=	18
CATEGORIES=	graphics
MASTER_SITES=	http://libopenraw.freedesktop.org/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library for camera RAW files decoding
WWW=		https://libopenraw.freedesktop.org/

LICENSE=		LGPL3+ MPL20
LICENSE_COMB=		multi
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSER
LICENSE_FILE_MPL20=	${WRKSRC}/MPL-2.0

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

CARGO_CRATES=	ahash-0.7.6 \
		aho-corasick-0.7.18 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		bitreader-0.3.2 \
		byteorder-1.2.2 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		env_logger-0.8.4 \
		fallible_collections-0.4.4 \
		getrandom-0.2.7 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.8 \
		humantime-2.1.0 \
		libc-0.2.126 \
		log-0.4.17 \
		memchr-2.5.0 \
		num-traits-0.2.15 \
		once_cell-1.12.0 \
		regex-1.5.6 \
		regex-syntax-0.6.26 \
		static_assertions-1.1.0 \
		termcolor-1.1.3 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_CARGOTOML=${WRKSRC}/lib/mp4/Cargo.toml
CARGO_CARGOLOCK=${WRKSRC}/lib/mp4/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

PLIST_SUB=	VER=${PORTVERSION:R}

OPTIONS_DEFINE=		GNOME TEST
OPTIONS_DEFAULT=	GNOME
OPTIONS_SUB=		yes

GNOME_CONFIGURE_ENABLE=	gnome
GNOME_USES=		gettext-runtime
GNOME_USE=		GNOME=glib20,gdkpixbuf

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
