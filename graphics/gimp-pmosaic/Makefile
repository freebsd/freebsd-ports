# New ports collection makefile for:	gimp-pmosaic
# Date created:		23 Feb 2004
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pmosaic
PORTVERSION=	1.08
CATEGORIES=	graphics
MASTER_SITES=	http://www.kirchgessner.net/pub/gimp-1.2/
PKGNAMEPREFIX=	gimp-
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Photo/Image Mosaic plugin for gimp

BUILD_DEPENDS=	gimp-config:${PORTSDIR}/graphics/gimp1
RUN_DEPENDS=	gimp:${PORTSDIR}/graphics/gimp1

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} -o pmosaic `gimp-config --cflags` \
		pmsc.c pmosaic.c `gimp-config --libs` -ljpeg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pmosaic \
		${PREFIX}/libexec/gimp/1.2/plug-ins/
	${INSTALL_DATA} ${WRKSRC}/de/gimp-pmosaic.mo \
		${PREFIX}/share/locale/de/LC_MESSAGES/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}/
.endif

.include <bsd.port.mk>
