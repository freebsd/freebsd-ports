# $FreeBSD$

PORTNAME=	imageviewer
PORTVERSION=	0.6.3
PORTREVISION=	8
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.nice.ch/~phip/ \
		LOCAL/dinoex

DISTNAME=	ImageViewer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep Image Viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ImageViewer.app/ImageViewer

.include <bsd.port.mk>
