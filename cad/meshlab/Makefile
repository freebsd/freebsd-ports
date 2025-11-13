PORTNAME=	meshlab
DISTVERSIONPREFIX=	Meshlab-
DISTVERSION=	2020.05
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	3D triangular meshes processing and editing tool
WWW=		https://www.meshlab.net/

LICENSE=	GPLv2

BROKEN=		fails to build and can not be update to Qt6

BUILD_DEPENDS=	${LOCALBASE}/include/vcglib/img/img.h:devel/vcglib
LIB_DEPENDS=	libmpirxx.so:math/mpir

USES=		dos2unix gl qmake:outsource qt:5
DOS2UNIX_GLOB=	*.c *.cpp *.h
USE_CXXSTD=	c++11
USE_GITHUB=	yes
GH_ACCOUNT=	cnr-isti-vclab
USE_GL=		gl glu glew
USE_LDCONFIG=	yes
USE_QT=		buildtools:build core gui network \
		opengl script xml xmlpatterns widgets

QMAKE_SOURCE_PATH=	${WRKSRC}/src/meshlab.pro

.if !exists(/usr/include/omp.h)
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/src/general.pri

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/meshlab/plugins
	cd ${BUILD_WRKSRC}/distrib/plugins && ${INSTALL_LIB} *.so ${STAGEDIR}${PREFIX}/lib/meshlab/plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/meshlab/shaders
	cd ${WRKSRC}/distrib/shaders && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/meshlab/shaders
	${INSTALL_LIB} ${BUILD_WRKSRC}/distrib/lib/* ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/distrib/meshlab ${STAGEDIR}${PREFIX}/lib/meshlab
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/distrib/meshlabserver ${STAGEDIR}${PREFIX}/lib/meshlab
	${RLN} ${STAGEDIR}${PREFIX}/lib/meshlab/meshlab ${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${PREFIX}/lib/meshlab/meshlabserver ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
