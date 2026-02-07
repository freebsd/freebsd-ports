PORTNAME=	argyllcms
PORTVERSION=	1.9.2
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	https://www.argyllcms.com/
DISTNAME=	Argyll_V${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ICC compatible color management system
WWW=		https://www.argyllcms.com/

LICENSE=	AGPLv3

BUILD_DEPENDS=	jam:devel/jam
LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png

WRKSRC=		${WRKDIR}/Argyll_V${PORTVERSION}

USES=		compiler:c11 cpe jpeg ssl xorg zip
USE_XORG=	x11 xau xdmcp xext xinerama xrandr xscrnsaver xxf86vm

do-build:
	@cd ${WRKSRC} && ${MAKE_ENV} jam -dx -q -fJambase -j${MAKE_JOBS_NUMBER}

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} ${MAKE_ENV} \
		REFSUBDIR=share/argyll/ref \
		jam -dx -q -fJambase -j${MAKE_JOBS_NUMBER} install
	${MV} ${STAGEDIR}${PREFIX}/bin/License.txt \
		${STAGEDIR}${PREFIX}/share/argyll/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
