# $FreeBSD$

PORTNAME=	FreeCAD
DISTVERSION=	0.17.g20161104
CATEGORIES=	cad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose 3D CAD modeller

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pyside-rcc:devel/pyside-tools		\
		swig:devel/swig13	\
		${LOCALBASE}/libdata/pkgconfig/eigen3.pc:math/eigen3
LIB_DEPENDS=	libexpat.so:textproc/expat2		\
		libfreetype.so:print/freetype2		\
		libboost_python.so:devel/boost-python-libs	\
		libpyside-python2.7.so:devel/pyside	\
		libCoin.so:graphics/Coin		\
		libpng16.so:graphics/png		\
		libtiff.so:graphics/tiff		\
		libvtkFiltersTexture-6.2.so:math/vtk6	\
		libTKernel.so:cad/opencascade		\
		libSoQt.so:x11-toolkits/soqt		\
		libxerces-c-3.1.so:textproc/xerces-c3	\
		libboost_thread.so:devel/boost-libs	\
		libarea.so:devel/libarea		\
		libmed.so:french/med			\
		libshiboken-${PYTHON_VERSION}.so:devel/shiboken

BROKEN_FreeBSD_9=	does not build on FreeBSD 9.x

USE_GITHUB=	yes
GH_TAGNAME=	0ea7373

USES=		compiler:c++11-lib cmake:outsource jpeg python localbase
USE_XORG=	ice sm x11 xext xt
USE_GL=		gl glu
USE_QT4=	qmake_build corelib gui moc_build network opengl rcc_build \
		uic_build svg xml webkit
CMAKE_ARGS=	-DOCC_INCLUDE_DIR="${LOCALBASE}/include/OpenCASCADE" \
		-DFREECAD_USE_EXTERNAL_PIVY=1

CMAKE_INSTALL_PREFIX=	${PREFIX}/${PORTNAME}

DESKTOP_ENTRIES=${PORTNAME} "" "${PREFIX}/FreeCAD/data/freecad.svg" \
		${PORTNAME} "Engineering;" false

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${WRKSRC}/src/Gui/CMakeLists.txt

post-install:
	${LN} -s ../${PORTNAME}/bin/FreeCAD ${STAGEDIR}${LOCALBASE}/bin/FreeCAD
	${LN} -s ../${PORTNAME}/bin/FreeCADCmd ${STAGEDIR}${LOCALBASE}/bin/FreeCADCmd

.include <bsd.port.mk>
