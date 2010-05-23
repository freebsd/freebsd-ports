# New ports collection makefile for:    gorm
# Date created:         15 Mar 2002
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gorm
.if defined(WITH_GNUSTEP_DEVEL)
PORTVERSION=	1.2.12
.else
PORTVERSION=	1.2.10
.endif
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	dev-apps

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graphical Object Relationship Modeller

NO_PACKAGE=	GPL3
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

DEFAULT_LIBVERSION=	1.1.0
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

.include <bsd.port.mk>
