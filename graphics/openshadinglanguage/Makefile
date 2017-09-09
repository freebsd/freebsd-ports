# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	openshadinglanguage
PORTVERSION=	1.7.5
DISTVERSIONPREFIX=	Release-
PORTREVISION=	3
CATEGORIES=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Advanced shading language for production GI renderers

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	llvm-config34:devel/llvm34 \
		clang34>=3.4_1:lang/clang34
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libIlmImf.so:graphics/OpenEXR \
		libImath.so:graphics/ilmbase \
		libOpenImageIO.so:graphics/openimageio
RUN_DEPENDS=	llvm-config34:devel/llvm34

USES=		bison cmake:outsource compiler:c++11-lib ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
GH_PROJECT=	OpenShadingLanguage

CMAKE_ARGS=	-DLLVM_CONFIG:STRING="${LOCALBASE}/bin/llvm-config34" \
		-DENABLERTTI:BOOL=ON
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,' \
		${WRKSRC}/src/liboslexec/serialize-bc.bash

.include <bsd.port.mk>
