# Created by: Takefu
# $FreeBSD$

PORTNAME=	wordpress
PORTVERSION=	3.7
CATEGORIES=	japanese www
MASTER_SITES=	http://ja.wordpress.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}-ja

MAINTAINER=	ports@FreeBSD.org
COMMENT=	State-of-the-art semantic personal publishing platform

LICENSE=	GPLv2

CONFLICTS_INSTALL=	wordpress-3.* de-wordpress-3.* ru-wordpress-3.*

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

NO_STAGE=	yes
.include <bsd.port.options.mk>

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

do-install:
	${INSTALL} -d -g ${WWWGRP} -m 755 -o ${WWWOWN} ${WWWDIR}/
	${CP} -R ${WRKSRC}/ ${WWWDIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
