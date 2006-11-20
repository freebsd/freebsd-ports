# New ports collection makefile for:    etoile
# Date created:         4 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	etoile
PORTVERSION=	0.1.${SNAPSHOT}
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://florida.ethz.ch/ports/distfiles/
DISTNAME=	etoile_0+${SNAPSHOT}+dfsg.orig

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Etoile Project software for GNUstep

SNAPSHOT=	20060917
WRKSRC=	${WRKDIR}/etoile-0+${SNAPSHOT}+dfsg/Etoile/
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
USE_GNUSTEP_MAKE_DIRS+=	Services/User/DictionaryReader

.include <bsd.port.mk>
