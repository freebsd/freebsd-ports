PORTNAME=	opensycl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4
CATEGORIES=	lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-backend implementation of SYCL for CPUs and GPUs
WWW=		https://github.com/OpenSYCL/OpenSYCL

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		cmake compiler:c++11-lang llvm:15 python shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	OpenSYCL
GH_PROJECT=	OpenSYCL

SHEBANG_FILES=	bin/syclcc-clang cmake/syclcc-launcher

.include <bsd.port.mk>
