# Created by: theraven@FreeBSD.org
# $FreeBSD$

PORTNAME=	pikopixel
DISTVERSION=	1.0-b9e
PORTEPOCH=	1
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://twilightedge.com/downloads/
DISTNAME=	PikoPixel.Sources.${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application for drawing and editing pixel-art images

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE_agpl-3.0.txt

USES=		gnustep
WRKSRC_SUBDIR=	PikoPixel
USE_GNUSTEP=	base build gui

post-install:
	@${STRIP_CMD} ${STAGEDIR}${GNUSTEP_SYSTEM_ROOT}/Applications/PikoPixel.app/PikoPixel

.include <bsd.port.mk>
