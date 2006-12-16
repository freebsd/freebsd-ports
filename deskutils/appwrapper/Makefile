# New ports collection makefile for:    appwrapper
# Date created:         16 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	appwrapper
PORTVERSION=	0.1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	AppWrapper.${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep application wrapper

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
#USE_GNUSTEP_LDCONFIG=	${LOCALLIBDIR}
#USE_GNUSTEP_LOCAL_LIBS+=	XWindowServerKit:${XWINDOWSERVERKIT_PORT}

WRKSRC=		${WRKDIR}/AppWrapper
#USE_GNUSTEP_MAKE_DIRS+=	Services/Private/AZDock
#ADDITIONAL_OBJCFLAGS+=	-I${X11BASE}/include
#ADDITIONAL_LDFLAGS+=	-L${X11BASE}/lib

#XWINDOWSERVERKIT_PORT?=	x11/etoile-xwindowserverkit

.include <bsd.port.mk>
