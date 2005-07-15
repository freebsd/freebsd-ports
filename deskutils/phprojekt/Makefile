# New ports collection makefile for:	deskutils/phprojekt
# Date created:				January 33th 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	phprojekt
PORTVERSION=	5.0
CATEGORIES=	deskutils www
MASTER_SITES=	http://www.phprojekt.com/download/
DISTNAME=	${PORTNAME}

MAINTAINER=	tux@pinguru.net
COMMENT=	An open source groupware suite

.if defined(WITH_APACHE2)
RUN_DEPENDS=	${LOCALBASE}/libexec/apache2/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.endif

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//g}

do-install:
	@${CP} -r ${WRKSRC} ${PREFIX}/www/${PORTNAME}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/${PORTNAME}

post-install:
	@${FIND} ${WRKSRC}/${file} -not -type d \
	  | ${SED} -ne 's,^${WRKSRC},www/${PORTNAME},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm www/${PORTNAME},p' >> ${TMPPLIST}

.include <bsd.port.mk>
