# New ports collection makefile for:    jishyo
# Date created:         30 Oct 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	jishyo
PORTVERSION=	0.1
CATEGORIES=	japanese
MASTER_SITES=	http://www.eskimo.com/~pburns/Dictionaries/files/ \
		http://florida.ethz.ch/ports/distfiles/
DISTNAME=	Jishyo-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	English to Japanese dictionary for GNUstep

WRKSRC=	${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
