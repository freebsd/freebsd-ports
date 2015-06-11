# Created by: gahr
# $FreeBSD$

PORTNAME=	meshlab
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/MeshLab%20v${PORTVERSION}/
DISTNAME=	MeshLabSrc_AllInc_v${PORTVERSION:C|\.||g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D triangular meshes processing and editing tool

LICENSE=	GPLv2

EXTRACT_DEPENDS=gtar:${PORTSDIR}/archivers/gtar
LIB_DEPENDS=	libQtSolutions_SOAP-head.so:${PORTSDIR}/devel/qt4-qtsolutions-soap	\
		libmpir.so:${PORTSDIR}/math/mpir

USES=		dos2unix qmake compiler:c++11-lib tar:tgz
USE_CXXSTD=	c++11
USE_GL=		glew glu
USE_QT4=	moc_build rcc_build uic_build corelib gui xml \
		xmlpatterns opengl network script
USE_LDCONFIG=	yes
DOS2UNIX_FILES=	external/structuresynth/ssynth/SyntopiaCore/GLEngine/Object3D.h \
		external/structuresynth/ssynth/SyntopiaCore/GLEngine/Raytracer/VoxelStepper.cpp \
		meshlabplugins/edit_arc3D/fillImage.cpp \
		meshlabplugins/filter_csg/intercept.h

EXTRACT_CMD=	gtar
WRKSRC=		${WRKDIR}/${PORTNAME}/src

pre-configure:
	${MV} "${WRKSRC}/distrib/shaders/electronic microscope.gdp" \
	    ${WRKSRC}/distrib/shaders/electronic_microscope.gdp
	${MV} "${WRKSRC}/distrib/shaders/shadersrm/old/Depth of Field.rfx" \
	    ${WRKSRC}/distrib/shaders/shadersrm/old/Depth_of_Field.rfx
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
	   ${WRKSRC}/common/pluginmanager.cpp

.if defined(MAINTAINER_MODE)
	${FIND} ${WRKSRC}/../../ -name "*.pro" | ${XARGS} \
	    ${REINPLACE_CMD} -e '/^CONFIG +=/s|$$| debug|'
.endif

do-configure:
	cd ${WRKSRC}/external && ${QMAKE} ${QMAKE_ARGS} -recursive external.pro
	cd ${WRKSRC} && ${QMAKE} -spec ${QMAKESPEC} -recursive meshlab_full.pro

do-build:
	cd ${WRKSRC}/external && ${MAKE}
	cd ${WRKSRC} && ${MAKE}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/meshlab/plugins
	cd ${WRKSRC}/distrib/plugins && ${INSTALL_LIB} *.so ${STAGEDIR}${PREFIX}/lib/meshlab/plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/meshlab/shaders
	cd ${WRKSRC}/distrib/shaders && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/meshlab/shaders
	${INSTALL_PROGRAM} ${WRKSRC}/distrib/meshlab ${STAGEDIR}${PREFIX}/lib/meshlab
	${LN} -sf ${PREFIX}/lib/meshlab/meshlab ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
