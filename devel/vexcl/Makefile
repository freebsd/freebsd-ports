PORTNAME=	vexcl
DISTVERSION=	1.4.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ vector expression template library for OpenCL/CUDA

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

HPP_DEPENDS=	boost-libs>0:devel/boost-libs \
		opencl>0:devel/opencl
BUILD_DEPENDS=	${HPP_DEPENDS} \
		ocl-icd>0:devel/ocl-icd # devel/ocl-icd is probably not needed
RUN_DEPENDS=	${HPP_DEPENDS}

USES=		cmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	ddemidov

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
