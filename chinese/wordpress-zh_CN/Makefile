# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	wordpress
PORTVERSION=	4.2.2
DISTVERSIONSUFFIX=	-zh_CN
CATEGORIES=	chinese www
MASTER_SITES=	http://cn.wordpress.org/ \
		http://mirror.joehorn.idv.tw/wordpress/
PKGNAMESUFFIX=	-zh_CN

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

SUB_FILES=	pkg-message

pre-everything::
	@${ECHO_CMD} "If you want to upgrade, you must read upgrade document."
	@${ECHO_CMD} ""
	@sleep 1

pre-install:
	${ECHO_CMD} '@owner www' > ${PLIST}
	${ECHO_CMD} '@group www' >> ${PLIST}
	cd ${WRKSRC}/ && ${FIND} -s * -type f | ${SED} -e 's|^|%%WWWDIR%%/|' >> ${PLIST}
	${ECHO_CMD} '@owner' >> ${PLIST}
	${ECHO_CMD} '@group' >> ${PLIST}
	if [ ! -f ${WRKSRC}/wp-config-sample.php ]; then ${CP} \
		${WRKSRC}/wp-config.php.sample ${WRKSRC}/wp-config.php; fi

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}${WWWDIR}/
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}/
	${FIND} ${STAGEDIR}${WWWDIR}/ -type d -exec ${CHMOD} g+w '{}' \;
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
