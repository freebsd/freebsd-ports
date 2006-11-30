# New ports collection makefile for:    etoile-menuserver
# Date created:         19 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	menuserver
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	deskutils
MASTER_SITES=	http://io.debian.net/~tar/ports/distfiles/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile_0+${SNAPSHOT}+dfsg.orig

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project MenuServer application

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	XWindowServerKit:${XWINDOWSERVERKIT_PORT}

SNAPSHOT=	20060917
WRKSRC=	${WRKDIR}/etoile-0+${SNAPSHOT}+dfsg/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Services/Private/MenuServer
ADDITIONAL_OBJCFLAGS+=	-I${X11BASE}/include
ADDITIONAL_LDFLAGS+=	-L${X11BASE}/lib

XWINDOWSERVERKIT_PORT?=		x11/etoile-xwindowserverkit

.include <bsd.port.mk>
