# Also update devel/libgit2, devel/libgit2-glib, devel/py-pygit2

PORTNAME=	rugged
PORTVERSION=	1.5.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

# libgit2 1.5 added more spaces in version definition, fetch the required patch
PATCH_SITES=	https://github.com/libgit2/rugged/commit/
PATCHFILES=	9f9bce7e3346dfcf2a4256561e37ba8c888a16b6.diff:-p1

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby bindings to the libgit2 library
WWW=		https://github.com/libgit2/rugged

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libgit2>=${PORTVERSION:R}:devel/libgit2
LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libgmp.so:math/gmp

CONFIGURE_ARGS=	--use-system-libraries
USES=		gem pkgconfig
USE_RUBY=	yes

.include <bsd.port.mk>
