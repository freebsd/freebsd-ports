# $FreeBSD$

PORTNAME=	opensubdiv
DISTVERSIONPREFIX=	v
DISTVERSION=	3_0_5
PORTREVISION=	4
CATEGORIES=	graphics devel

MAINTAINER=	mva@FreeBSD.org
COMMENT=	High performance subdivision surface libraries

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/GLFW/glfw3.h:graphics/glfw

USE_GITHUB=	yes
GH_ACCOUNT=	PixarAnimationStudios
GH_PROJECT=	OpenSubdiv

USE_LDCONFIG=	yes
USE_GL=		glew
USES=		cmake:outsource compiler pkgconfig
USE_XORG=	x11 xi xcursor xrandr xxf86vm xinerama

CMAKE_ARGS+=	-DNO_TUTORIALS:BOOL=ON -DNO_EXAMPLES:BOOL=ON \
		-DNO_REGRESSION:BOOL=ON -DNO_PTEX:BOOL=ON -DNO_CUDA:BOOL=ON \
		-DNO_OPENCL:BOOL=ON -DNO_MAYA:BOOL=ON -DNO_TBB:BOOL=ON

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE:Mgcc}
# OpenMP is available
PLIST_SUB+=	OPENMP=""
.else
PLIST_SUB+=	OPENMP="@comment "
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:devel/doxygen \
		python2:lang/python2 \
		rst2html:textproc/py-docutils
.else
CMAKE_ARGS+=	-DNO_DOC:BOOL=ON
.endif

.include <bsd.port.post.mk>
