# New ports collection makefile for:    objectivelib
# Date created:         1 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	objectivelib
PORTVERSION=	0.10
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ObjectiveLib-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Object containers and generic algorithms for Objective-C

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=   ${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}

.include <bsd.port.mk>
