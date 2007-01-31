# New ports collection makefile for:    talksoup
# Date created:         8 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	talksoup
PORTVERSION=	1.0
CATEGORIES=	irc gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	TalkSoup-${PORTVERSION}alpha

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	IRC client for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	netclasses:${NETCLASSES_PORT}
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_SUB+=	APPVERSION=0.990

NETCLASSES_PORT?=	net/netclasses

.include <bsd.port.mk>
