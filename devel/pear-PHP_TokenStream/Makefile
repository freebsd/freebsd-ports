# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	PHP_TokenStream
PORTVERSION=	1.4.11
CATEGORIES=	devel pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Wrapper around PHP tokenizer extension

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	php-token-stream

NO_BUILD=	yes

PHP_DIR=	share/PHP
PLIST_FILES=	${PHP_DIR}/${PORTNAME}/Token.php

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/src/Token.php \
	${STAGEDIR}${PREFIX}/${PHP_DIR}/${PORTNAME}

.include <bsd.port.mk>
