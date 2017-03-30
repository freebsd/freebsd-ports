# Created by: Jochen Neumeister (<joneum@bsdproject.de>)
# $FreeBSD$

PORTNAME=	phpunit
PORTVERSION=	6.0.11
CATEGORIES=	devel www
MASTER_SITES=	https://phar.phpunit.de/
EXTRACT_SUFX=	.phar

MAINTAINER=	joneum@bsdproject.de
COMMENT=	Testing framework for unit tests

LICENSE=	BSD3CLAUSE

USES=	cpe php
CPE_VENDOR=	phpunit_project
USE_PHP=	dom json spl pcre phar

PHP_VER=	70
IGNORE_WITH_PHP=	56

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/phpunit

# Download isn't compressed or aggregated, it's just the single file
do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
