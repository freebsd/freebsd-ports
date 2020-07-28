# Created by: gahr
# $FreeBSD$

PORTNAME=	meshlab
DISTVERSIONPREFIX=	Meshlab-
DISTVERSION=	2020.05
CATEGORIES=	cad

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	3D triangular meshes processing and editing tool

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/vcglib/img/img.h:devel/vcglib
LIB_DEPENDS=	libmpirxx.so:math/mpir

USES=		compiler:c++11-lang dos2unix gl qmake:outsource qt:5
USE_GL=		gl glu glew
USE_QT=		buildtools_build core gui network \
		opengl script xml xmlpatterns widgets
USE_GITHUB=	yes
GH_ACCOUNT=	cnr-isti-vclab
USE_LDCONFIG=	yes

QMAKE_SOURCE_PATH=	${WRKSRC}/src/meshlab.pro

DOS2UNIX_GLOB=	*.c *.cpp *.h

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
