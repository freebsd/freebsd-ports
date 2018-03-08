# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	Git
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	devel pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}SebastianBergmann_

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Simple wrapper for Git

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	pear:env
USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	git

NO_BUILD=	yes

PHP_DIR=	share/PHP

PLIST_FILES=	${PHP_DIR}/${PORTNAME}/Git.php

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/src/Git.php \
		${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}

.include <bsd.port.mk>
