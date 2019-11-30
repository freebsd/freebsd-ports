# $FreeBSD$

PORTNAME=	dmlc-core
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-105
DISTVERSIONSUFFIX=	-g32d9fe7
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Common library for scalable and portable distributed machine learning

LICENSE=	APACHE20

BUILD_DEPENDS=	llvm80>0:devel/llvm80

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	dmlc
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS

# use clang from ports because otherwise OpenMP isn't detected on some systems (ex. 12.0-RELEASE-p9)
CPP=		clang-cpp80
CC=		clang80
CXX=		clang++80

.include <bsd.port.mk>
