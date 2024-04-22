PORTNAME=	rar
PORTVERSION=	4.2.0
PORTREVISION=	2
CATEGORIES=	archivers pear

PATCH_SITES=	https://github.com/cataphract/php-rar/commit/
PATCHFILES=	ab26d285759e4c917879967b09976a44829ed570.diff:-p1

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	PECL extension to create and read RAR files
WWW=		https://pecl.php.net/package/rar

LICENSE=	PHP301

USES=		compiler:c11 php:build,pecl

CFLAGS+=	-Wno-error=incompatible-function-pointer-types

CONFIGURE_ARGS=	--enable-rar

.include <bsd.port.mk>
