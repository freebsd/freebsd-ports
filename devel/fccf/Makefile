PORTNAME=	fccf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line tool that quickly searches through C/C++
WWW=		https://github.com/p-ranav/fccf

LICENSE=	MIT

BUILD_DEPENDS=	argparse>0:devel/argparse
LIB_DEPENDS=	libfmt.so:devel/libfmt

USES=		cmake llvm:build,lib,run

USE_GITHUB=	yes
GH_ACCOUNT=	p-ranav

CMAKE_ARGS=	-DLLVM_DIR:STRING=${PREFIX}/llvm${LLVM_VERSION}/lib/cmake/llvm
CXXFLAGS+=	-I${LOCALBASE}/include/argparse

post-patch:
	${REINPLACE_CMD} "s/llvm-config/${LLVM_CONFIG}/g" ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
