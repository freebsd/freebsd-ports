# $FreeBSD$

PORTNAME=	libcelero
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	benchmarks

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ benchmark authoring library/framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/sys/sysinfo.h:devel/libsysinfo

USES=		cmake localbase:ldflags # compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	DigitalInBlue
GH_PROJECT=	Celero
USE_LDCONFIG=	yes

# workaround for breakage with clang-10: https://github.com/DigitalInBlue/Celero/issues/142
LLVM_VER=	80
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}

.include <bsd.port.mk>
