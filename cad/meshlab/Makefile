# Created by: gahr
# $FreeBSD$

PORTNAME=	meshlab
DISTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_LOCAL}/gahr/ \
		http://people.freebsd.org/~gahr/distfiles/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	3D triangular meshes processing and editing tool

EXTRACT_DEPENDS=7z:${PORTSDIR}/archivers/p7zip
LIB_DEPENDS=	QtSolutions_SOAP-head:${PORTSDIR}/devel/qt4-qtsolutions-soap

USE_GCC=	yes
USE_GL=		glew glu
USE_QT4=	qmake_build moc_build rcc_build uic_build corelib gui xml \
		xmlpatterns opengl network script
USE_DOS2UNIX=	external/structuresynth/ssynth/SyntopiaCore/GLEngine/Object3D.h

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}/src

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
	   ${WRKSRC}/common/pluginmanager.cpp

do-configure:
	cd ${WRKSRC}/external && ${QMAKE} -spec ${QMAKESPEC} -recursive external.pro
	cd ${WRKSRC} && ${QMAKE} -spec ${QMAKESPEC} -recursive meshlab_full.pro

do-build:
	cd ${WRKSRC}/external && ${MAKE}
	cd ${WRKSRC} && ${MAKE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/common/libcommon.so.1.0.0 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libcommon.so.1.0.0 ${PREFIX}/lib/libcommon.so.1.0
	${LN} -sf ${PREFIX}/lib/libcommon.so.1.0 ${PREFIX}/lib/libcommon.so.1
	${LN} -sf ${PREFIX}/lib/libcommon.so.1 ${PREFIX}/lib/libcommon.so
	${MKDIR} ${PREFIX}/lib/meshlab/plugins
	cd ${WRKSRC}/distrib/plugins && ${COPYTREE_SHARE} \*.so ${PREFIX}/lib/meshlab/plugins
	${MKDIR} ${PREFIX}/lib/meshlab/shaders
	cd ${WRKSRC}/distrib/shaders && ${COPYTREE_SHARE} \* ${PREFIX}/lib/meshlab/shaders
	${INSTALL_PROGRAM} ${WRKSRC}/distrib/meshlab ${PREFIX}/lib/meshlab
	${LN} -sf ${PREFIX}/lib/meshlab/meshlab ${PREFIX}/bin

.include <bsd.port.mk>
