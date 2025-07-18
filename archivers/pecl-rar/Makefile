PORTNAME=	rar
PORTVERSION=	4.2.0
PORTREVISION=	3
CATEGORIES=	archivers pear

# Temporary switch patches source to Remi Collet's repo
#PATCH_SITES=	https://github.com/cataphract/php-rar/commit/
PATCH_SITES=	https://github.com/remicollet/php-rar/commit/
PATCHFILES=	ab26d285759e4c917879967b09976a44829ed570.diff:-p1 \
		02331ca1cc1e8638c34e024566f4b391a6c863c5.diff:-p1 \
		eefdef210536834617bc57d3d38e4ab092481c6b.diff:-p1 \
		048aa2b35bfd1ec5dfae30d2f9c8d52fb8842784.diff:-p1

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	PECL extension to create and read RAR files
WWW=		https://pecl.php.net/package/rar

LICENSE=	PHP301

USES=		compiler:c11 php:build,pecl

CFLAGS+=	-Wno-error=incompatible-function-pointer-types

CONFIGURE_ARGS=	--enable-rar

.include <bsd.port.mk>
