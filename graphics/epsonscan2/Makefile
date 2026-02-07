PORTNAME=	epsonscan2
DISTVERSION=	6.7.70.0
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://download3.ebz.epson.net/dsc/f/03/00/16/14/37/7577ee65efdad48ee2d2f38d9eda75418e490552/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.src

MAINTAINER=	fbsd@opal.com
COMMENT=	Epson Scan 2 scanner driver
WWW=		https://download.ebz.epson.net/man/linux/epsonscan2_e.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	sane-config:graphics/sane-backends
LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake jpeg localbase qt:5 xorg
USE_LDCONFIG=	${PREFIX}/lib/epsonscan2
USE_QT=		buildtools:build core gui qmake:build widgets
USE_XORG=	x11 xau xcb xdmcp

EPSON_VERSION=	1.0.0.0

CONFIGURE_ENV+=	STAGEDIR=${STAGEDIR}

CFLAGS+=	-I${PREFIX}/include

SUB_FILES=	pkg-message \
		Read_me.FreeBSD

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-1

OPTIONS_DEFINE=		AVAHI
OPTIONS_DEFAULT=	AVAHI
AVAHI_DESC=		Use avahi to find scanners
AVAHI_RUN_DEPENDS=	avahi-browse:net/avahi-app

pre-configure:
		${RM} ${WRKSRC}/CMakeCache.txt

post-install:
		${RM} -rf ${STAGEDIR}${DOCSDIR}
		${MV} ${STAGEDIR}${DOCSDIR}-${EPSON_VERSION}-1 ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKDIR}/Read_me.FreeBSD ${STAGEDIR}${PREFIX}/lib/epsonscan2

.include <bsd.port.mk>
