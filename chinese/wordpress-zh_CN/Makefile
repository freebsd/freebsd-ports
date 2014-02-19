# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	wordpress
PORTVERSION=	3.8.1
CATEGORIES=	chinese www
MASTER_SITES=	http://cn.wordpress.org/ \
		http://mirror.joehorn.idv.tw/wordpress/
PKGNAMESUFFIX=	-zh_CN
DISTNAME=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}

MAINTAINER=	joehorn@gmail.com
COMMENT=	State-of-the-art semantic personal publishing platform

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	curl gd mysql pcre tokenizer xml zip
NO_BUILD=	yes
WANT_PHP_WEB=	yes

PLIST=		${WRKDIR}/pkg-plist
WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}

PORTDOCS=	readme.html

OPTIONS_DEFINE=	DOCS

SUB_FILES+=	pkg-message
SUB_LISTS+=	WWWDIR=${WWWDIR}

pre-everything::
	@${ECHO_CMD} "If you want to upgrade, you must read upgrade document."
	@${ECHO_CMD} ""
	@sleep 1

pre-install:
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${WWWDIR:S|${PREFIX}/||}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${WWWDIR:S|${PREFIX}/||}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${WWWDIR:S|${PREFIX}/||} >> ${PLIST}
	if [ ! -f ${WRKSRC}/wp-config-sample.php ]; then ${CP} \
		${WRKSRC}/wp-config.php.sample ${WRKSRC}/wp-config.php; fi

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' >> ${TMPPLIST}
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/${i}
.endfor

.include <bsd.port.mk>
