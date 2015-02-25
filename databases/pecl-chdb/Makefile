# Created by: Evan Sarmiento <esarmiento@wayfair.com>
# $FreeBSD$

PORTNAME=	chdb
PORTVERSION=	1.0.2
CATEGORIES=	databases
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CHDB extension

BUILD_DEPENDS=	${LOCALBASE}/lib/libcmph.so:${PORTSDIR}/devel/cmph
RUN_DEPENDS=	${LOCALBASE}/lib/libcmph.so:${PORTSDIR}/devel/cmph

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	chdb
IGNORE_WITH_PHP=5

CFLAGS+=	-L${LOCALBASE}/lib

USE_GITHUB=	yes
GH_ACCOUNT=	lcastelli
GH_COMMIT=	169f45d

CONFIGURE_ARGS=	--with-libcmph-dir=${LOCALBASE}/lib

.include <bsd.port.mk>
