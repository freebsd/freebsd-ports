PORTNAME=	websvn
PORTVERSION=	2.6.0
CATEGORIES=	devel www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	michael.osipov@siemens.com
COMMENT=	Online Subversion repository browser

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	${LOCALBASE}/bin/svn:devel/subversion \
		${PEARDIR}/Archive/Tar.php:devel/pear@${PHP_FLAVOR} \
		${PEARDIR}/geshi.php:devel/pear-geshi@${PHP_FLAVOR} \
		${PEARDIR}/Text/Diff.php:devel/pear-Text_Diff@${PHP_FLAVOR}

USES=		php:flavors cpe
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}php

USE_PHP=	iconv pcre xml mbstring

NO_BUILD=	yes
NO_ARCH=	yes

PEARDIR?=	${LOCALBASE}/share/pear

SUB_FILES=	pkg-message
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^// \$$config->setSvnConfigDir.+|$$config->setSvnConfigDir('"'"'${ETCDIR}/subversion'"'"')\;|' \
		-e 's|^// \$$config->setSVNCommandPath.+|$$config->setSVNCommandPath('"'"'${LOCALBASE}/bin'"'"')\;|' \
		-e 's|^// \$$config->useGeshi.+|$$config->useGeshi()\;|' \
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
