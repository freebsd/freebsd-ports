# New ports collection makefile for:    systempreferences
# Date created:         29 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	systempreferences
PORTVERSION=	1.1.0
CATEGORIES=	deskutils gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=usr-apps
DISTNAME=	SystemPreferences-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	System Preferences application for GNUstep

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	PreferencePanes:${PREFERENCEPANES_PORT}

USE_GNUSTEP_MAKE_DIRS=	SystemPreferences Modules
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

PREFERENCEPANES_PORT?=	deskutils/preferencepanes

.include <bsd.port.mk>
