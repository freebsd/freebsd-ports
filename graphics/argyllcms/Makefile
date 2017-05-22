# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	argyllcms
PORTVERSION=	1.9.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.argyllcms.com/
DISTNAME=	Argyll_V${PORTVERSION}_src

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	ICC compatible color management system

LICENSE=	AGPLv3

BUILD_DEPENDS=	jam:devel/jam
LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng16.so:graphics/png

WRKSRC=		${WRKDIR}/Argyll_V${PORTVERSION}

USES=		compiler:c11 cpe jpeg ssl zip
USE_XORG=	x11 xau xdmcp xext xinerama xrandr xscrnsaver xxf86vm

post-patch:
	@${REINPLACE_CMD} 's:711:755:g' ${WRKSRC}/Jambase

do-build:
	@cd ${WRKSRC} && ${MAKE_ENV} jam -q -fJambase -j${MAKE_JOBS_NUMBER}

do-install:
	@cd ${WRKSRC} && ${SETENV} DESTDIR=${STAGEDIR} PREFIX=${PREFIX} \
		REFSUBDIR=share/argyll/ref \
		jam -q -fJambase -j${MAKE_JOBS_NUMBER} install
	@${MV} ${STAGEDIR}${PREFIX}/bin/License.txt \
		${STAGEDIR}${PREFIX}/share/argyll/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
