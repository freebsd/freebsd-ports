PORTNAME?=	arcanist
PORTVERSION?=	20220518
CATEGORIES?=	devel
PKGNAMESUFFIX=	${SLAVE_PKGNAMESUFFIX}${PHP_PKGNAMESUFFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT?=	Libraries for the command line interface for Phabricator

SLAVEPORT?=	lib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PHP_DESTDIR=	lib/php/arcanist
USES=		php:cli,flavors python:env shebangfix
SHEBANG_FILES=	bin/arc \
		bin/phage \
		scripts/*.php \
		scripts/hgdaemon/*.php \
		src/parser/*.php \
		support/arcanoid/arcanoid.py \
		support/lib/*.php \
		support/unit/*.php \
		support/xhpast/*.php \
		support/xhpast/bin/*.php

USE_PHP=	curl dom hash json simplexml zlib
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes
PORTSCOUT=	ignore:1
GH_ACCOUNT=	phacility
GH_TAGNAME=	85c953e
PLIST=		${.CURDIR}/pkg-plist

.if ${SLAVEPORT} == lib
SLAVE_PKGNAMESUFFIX=	-${SLAVEPORT}

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

OPTIONS_DEFINE=	ENCODINGS
OPTIONS_DEFAULT=ENCODINGS
ENCODINGS_DESC=	Support for encodings other than utf-8
ENCODINGS_USE=	PHP=mbstring

.else # link only

RUN_DEPENDS=	arcanist-lib${PHP_PKGNAMESUFFIX}>0:devel/arcanist-lib@${PHP_FLAVOR}

CONFLICTS=	arc arcanist-php??

PLIST_FILES=	bin/arc

.endif

do-install:
.if ${SLAVEPORT} == bin
	${RLN} ../${PHP_DESTDIR}/bin/arc ${STAGEDIR}${PREFIX}/bin/arc
.else
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	@${REINPLACE_CMD} \
		's|%%PREFIX%%|${PREFIX}|g; \
		 s|%%PHP_DESTDIR%%|${PHP_DESTDIR}|g' \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/support/shell/hooks/bash-completion.sh
	@${REINPLACE_CMD} \
		's|%%PKGNAME%%|${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}|g; \
		 s|%%PKGVERSION%%|${PKGVERSION}|g; \
		 s|%%PKGORIGIN%%|${PKGORIGIN}|g' \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/toolset/workflow/ArcanistVersionWorkflow.php
	@${REINPLACE_CMD} \
		's|%%PHP_CMD%%|${PREFIX}/bin/php|g' \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/lint/linter/ArcanistPhpLinter.php \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/moduleutils/PhutilLibraryMapBuilder.php \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/phage/bootloader/PhagePHPAgentBootloader.php \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/runtime/ArcanistRuntime.php \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/utils/PhutilExecutionEnvironment.php \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/workflow/ArcanistLiberateWorkflow.php
	@${REINPLACE_CMD} \
		's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/workflow/ArcanistAnoidWorkflow.php
	${LN} -sf ${LOCALBASE}/share/certs/ca-root-nss.crt \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/resources/ssl/default.pem
	${RLN} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/support/shell/hooks/bash-completion.sh \
		 ${STAGEDIR}${PREFIX}/share/bash-completion/completions/arc
	${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/bin/arc shell-complete --generate
.endif

.include <bsd.port.mk>
