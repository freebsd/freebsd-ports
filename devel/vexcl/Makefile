# $FreeBSD$

PORTNAME=	vexcl
DISTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ vector expression template library for OpenCL/CUDA

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		opencl>0:devel/opencl \
		ocl-icd>0:devel/ocl-icd

USES=		cmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	ddemidov
NO_ARCH=	yes

.include <bsd.port.mk>
