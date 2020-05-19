# $FreeBSD$

PORTNAME?=	arcanist
PORTVERSION?=	20200514
PORTREVISION?=	1
CATEGORIES?=	devel
PKGNAMESUFFIX=	${SLAVE_PKGNAMESUFFIX}${PHP_PKGNAMESUFFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT?=	Libraries for the command line interface for Phabricator

SLAVEPORT?=	lib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PHP_DESTDIR=	lib/php/arcanist
USES=		php:flavors python:env shebangfix
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
GH_TAGNAME=	b76b9c4
PLIST=		${.CURDIR}/pkg-plist

.if ${SLAVEPORT} == lib
SLAVE_PKGNAMESUFFIX=	-${SLAVEPORT}

OPTIONS_DEFINE=	ENCODINGS
OPTIONS_DEFAULT=ENCODINGS
ENCODINGS_DESC=	Support for encodings other than utf-8
ENCODINGS_USE=	PHP=mbstring

.else # link only

RUN_DEPENDS=	arcanist-lib${PHP_PKGNAMESUFFIX}>0:devel/arcanist-lib@${PHP_FLAVOR}

NO_BUILD=	yes

CONFLICTS=	arc

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
	${RLN} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/support/shell/hooks/bash-completion.sh \
		 ${STAGEDIR}${PREFIX}/share/bash-completion/completions/arc
.endif

.include <bsd.port.mk>
