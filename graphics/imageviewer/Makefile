# New ports collection makefile for:    imageviewer
# Date created:         15 Mar 2003
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	imageviewer
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.nice.ch/~phip/ \
		${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	usr-apps
DISTNAME=	ImageViewer-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep Image Viewer

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/ImageViewer
GUN_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
