# New ports collection makefile for:    etoile-volumecontrolmenulet
# Date created:         28 Nov 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	volumecontrolmenulet
PORTVERSION=	0.4.1
CATEGORIES=	audio gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project VolumeControlMenulet bundle

LICENSE=	BSD

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	SystemConfig:${SYSTEMCONFIG_PORT}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Bundles/VolumeControlMenulet

SYSTEMCONFIG_PORT?=	deskutils/etoile-systemconfig

.include <bsd.port.mk>
