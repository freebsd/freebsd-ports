# Created by: chinsan <chinsan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bcompiler
PORTVERSION=	1.0.2
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bytecode compiler extension

LICENSE=	PHP202

USES=		tar:tgz
USE_PHP=	bz2
USE_PHPEXT=	yes
DEFAULT_VERSIONS+=	php=53
IGNORE_WITH_PHP=5

CONFIGURE_ARGS=	--enable-bcompiler

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/${PHP_MODNAME}.so

.include <bsd.port.mk>
