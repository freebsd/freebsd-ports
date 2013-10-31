# Created by: gahr
# $FreeBSD$

PORTNAME=	meshlab
DISTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_LOCAL}/gahr/ \
		http://people.freebsd.org/~gahr/distfiles/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	3D triangular meshes processing and editing tool

EXTRACT_DEPENDS=7z:${PORTSDIR}/archivers/p7zip
LIB_DEPENDS=	libQtSolutions_SOAP-head.so:${PORTSDIR}/devel/qt4-qtsolutions-soap

USE_GL=		glew glu
USE_QT4=	qmake_build moc_build rcc_build uic_build corelib gui xml \
		xmlpatterns opengl network script
USE_DOS2UNIX=	external/structuresynth/ssynth/SyntopiaCore/GLEngine/Object3D.h \
		meshlabplugins/edit_arc3D/fillImage.cpp

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}/src

post-patch:
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
	cd ${WRKSRC}/external && ${QMAKE} -spec ${QMAKESPEC} -recursive external.pro
	cd ${WRKSRC} && ${QMAKE} -spec ${QMAKESPEC} -recursive meshlab_full.pro

do-build:
	cd ${WRKSRC}/external && ${MAKE}
	cd ${WRKSRC} && ${MAKE}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/meshlab/plugins
	cd ${WRKSRC}/distrib/plugins && ${COPYTREE_SHARE} \*.so ${STAGEDIR}${PREFIX}/lib/meshlab/plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/meshlab/shaders
	cd ${WRKSRC}/distrib/shaders && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/meshlab/shaders
	${INSTALL_PROGRAM} ${WRKSRC}/distrib/meshlab ${STAGEDIR}${PREFIX}/lib/meshlab
	${LN} -sf ${PREFIX}/lib/meshlab/meshlab ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
