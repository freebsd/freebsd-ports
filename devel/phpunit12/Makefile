PORTNAME=	phpunit
PORTVERSION=	12.4.4
CATEGORIES=	devel www
MASTER_SITES=	https://phar.phpunit.de/
PKGNAMESUFFIX=	12${PHP_PKGNAMESUFFIX}
EXTRACT_SUFX=	.phar

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Testing framework for unit tests
WWW=		https://phpunit.de/ \
		https://github.com/sebastianbergmann/phpunit

LICENSE=	BSD3CLAUSE

USES=		cpe php:flavors
USE_PHP=	ctype dom mbstring phar tokenizer xml xmlwriter

IGNORE_WITH_PHP=81 82
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/phpunit

CONFLICTS_INSTALL=	phpunit*

CPE_VENDOR=	phpunit_project

do-extract:
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/phpunit

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/phpunit ${STAGEDIR}${PREFIX}/bin/phpunit

.include <bsd.port.mk>
