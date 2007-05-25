# New ports collection makefile for:	steptalk
# Date created:         29 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	steptalk
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	lang gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs
DISTNAME=	StepTalk-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	The official GNUstep scripting framework

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/StepTalk
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

.include <bsd.port.mk>
