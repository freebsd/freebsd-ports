# $FreeBSD$

PORTNAME=	dmlc-core
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-105
DISTVERSIONSUFFIX=	-g32d9fe7
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common library for scalable and portable distributed machine learning

LICENSE=	APACHE20

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

# use clang from ports because otherwise OpenMP isn't detected on some systems (ex. 12.0-RELEASE-p9)
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

.include <bsd.port.options.mk>

.if ${LLVM_DEFAULT:S,-devel,990,} >= 90
LLVM_DEFAULT=	80
.endif

.include <bsd.port.mk>
