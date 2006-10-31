# New ports collection makefile for:	steptalk
# Date created:         29 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	steptalk
PORTVERSION=	0.10.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	libs
DISTNAME=	StepTalk-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	The official GNUstep scripting framework

WRKSRC=		${WRKDIR}/StepTalk
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=
LDCONFIG_DIRS=	${LOCALLIBDIR}
INSTALLS_SHLIB=	yes
#NO_FILTER_SHLIBS=	yes

.include <bsd.port.mk>
