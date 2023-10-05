PORTNAME=	epsonscan2
DISTVERSION=	6.6.40.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	https://support.epson.net/linux/src/scanner/epsonscan2/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.src

MAINTAINER=	fbsd@opal.com
COMMENT=	Epson Scan 2 scanner driver
WWW=		https://download.ebz.epson.net/man/linux/epsonscan2_e.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sane-config:graphics/sane-backends
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libfreetype.so:print/freetype2 \
		libglib-2.0.so:devel/glib20 \
		libGL.so:graphics/libglvnd \
		libgraphite2.so:graphics/graphite2 \
		libicuuc.so:devel/icu \
		libiconv.so:converters/libiconv \
		libintl.so:devel/gettext-runtime \
		libharfbuzz.so:print/harfbuzz \
		libpcre.so:devel/pcre \
		libpcre2-16.so:devel/pcre2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	avahi-browse:net/avahi-app

USES=		cmake gettext-runtime gnome jpeg localbase qt:5 xorg
USE_GNOME=	glib20
USE_LDCONFIG=	${PREFIX}/lib/epsonscan2
USE_QT=		buildtools:build core gui qmake:build widgets
USE_XORG=	x11 xau xcb xdmcp

EPSON_VERSION=	1.0.0.0

CONFIGURE_ENV+=	STAGEDIR=${STAGEDIR}

CFLAGS+=	-I${PREFIX}/include

SUB_FILES=	pkg-message \
		Read_me.FreeBSD

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-1

post-install:
		${RM} -rf ${STAGEDIR}${DOCSDIR}
		${MV} ${STAGEDIR}${DOCSDIR}-${EPSON_VERSION}-1 ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKDIR}/Read_me.FreeBSD ${STAGEDIR}${PREFIX}/lib/epsonscan2

.include <bsd.port.mk>
