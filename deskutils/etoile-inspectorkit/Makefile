# New ports collection makefile for:    etoile-inspectorkit
# Date created:         05 May 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	inspectorkit
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project InspectorKit framework

PORTSCOUT=	limit:^0\.2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}
USE_GNUSTEP_LOCAL_LIBS+=	PaneKit:${PANEKIT_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	IconKit:${ICONKIT_PORT}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/InspectorKit

PANEKIT_PORT?=	deskutils/etoile-panekit
ICONKIT_PORT?=	x11-themes/etoile-iconkit

.include <bsd.port.mk>
