# New ports collection makefile for:	deskutils/phprojekt
# Date created:				January 33th 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	phprojekt
PORTVERSION=	5.0.1
CATEGORIES=	deskutils www
MASTER_SITES=	http://www.phprojekt.com/download/
DISTNAME=	${PORTNAME}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	An open source groupware suite

USE_PHP=	yes
DEFAULT_PHP_VER=4
BROKEN_WITH_PHP=5
WANT_PHP_MOD=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${CP} -r ${WRKSRC} ${PREFIX}/www/${PORTNAME}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/${PORTNAME}

post-install:
	@${FIND} ${WRKSRC}/${file} -not -type d \
	  | ${SED} -ne 's,^${WRKSRC},www/${PORTNAME},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm www/${PORTNAME},p' >> ${TMPPLIST}

.include <bsd.port.mk>
