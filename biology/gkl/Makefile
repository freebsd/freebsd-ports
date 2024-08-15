PORTNAME=	gkl
DISTVERSION=	0.8.11-9
DISTVERSIONSUFFIX=	-g25670d8
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Accelerated kernel library for genomics
WWW=		https://github.com/Intel-HLS/GKL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake
LIB_DEPENDS=	libisal.so:devel/isa-l

USES=		cmake:noninja localbase:ldflags
USE_JAVA=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Intel-HLS
GH_PROJECT=	GKL

BINARY_ALIAS=	make=${GMAKE}

.include <bsd.port.mk>
