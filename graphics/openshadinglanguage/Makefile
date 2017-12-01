# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	openshadinglanguage
PORTVERSION=	1.8.10
PORTREVISION=	4
DISTVERSIONPREFIX=	Release-
CATEGORIES=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Advanced shading language for production GI renderers

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	llvm-config40:devel/llvm40
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libIlmImf.so:graphics/OpenEXR \
		libImath.so:graphics/ilmbase \
		libOpenImageIO.so:graphics/openimageio
RUN_DEPENDS=	llvm-config40:devel/llvm40

USES=		bison cmake:outsource compiler:c++11-lang ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
GH_PROJECT=	OpenShadingLanguage

CMAKE_ARGS=	-DLLVM_CONFIG:STRING="${LOCALBASE}/bin/llvm-config40" \
		-DENABLERTTI:BOOL=OFF -DUSE_BOOST_WAVE:BOOL=OFF
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,' \
		${WRKSRC}/src/liboslexec/serialize-bc.bash

.include <bsd.port.mk>
