# New ports collection makefile for:	deskutils/phprojekt
# Date created:				January 33th 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	phprojekt
PORTVERSION=	6.0.5
CATEGORIES=	deskutils www
MASTER_SITES=	http://www.phprojekt.com/downloads/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source groupware suite

USE_PHP=	session imap mysql
WANT_PHP_WEB=	yes

NO_BUILD=	yes

do-install:
	@${CP} -r ${WRKSRC} ${PREFIX}/www/${PORTNAME}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/${PORTNAME}

post-install:
	@${FIND} ${WRKSRC}/${file} -not -type d \
	  | ${SED} -ne 's,^${WRKSRC},www/${PORTNAME},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm www/${PORTNAME},p' >> ${TMPPLIST}

.include <bsd.port.mk>
