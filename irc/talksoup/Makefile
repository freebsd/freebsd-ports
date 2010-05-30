# New ports collection makefile for:    talksoup
# Date created:         8 Sep 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	talksoup
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	irc gnustep
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}alpha
DISTNAME=	TalkSoup-${PORTVERSION}alpha

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	IRC client for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	netclasses:${NETCLASSES_PORT}
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/${DISTNAME}
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}
PLIST_SUB+=	APPVERSION=0.990

NETCLASSES_PORT?=	net/netclasses

.include <bsd.port.mk>
