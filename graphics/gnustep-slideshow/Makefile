# New ports collection makefile for:    preview
# Date created:         16 Feb 2004
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	slideshow
PORTVERSION=	0.3
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/gsimageapps/
PKGNAMEPREFIX=	gnustep-
DISTNAME=	SlideShow-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	SlideShow Viewer

BUILD_DEPENDS+=	${LOCALLIBDIR}/libSlideShow.so:${PORTSDIR}/${SLIDESHOWKIT_PORT}
RUN_DEPENDS+=	${LOCALLIBDIR}/libSlideShow.so:${PORTSDIR}/${SLIDESHOWKIT_PORT}

USE_BZIP2=	yes
PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=

SLIDESHOWKIT_PORT?=	graphics/gnustep-slideshowkit

.include <bsd.port.mk>
