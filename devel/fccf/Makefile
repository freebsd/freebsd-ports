PORTNAME=	fccf
PORTVERSION=	0.6.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line tool that quickly searches through C/C++
WWW=		https://github.com/p-ranav/fccf

LICENSE=	MIT

BUILD_DEPENDS=	argparse>0:devel/argparse \
		llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libfmt.so:devel/libfmt
RUN_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	p-ranav

CXXFLAGS+=	-I${LOCALBASE}/include/argparse

post-patch:
	${REINPLACE_CMD} "s/llvm-config/llvm-config${LLVM_DEFAULT}/g" ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
