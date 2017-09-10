# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
PORTVERSION=	4.0.7
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	cad

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Schematic and PCB editing software

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm	\
		swig3.0:devel/swig30
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs	\
		libpixman-1.so:x11/pixman		\
		libpng.so:graphics/png			\
		libcurl.so:ftp/curl
RUN_DEPENDS=	xpdf:graphics/xpdf

CONFLICTS=	kicad-devel-r201*

USE_GITHUB=	yes
GH_ACCOUNT=	KiCad
GH_PROJECT=	kicad-source-mirror

USES=		cmake:noninja compiler:c++11-lib desktop-file-utils	\
		pkgconfig python shared-mime-info shebangfix ssl tar:xz
SHEBANG_FILES=	pcbnew/scripting/plugins/touch_slider_wizard.py

USE_XORG=	ice x11 xext
USE_GL=		gl glew glu glut
USE_WX=		3.0
WX_COMPS=	python:lib wx
USE_GNOME=	atk cairo
CXXFLAGS+=	--std=c++11 -I${WRKSRC}/include -I${LOCALBASE}/include
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}		\
		-DwxWidgets_USE_UNICODE=ON -DKICAD_STABLE_VERSION=ON	\
		-DwxWidgets_wxrc_EXECUTABLE=${WXRC_CMD}			\
		-DKICAD_SCRIPTING=ON -DKICAD_SCRIPTING_MODULES=ON	\
		-DKICAD_SCRIPTING_WXPYTHON=ON -DKICAD_SKIP_BOOST=ON
INSTALLS_ICONS=	yes

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

OPTIONS_DEFINE=	DOCS DOXYGEN NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

BINS=		cvpcb eeschema gerbview kicad pcbnew
EXTRAS2RM=	linux-non_unicode linux wings3d LINUX.README	\
		contrib_makefiles.txt running_kicad_under_W98.txt

DOXYGEN_VARS=	LICENSE+=GFDL LICENSE_COMB=multi
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_ALL_TARGET=	all doxygen-docs
DOXYGEN_PORTDOCS=	doxygen

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share/kicad|${DATADIR}|'		\
		-e 's|/usr/local|${PREFIX}|'				\
		-e 's|/usr/bin/evince|${LOCALBASE}/bin/xpdf|'		\
		-e 's|/usr/bin/kpdf|${LOCALBASE}/bin/okular|'		\
		-e 's|/usr/bin/xpdf|${LOCALBASE}/bin/xpdf|'		\
		-e 's|/usr/bin/konqueror|${LOCALBASE}/bin/konqueror|'	\
		-e 's|/usr/bin/xdg-open|${LOCALBASE}/bin/xdg-open|'	\
		${WRKSRC}/common/gestfich.cpp

post-install-DOCS-on:
	(cd ${WRKSRC}/Documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
