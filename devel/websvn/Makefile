PORTNAME=	websvn
PORTVERSION=	2.8.3
CATEGORIES=	devel www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	michael.osipov@siemens.com
COMMENT=	Online Subversion repository browser
WWW=		https://websvnphp.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	${LOCALBASE}/bin/svn:devel/subversion \
		${LOCALBASE}/bin/composer:devel/php-composer@${PHP_FLAVOR}

USES=		php:web,flavors cpe
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}php

USE_PHP=	iconv xml mbstring zlib dom

NO_ARCH=	yes
NO_BUILD=	yes

PEARDIR?=	${LOCALBASE}/share/pear

SUB_FILES=	pkg-message
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^// \$$config->setSvnConfigDir.+|$$config->setSvnConfigDir('"'"'${ETCDIR}/subversion'"'"')\;|' \
		-e 's|^// \$$config->setSvnCommandPath.+|$$config->setSvnCommandPath('"'"'${LOCALBASE}/bin'"'"')\;|' \
		-e 's|^// \$$config->setSvnAuthzCommandPath.+|$$config->setSvnAuthzCommandPath('"'"'${LOCALBASE}/bin'"'"')\;|' \
		-e 's|^// \$$config->useGeshi.+|$$config->useGeshi()\;|' \
		-e 's|^// \$$config->setLocale.+|$$config->setLocale('"'"'C.UTF-8'"'"')\;|' \
	${WRKSRC}/include/distconfig.php

do-install:
	@(cd ${WRKSRC} \
		&& ${RM} README.md changes.txt include/.gitignore)
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/subversion

.include <bsd.port.mk>
