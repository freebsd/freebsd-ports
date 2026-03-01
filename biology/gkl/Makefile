PORTNAME=	gkl
DISTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Accelerated kernel library for genomics
WWW=		https://github.com/Intel-HLS/GKL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	/usr/lib/clang/19/include/ia32intrin.h:312:10: error: use of undeclared identifier '__builtin_ia32_readeflags_u32'

BUILD_DEPENDS=	gmake:devel/gmake
LIB_DEPENDS=	libisal.so:devel/isa-l

USES=		cmake:noninja java localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Intel-HLS
GH_PROJECT=	GKL
JAVA_VERSION=	8 11

BINARY_ALIAS=	make=${GMAKE}

.include <bsd.port.mk>
