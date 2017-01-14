# Created by: Takefu
# $FreeBSD$

PORTNAME=	wordpress
PORTVERSION=	4.7.1
DISTVERSIONSUFFIX=	-ja
CATEGORIES=	japanese www
MASTER_SITES=	http://ja.wordpress.org/

MAINTAINER=	joneum@bsdproject.de
COMMENT=	State-of-the-art semantic personal publishing platform

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/license.txt

CONFLICTS_INSTALL=	wordpress-[0-9].* de-wordpress-[0-9].* ru-wordpress-[0-9].*

NO_ARCH=	yes
NO_BUILD=	yes
USES=		cpe php:web
USE_PHP=	curl gd mysqli pcre tokenizer xml zip zlib ftp
WRKSRC=		${WRKDIR}/${PORTNAME}

CPE_LANG=	ja
.if ${PORTVERSION:N*.*.*}
CPE_VERSION=	${PORTVERSION}.0
.endif

SUB_FILES=	pkg-message
PLIST=		${WRKDIR}/pkg-plist
PORTDOCS=	license.txt readme.html

OPTIONS_DEFINE=	DOCS

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
	${FIND} ${STAGEDIR}${WWWDIR}/ -type d -exec ${CHMOD} g+w {} \;

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
