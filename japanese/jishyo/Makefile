# New ports collection makefile for:    jishyo
# Date created:         30 Oct 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	jishyo
PORTVERSION=	0.1
CATEGORIES=	japanese gnustep
MASTER_SITES=	http://www.eskimo.com/~pburns/Dictionaries/files/ \
		${MASTER_SITE_GNUSTEP_CH}
DISTNAME=	Jishyo-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	English to Japanese dictionary for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=	${WRKDIR}/${DISTNAME}

.include <bsd.port.mk>
