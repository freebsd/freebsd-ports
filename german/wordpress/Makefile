# New ports collection makefile for:	wordpress
# Date created:		2006-06-03
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#			(based on wordpress by Elvis Chiang)
#
# $FreeBSD$
#

PORTNAME=	wordpress
PORTVERSION=	2.8.3
CATEGORIES=	german www
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	de-
DISTNAME=	wordpress_283-de

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A state-of-the-art semantic personal publishing platform

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	YES
USE_PHP=	mysql pcre xml gd tokenizer
NO_BUILD=	YES
WANT_PHP_WEB=	YES
WORDPRESS?=	www/wordpress
PLIST_SUB+=	WORDPRESS=${WORDPRESS}
PLIST=		${WRKDIR}/pkg-plist

PORTDOCS=	license.txt readme.html liesmich.html

pre-everything::
	@${ECHO_CMD} "If you want to upgrade, you must read upgrade document."
	@${ECHO_CMD} ""
	@sleep 1

pre-install:
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${WORDPRESS}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${WORDPRESS}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${WORDPRESS} >> ${PLIST}
	if [! -f ${WRKSRC}/wp-config-sample.php]; then ${CP} \
		${WRKSRC}/wp-config.php.sample ${WRKSRC}/wp-config.php; fi

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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
