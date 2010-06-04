# New ports collection makefile for:    preview
# Date created:         16 Feb 2004
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	slideshow
PORTVERSION=	0.3.5
PORTREVISION=	2
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/
PKGNAMEPREFIX=	gnustep-
DISTNAME=	SlideShow-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	SlideShow Viewer

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	SlideShow:${SLIDESHOWKIT_PORT}

SLIDESHOWKIT_PORT?=	graphics/gnustep-slideshowkit

.include <bsd.port.mk>
