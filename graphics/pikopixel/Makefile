PORTNAME=	pikopixel
DISTVERSION=	1.0-b10
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://twilightedge.com/downloads/
DISTNAME=	PikoPixel.Sources.${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application for drawing and editing pixel-art images
WWW=		https://twilightedge.com/mac/pikopixel/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE_agpl-3.0.txt

USES=		gnustep
WRKSRC_SUBDIR=	PikoPixel
USE_GNUSTEP=	base build gui

post-install:
	@${STRIP_CMD} ${STAGEDIR}${GNUSTEP_SYSTEM_ROOT}/Applications/PikoPixel.app/PikoPixel

.include <bsd.port.mk>
