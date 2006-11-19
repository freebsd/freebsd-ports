# New ports collection makefile for:    etoile-lookandbehavior
# Date created:         19 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	lookandbehavior
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	deskutils
MASTER_SITES=	http://florida.ethz.ch/ports/distfiles/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile_0+${SNAPSHOT}+dfsg.orig

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project LookAndBehavior application

SNAPSHOT=	20060917
WRKSRC=	${WRKDIR}/etoile-0+${SNAPSHOT}+dfsg/Etoile/
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
USE_GNUSTEP_SYSTEM_LIBS+=	PreferencesKit:${PREFERENCESKIT_PORT}
USE_GNUSTEP_MAKE_DIRS+=	Services/User/LookAndBehavior

PREFERENCESKIT_PORT?=	deskutils/etoile-preferenceskit

.include <bsd.port.mk>
