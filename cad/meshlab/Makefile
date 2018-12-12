# Created by: gahr
# $FreeBSD$

PORTNAME=	meshlab
PORTVERSION=	1.3.3
PORTREVISION=	10
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/MeshLab%20v${PORTVERSION}/
DISTNAME=	MeshLabSrc_AllInc_v${PORTVERSION:C|\.||g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D triangular meshes processing and editing tool

LICENSE=	GPLv2

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BROKEN_aarch64=		fails to compile: constant expression evaluates to -1 which cannot be narrowed to type char
BROKEN_armv6=		fails to compile: constant expression evaluates to -1 which cannot be narrowed to type char
BROKEN_armv7=		fails to compile: constant expression evaluates to -1 which cannot be narrowed to type char
BROKEN_powerpc64=	fails to compile: mc_lookup_table.h:316:5: narrowing conversion of '-1' from 'int' to 'char' inside { }

EXTRACT_DEPENDS=gtar:archivers/gtar
LIB_DEPENDS=	libQtSolutions_SOAP-head.so:devel/qt4-qtsolutions-soap	\
		libmpir.so:math/mpir

USES=		compiler:c++11-lib dos2unix qmake qt:4 tar:tgz
USE_CXXSTD=	c++11
USE_GL=		glew glu
USE_QT=		moc_build rcc_build uic_build corelib gui xml \
		xmlpatterns opengl network script
USE_LDCONFIG=	yes
DOS2UNIX_FILES=	external/structuresynth/ssynth/SyntopiaCore/GLEngine/Object3D.h \
		external/structuresynth/ssynth/SyntopiaCore/GLEngine/Raytracer/VoxelStepper.cpp \
		meshlabplugins/edit_arc3D/fillImage.cpp \
		meshlabplugins/filter_csg/intercept.h \
		meshlabplugins/filter_photosynth/downloader.cpp

EXTRACT_CMD=	gtar
QMAKE_SOURCE_PATH=	${WRKSRC}/meshlab_full.pro
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

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/meshlab/plugins
	cd ${WRKSRC}/distrib/plugins && ${INSTALL_LIB} *.so ${STAGEDIR}${PREFIX}/lib/meshlab/plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/meshlab/shaders
	cd ${WRKSRC}/distrib/shaders && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/meshlab/shaders
	${INSTALL_PROGRAM} ${WRKSRC}/distrib/meshlab ${STAGEDIR}${PREFIX}/lib/meshlab
	${LN} -sf ../lib/meshlab/meshlab ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
