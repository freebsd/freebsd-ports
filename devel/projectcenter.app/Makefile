# New ports collection makefile for:    ProjectCenter
# Date created:         22 Sep 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	projectcenter.app
PORTVERSION=	0.4.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	dev-apps
DISTNAME=	ProjectCenter-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A development environment for GNUstep

USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
PLIST_SUB+=	FRAMEVERSION=${PORTVERSION}

.include <bsd.port.mk>
