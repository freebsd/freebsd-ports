PORTNAME=	rkcommon
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.2
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel RenderKit common C++/CMake infrastructure
WWW=		https://github.com/ospray/rkcommon

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_armv6=	error: use of undeclared identifier '__builtin_ia32_emms'; did you mean '__builtin_isless'

LIB_DEPENDS=	libtbb.so:devel/onetbb

USES=		cmake:testing compiler:c++11-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ospray

CMAKE_OFF=	BUILD_TESTING
CXXFLAGS_i386=	-msse2 # workaround for error: '_mm_setcsr' needs target feature sse
CMAKE_TESTING_ON=	BUILD_TESTING

PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${ARCH} != aarch64 && ${ARCH} != amd64 && !${ARCH:Marmv?} && ${ARCH} != i386
CMAKE_ARGS+=	-DRKCOMMON_NO_SIMD:BOOL=ON
.endif

.include <bsd.port.mk>
