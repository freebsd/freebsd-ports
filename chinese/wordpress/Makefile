# New ports collection makefile for:	wordpress
# Date created:		2007-05-11
# Whom:			Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	wordpress
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	chinese www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}-zh
PKGNAMEPREFIX=	zh-
DISTNAME=	${PORTNAME}_${PORTVERSION}_zh_CN

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A state-of-the-art semantic personal publishing platform

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	YES
USE_PHP=	mysql pcre xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES
WORDPRESS?=	www/wordpress
PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	license.txt readme.html

pre-everything::
	@${ECHO_CMD} "If you want to upgrade, you must read upgrade document."
	@${ECHO_CMD} ""
	@sleep 1

pre-install:
	if [ ! -f ${WRKSRC}/wp-config.php ]; then ${CP} \
		${WRKSRC}/wp-config-sample.php ${WRKSRC}/wp-config.php; fi

do-install:
	@${MKDIR} ${PREFIX}/${WORDPRESS}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${WORDPRESS}
	@${CHMOD} 755 ${PREFIX}/${WORDPRESS}
	${CP} -R ${WRKSRC}/ ${PREFIX}/${WORDPRESS}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif
	@${SED} "s|%%WORDPRESSDIR%%|${PREFIX}/${WORDPRESS}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
