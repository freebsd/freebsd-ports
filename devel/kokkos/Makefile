# $FreeBSD$

PORTNAME=	kokkos
DISTVERSION=	3.1.01
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ performance portability programming ecosystem

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes
SHEBANG_FILES=	bin/nvcc_wrapper

CMAKE_ON=	BUILD_SHARED_LIBS

post-install:
	@cd ${STAGEDIR}${PREFIX}/include/eti && ${RMDIR} Cuda HPX OpenMP ROCm Serial Threads

.include <bsd.port.mk>
