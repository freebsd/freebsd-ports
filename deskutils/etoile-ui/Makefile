# New ports collection makefile for:    etoile-ui
# Date created:         22 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	ui
PORTVERSION=	0.4.1
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project EtoileUI framework

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_GNUSTEP_LOCAL_LIBS+=	EtoileFoundation:${FOUNDATION_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	CoreObject:${COREOBJECT_PORT}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/EtoileUI

FOUNDATION_PORT?=	devel/etoile-foundation
COREOBJECT_PORT?=	devel/etoile-coreobject

.include <bsd.port.mk>
