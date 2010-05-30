# New ports collection makefile for:    gworkspace-clipbook
# Date created:         30 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gworkspace
PORTVERSION=	0.8.3
PORTREVISION=	2
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://io.debian.net/~tar/debian/gworkspace/
PKGNAMESUFFIX=	-clipbook${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	ClipBook for GNUstep workspace manager

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/GWorkspace-${PORTVERSION}/ClipBook
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

.include <bsd.port.mk>
