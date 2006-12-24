# New ports collection makefile for:    etoile-dictionaryreader
# Date created:         4 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	dictionaryreader
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~%%SUBDIR%%/distfiles/
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	etoile-
DISTNAME=	Etoile-${SNAPSHOT}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Dict client for GNUstep

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

SNAPSHOT=	20061221
WRKSRC=	${WRKDIR}/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Services/User/DictionaryReader

.include <bsd.port.mk>
