PORTNAME=	kicad
PORTVERSION=	6.0.6
PORTEPOCH=	2
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/${PORTNAME}/code/${PORTNAME}/-/archive/${DISTVERSION}/

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Schematic and PCB editing software

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm	\
		swig:devel/swig
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs	\
		libharfbuzz.so:print/harfbuzz		\
		libngspice.so:cad/ngspice_rework@shlib	\
		libTKernel.so:cad/opencascade		\
		libpixman-1.so:x11/pixman		\
		libpng.so:graphics/png			\
		libcurl.so:ftp/curl			\
		libGLEW-wayland.so:graphics/glew-wayland

CONFLICTS_INSTALL=	kicad-devel # bin/_cvpcb.kiface

USES=		cmake:noninja compiler:c++11-lib desktop-file-utils gl \
		gnome pkgconfig python:3.5+ shared-mime-info shebangfix ssl \
		tar:bz2 xorg
SHEBANG_FILES=	pcbnew/python/plugins/touch_slider_wizard.py

USE_XORG=	ice x11 xext
USE_GL=		gl glu glut
USE_WX=		3.1
WX_COMPS=	python:lib wx
USE_GNOME=	atk cairo gdkpixbuf2 gtk30 pango
CXXFLAGS+=	--std=c++11 -I${WRKSRC}/include -I${LOCALBASE}/include
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}	\
		-DwxWidgets_USE_UNICODE=ON			\
		-DwxWidgets_wxrc_EXECUTABLE=${WXRC_CMD}		\
		-DKICAD_SCRIPTING_WXPYTHON=ON			\
		-DKICAD_USE_OCC=ON				\
		-DKICAD_USE_EGL=ON				\
		-DKICAD_USE_BUNDLED_GLEW=ON 			\
		-DOCC_INCLUDE_DIR=${LOCALBASE}/include/OpenCASCADE
USE_LDCONFIG=	yes

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

OPTIONS_DEFINE=	DOCS DOXYGEN NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

DOXYGEN_VARS=	LICENSE+=GFDL LICENSE_COMB=multi
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_ALL_TARGET=	all doxygen-docs
DOXYGEN_PORTDOCS=	doxygen

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local/bin/xdg-open|${LOCALBASE}/bin/xdg-open|' \
		${WRKSRC}/common/pgm_base.cpp

post-install-DOCS-on:
	(cd ${WRKSRC}/Documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
