PORTNAME=	arcanist
DISTVERSION=	20230530
CATEGORIES=	devel
PKGNAMEPREFIX=	php80-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Phabricator Arcanist libraries (php80)
WWW=		https://secure.phabricator.com/book/arcanist/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !defined(WITH_CLUSTER_ALLOW_TECHNICAL_DEBTS)
IGNORE=		PHP 8.0 is EOL; set WITH_CLUSTER_ALLOW_TECHNICAL_DEBTS=yes in make.conf to build it
.endif

RUN_DEPENDS=	${LOCALBASE}/include/php/main/php.h:lang/php80-legacy

USES=		python:env shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	phacility
GH_TAGNAME=	e50d1bc

SHEBANG_FILES=	bin/arc bin/phage scripts/*.php scripts/hgdaemon/*.php \
		src/parser/*.php support/arcanoid/arcanoid.py support/lib/*.php \
		support/unit/*.php support/xhpast/*.php \
		support/xhpast/bin/*.php

CONFLICTS=	arc arcanist-php??

NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	ignore:1

PHP_DESTDIR=	lib/php/arcanist

do-install:
	${RLN} ../${PHP_DESTDIR}/bin/arc ${STAGEDIR}${PREFIX}/bin/arc
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	${FIND} ${WRKSRC} -type f \( -name \*.orig -o -name \*.bak \) -delete
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g; \
		 s|%%PHP_DESTDIR%%|${PHP_DESTDIR}|g' \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/support/shell/hooks/bash-completion.sh
	@${REINPLACE_CMD} 's|%%PKGNAME%%|${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}|g; \
		 s|%%PKGVERSION%%|${PKGVERSION}|g; \
		 s|%%PKGORIGIN%%|${PKGORIGIN}|g' \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/toolset/workflow/ArcanistVersionWorkflow.php
	@${REINPLACE_CMD} 's|%%PHP_CMD%%|${PREFIX}/bin/php|g' \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/lint/linter/ArcanistPhpLinter.php \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/moduleutils/PhutilLibraryMapBuilder.php \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/phage/bootloader/PhagePHPAgentBootloader.php \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/runtime/ArcanistRuntime.php \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/utils/PhutilExecutionEnvironment.php \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/workflow/ArcanistLiberateWorkflow.php
	@${REINPLACE_CMD} 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
		${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/src/workflow/ArcanistAnoidWorkflow.php
	${RM} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}/resources/ssl/default.pem

.include <bsd.port.mk>
