# New ports collection makefile for:	wordpress-zh_CN
# Date created:		2010-03-01
# Whom:			Joe Horn <joehorn@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	wordpress
PORTVERSION=	2.9.2
CATEGORIES=	chinese www
MASTER_SITES=	http://cn.wordpress.org/
PKGNAMESUFFIX=	-zh_CN
DISTNAME=	wordpress-${PORTVERSION}-zh_CN

MAINTAINER=	joehorn@gmail.com
COMMENT=	A state-of-the-art semantic personal publishing platform

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	mysql pcre xml gd tokenizer
NO_BUILD=	YES
WANT_PHP_WEB=	YES

WORDPRESS=	www/wordpress-zh_CN
WWWDIR=		${PREFIX}/${WORDPRESS}

PLIST_SUB+=	WORDPRESS=${WORDPRESS}
PLIST=		${WRKDIR}/pkg-plist

PORTDOCS=	license.txt readme.html

SUB_FILES+=	pkg-message
SUB_LISTS+=	WWWDIR=${WWWDIR}

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
	if [ ! -f ${WRKSRC}/wp-config-sample.php ]; then ${CP} \
		${WRKSRC}/wp-config.php.sample ${WRKSRC}/wp-config.php; fi

do-install:
	@${MKDIR} ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' >> ${TMPPLIST}
	${CP} -R ${WRKSRC}/ ${WWWDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
