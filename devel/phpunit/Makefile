# $FreeBSD$

PORTNAME=	phpunit
DISTVERSION=	5.7.27
CATEGORIES=	devel www
MASTER_SITES=	https://phar.phpunit.de/
EXTRACT_SUFX=	.phar
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Testing framework for unit tests

LICENSE=	BSD3CLAUSE

DEPRECATED=	No longer maintained upstream
EXPIRATION_DATE=	2018-02-02

CONFLICTS_INSTALL=	phpunit6

PORTSCOUT=	limit:^5\.7\.[0-9]*

USES=		cpe php:flavors
CPE_VENDOR=	phpunit_project
USE_PHP=	dom json spl pcre phar

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
