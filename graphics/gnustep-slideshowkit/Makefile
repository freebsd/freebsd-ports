# New ports collection makefile for:    preview
# Date created:         16 Feb 2004
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	slideshowkit
PORTVERSION=	0.0.1
PORTREVISION=	20041011
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/gsimageapps/
PKGNAMEPREFIX=	gnustep-
DISTNAME=	SlideShowKit-${PORTREVISION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	SlideShow Framework

USE_BZIP2=	yes
PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/SlideShowKit
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
LDCONFIG_DIRS=	${LOCALLIBDIR}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
