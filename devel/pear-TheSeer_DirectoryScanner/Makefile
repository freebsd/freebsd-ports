# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	DirectoryScanner
PORTVERSION=	1.3.2
CATEGORIES=	devel pear
PKGNAMEPREFIX=	pear-TheSeer_

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Recursive directory scanner and filter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pear-channel-theseer>=20120501:devel/pear-channel-theseer
RUN_DEPENDS=	pear-channel-theseer>=20120501:devel/pear-channel-theseer

USE_GITHUB=	yes
GH_ACCOUNT=	theseer
GH_PROJECT=	DirectoryScanner

USE_PHP=	fileinfo
PEAR_CHANNEL=	theseer

NO_BUILD=	yes

PHP_DIR=	share/PHP

PLIST_FILES=	${PHP_DIR}/${PORTNAME}/directoryscanner.php

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/src/directoryscanner.php \
		${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}

.include <bsd.port.mk>
