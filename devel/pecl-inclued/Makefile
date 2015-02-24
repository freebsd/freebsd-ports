# Created by: chinsan
# $FreeBSD$

PORTNAME=	inclued
PORTVERSION=	0.1.3
PORTEPOCH=	1
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Inclued gives you a Clue for PHP inclusion check

LICENSE=	PHP301

USES=		tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_VERSIONS+=	php=53
IGNORE_WITH_PHP=	55 56

CONFIGURE_ARGS=	--enable-inclued

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so

.include <bsd.port.mk>
