# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	wordpress
PORTVERSION=	4.7
DISTVERSIONSUFFIX=	-zh_TW
CATEGORIES=	chinese www
MASTER_SITES=	http://tw.wordpress.org/
PKGNAMESUFFIX=	-zh_TW

MAINTAINER=	joneum@bsdproject.de
COMMENT=	State-of-the-art semantic personal publishing platform

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		php:web
USE_PHP=	curl gd mysqli pcre tokenizer xml zip ftp
NO_ARCH=	yes
NO_BUILD=	yes

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
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}/
	${FIND} ${STAGEDIR}${WWWDIR}/ -type d -exec ${CHMOD} g+w {} \;

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
