# $FreeBSD$

PORTNAME=	kokkos
DISTVERSION=	3.2.00
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ performance portability programming ecosystem

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386 # Kokkos assumes a 64-bit build; i.e., 8-byte pointers, but found 4-byte pointers instead

USES=		cmake compiler:c++11-lang shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes
SHEBANG_FILES=	bin/nvcc_wrapper

CMAKE_ON=	BUILD_SHARED_LIBS

.include <bsd.port.mk>
