# $FreeBSD$

PORTNAME=	leela-zero
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17
PORTREVISION=	8
CATEGORIES=	games

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Go engine without human-provided knowledge based on AlphaGo Zero paper

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	opencl>0:devel/opencl
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libopenblas.so:math/openblas \
		libOpenCL.so:devel/ocl-icd

USES=		cmake compiler:c++14-lang eigen:3 localbase qt:5
USE_GITHUB=	yes
GH_TUPLE=	google:googletest:cafa9e5:gtest/gtest
USE_QT=		core widgets buildtools_build qmake_build

CMAKE_ON=	USE_BLAS BUILD_TESTING
CMAKE_ARGS=	-DBLAS_INCLUDE_DIRS:STRING=${LOCALBASE}/include

PLIST_FILES=	bin/autogtp \
		bin/leelaz \
		bin/validation

do-test:
	@cd ${WRKSRC} && ${MKDIR} .build && ${CP} ../.build/tests .build && cd .build && ./tests

.include <bsd.port.mk>
