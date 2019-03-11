# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
PORTVERSION=	5.1.0
PORTEPOCH=	2
CATEGORIES=	cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Schematic and PCB editing software

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm	\
		swig3.0:devel/swig30
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs	\
		libngspice.so:cad/ngspice_rework@shlib	\
		libTKernel.so:cad/opencascade		\
		libpixman-1.so:x11/pixman		\
		libpng.so:graphics/png			\
		libcurl.so:ftp/curl

CONFLICTS=	kicad-devel-r201*

USE_GITHUB=	yes
GH_ACCOUNT=	KiCad
GH_PROJECT=	kicad-source-mirror

USES=		cmake:noninja compiler:c++11-lib desktop-file-utils gl gnome	\
		pkgconfig python:2.7 shared-mime-info shebangfix ssl tar:xz
SHEBANG_FILES=	pcbnew/python/plugins/touch_slider_wizard.py

USE_XORG=	ice x11 xext
USE_GL=		gl glew glu glut
USE_WX=		3.0
WX_COMPS=	python:lib wx
USE_GNOME=	atk cairo
CXXFLAGS+=	--std=c++11 -I${WRKSRC}/include -I${LOCALBASE}/include
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}		\
		-DwxWidgets_USE_UNICODE=ON -DKICAD_SCRIPTING_WXPYTHON=ON\
		-DwxWidgets_wxrc_EXECUTABLE=${WXRC_CMD}			\
		-DKICAD_SCRIPTING=ON -DKICAD_SCRIPTING_MODULES=ON	\
		-DKICAD_SCRIPTING_WXPYTHON_PHOENIX=ON			\
		-DKICAD_USE_OCE=OFF -DKICAD_USE_OCC=ON			\
		-DOCC_INCLUDE_DIR=${LOCALBASE}/include/OpenCASCADE
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

OPTIONS_DEFINE=	DOCS DOXYGEN NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

DOXYGEN_VARS=	LICENSE+=GFDL LICENSE_COMB=multi
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_ALL_TARGET=	all doxygen-docs
DOXYGEN_PORTDOCS=	doxygen

# The CheckCXXSymbolExists module has been shipped with CMake since 3.0 times.
# The ancient implementation that this bundled module uses, no longer works
# because it uses CMake internals that have gone away in 3.11.
post-extract:
	${RM} ${WRKSRC}/CMakeModules/CheckCXXSymbolExists.cmake

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share/kicad|${DATADIR}|'		\
		-e 's|/usr/local|${PREFIX}|'				\
		${WRKSRC}/common/gestfich.cpp
	${REINPLACE_CMD} -e 's|/usr/bin/xdg-open|${LOCALBASE}/bin/xdg-open|' \
		${WRKSRC}/common/pgm_base.cpp

post-install-DOCS-on:
	(cd ${WRKSRC}/Documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
