# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	openshadinglanguage
PORTVERSION=	1.6.6
DISTVERSIONPREFIX=	Release-
CATEGORIES=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Advanced shading language for production GI renderers

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	llvm-config34:${PORTSDIR}/devel/llvm34 \
		clang34>=3.4_1:${PORTSDIR}/lang/clang34
LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libOpenImageIO.so:${PORTSDIR}/graphics/openimageio
RUN_DEPENDS=	llvm-config34:${PORTSDIR}/devel/llvm34

BROKEN_FreeBSD_9=	does not build

USE_GITHUB=	yes
GH_ACCOUNT=	imageworks
GH_PROJECT=	OpenShadingLanguage

CMAKE_ARGS=	-DLLVM_CONFIG:STRING="${LOCALBASE}/bin/llvm-config34"
USE_LDCONFIG=	yes
USES=		bison cmake:outsource

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=2.5.37:${PORTSDIR}/textproc/flex
CMAKE_ARGS+=	-DFLEX_EXECUTABLE:STRING=${LOCALBASE}/bin/flex
CXXFLAGS+=	-I${LOCALBASE}/include/flex
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,' \
		${WRKSRC}/src/liboslexec/serialize-bc.bash

.include <bsd.port.mk>
