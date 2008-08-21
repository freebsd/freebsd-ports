# New ports collection makefile for:	FreeCAD
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	FreeCAD
DISTVERSION=	0.6.472
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	free-cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A general purpose 3D CAD modeller

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	gts.5:${PORTSDIR}/graphics/gts			\
		SoQt.24:${PORTSDIR}/x11-toolkits/soqt		\
		TKernel.0:${PORTSDIR}/cad/opencascade		\
		xerces-c.27:${PORTSDIR}/textproc/xerces-c2	\
		Wm4Foundation.0:${PORTSDIR}/graphics/wildmagic

USE_PYTHON=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-wildmagic-includes=${LOCALBASE}/include/Wm4	\
		--with-wildmagic-libs=${LOCALBASE}/lib			\
		--with-xercesc-includes=${LOCALBASE}/include		\
		--with-xercesc-libs=${LOCALBASE}/lib			\
		--with-OCC-includes=${LOCALBASE}/OpenCAS/ros/inc	\
		--with-OCC-libs=${LOCALBASE}/lib
QTDIR=		${QT_PREFIX}
QMAKESPEC=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
MAKE_ENV=	QMAKESPEC="${QMAKESPEC}" QTDIR="${QTDIR}"
PLIST_SUB=	QTDIR="${QTDIR}"

WM3TOWM4=	Core/Approximation.cpp Core/Approximation.h Core/Algorithm.cpp	\
		Core/Algorithm.h Core/Elements.cpp Core/Evaluation.cpp		\
		Core/Tools.h Core/Tools.cpp Core/TopoAlgorithm.cpp		\
		FeatureMeshCurvature.cpp MeshCurvature.cpp MeshPy.cpp		\
		PreCompiled.h
MOD2FIX=	App/FreeCADInit.py Gui/FreeCADGuiInit.py

pre-configure:
	${REINPLACE_CMD} -e 's|Wm3|Wm4|g;s|wm3|wm4|g;s|WM3|WM4|g'	\
		-e 's|-lpthread|${PTHREAD_LIBS}|'	${WRKSRC}/${CONFIGURE_SCRIPT}
.for sf in ${WM3TOWM4}
	${REINPLACE_CMD} -e 's|Wm3|Wm4|g;s|wm3|wm4|g;s|WM3|WM4|g'	\
		${WRKSRC}/src/Mod/Mesh/App/${sf}
.endfor
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS}	\
		${REINPLACE_CMD} -e 's|WM3|WM4|g'	\
			-e 's|$$(prefix)/Mod|${DATADIR}/Mod|'
.for sf in ${MOD2FIX}
	${REINPLACE_CMD} -e	\
		's|/usr/local/share/FreeCAD|${DATADIR}|'	\
		${WRKSRC}/src/${sf}
.endfor

pre-build:
	cd ${WRKSRC}/src/Tools/plugins/widget &&			\
	${SETENV} ${MAKE_ENV} qmake plugin.pro &&	\
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

pre-install:
	${MKDIR} ${QTDIR}/plugin/designer
	${INSTALL_PROGRAM}	\
		${WRKSRC}/src/Tools/plugins/widget/plugin/libFreeCAD_widgets.so	\
		${QTDIR}/plugin/designer

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/Mod
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/Mod

.include <bsd.port.mk>
