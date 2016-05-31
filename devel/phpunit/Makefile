# Created by: Torsten Zühlsdorff (<ports@toco-domains.de>)
# $FreeBSD$

PORTNAME=	phpunit
PORTVERSION=	5.3.4
CATEGORIES=	devel www
MASTER_SITES=	https://phar.phpunit.de/ \
		http://ports.toco-domains.de/
EXTRACT_SUFX=	.phar

MAINTAINER=	ports@toco-domains.de
COMMENT=	Testing framework for unit tests

LICENSE=	BSD3CLAUSE

CONFLICTS=	pear-PHPUnit-[1234]*

USES=		cpe
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
