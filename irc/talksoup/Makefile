# New ports collection makefile for:    talksoup
# Date created:         8 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	talksoup
PORTVERSION=	1.0
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	TalkSoup-${PORTVERSION}alpha

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	IRC client for GNUstep

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	netclasses:${NETCLASSES_PORT}
# broken:
#USE_LDCONFIG=	yes
INSTALLS_SHLIB=	yes
MAKEFILE=	GNUmakefile
NETCLASSES_PORT?=	net/netclasses
PLIST_SUB+=	APPVERSION=0.990

.include <bsd.port.mk>
