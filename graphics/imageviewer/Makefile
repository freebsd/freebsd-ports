# $FreeBSD$

PORTNAME=	imageviewer
PORTVERSION=	0.6.3
PORTREVISION=	5
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.nice.ch/~phip/ \
		LOCAL/dinoex

DISTNAME=	ImageViewer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep Image Viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/ImageViewer.app/ImageViewer

.include <bsd.port.mk>
