# Created by: miwi
# $FreeBSD$

PORTNAME=	wordpress
PORTVERSION=	3.8.1
CATEGORIES=	german www
MASTER_SITES=	http://de.wordpress.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}-de_DE

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	State-of-the-art semantic personal publishing platform

LICENSE=	GPLv2

CONFLICTS_INSTALL=	wordpress-3.* ja-wordpress-3.* ru-wordpress-3.*

NO_BUILD=	yes
USE_PHP=	curl gd mysql pcre tokenizer xml zip
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	pkg-message pkg-install
SUB_LIST=	CHGRP="${CHGRP}" CHOWN="${CHOWN}" CHMOD="${CHMOD}"\
		FIND="${FIND}" WWWGRP="${WWWGRP}" WWWOWN="${WWWOWN}"
PLIST=		${WRKDIR}/pkg-plist
PORTDOCS=	license.txt readme.html

OPTIONS_DEFINE=	DOCS

pre-everything::
	@${ECHO_CMD} "If you want to upgrade, you must read upgrade document."
	@${ECHO_CMD} ""
	@sleep 1

pre-install:
	cd ${WRKSRC}/ && \
		(${FIND} -s * -type f | ${SED} -e 's|^|%%WWWDIR%%/|'; \
		${FIND} -d . -type d | ${SED} -e 's|^\.|@dirrm %%WWWDIR%%|') > ${PLIST}
	if [ ! -f ${WRKSRC}/wp-config-sample.php ]; then ${CP} \
		${WRKSRC}/wp-config.php.sample ${WRKSRC}/wp-config.php; fi

.include <bsd.port.options.mk>

do-install:
	${INSTALL} -d -g ${WWWGRP} -m 755 -o ${WWWOWN} ${STAGEDIR}${WWWDIR}/
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
