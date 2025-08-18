PORTNAME=	kicad
DISTVERSION=	9.0.4
PORTEPOCH=	2
CATEGORIES=	cad

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Schematic and PCB editing software
WWW=		https://kicad.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm	\
		swig:devel/swig
LIB_DEPENDS=	libboost_locale.so:devel/boost-libs	\
		libabsl_log_internal_check_op.so:devel/abseil		\
		libgit2.so:devel/libgit2		\
		libprotobuf.so:devel/protobuf		\
		libnng.so:net/nng			\
		libharfbuzz.so:print/harfbuzz		\
		libngspice.so:cad/ngspice_rework@shlib	\
		libTKernel.so:cad/opencascade		\
		libpixman-1.so:x11/pixman		\
		libzstd.so:archivers/zstd		\
		libcurl.so:ftp/curl			\
		libwayland-client.so:graphics/wayland	\
		libfreetype.so:print/freetype2		\
		libsecret-1.so:security/libsecret	\
		libfontconfig.so:x11-fonts/fontconfig	\
		libodbc.so:databases/unixODBC

USES=		cmake:noninja compiler:c++20-lang desktop-file-utils \
		gnome pkgconfig python shared-mime-info shebangfix \
		tar:bz2 xorg
SHEBANG_FILES=	pcbnew/python/plugins/touch_slider_wizard.py

USE_XORG=	ice x11 xext
USE_GL=		egl gl glu glut opengl
USE_WX=		3.2
WX_COMPS=	python:lib wx
USE_GNOME=	atk cairo gdkpixbuf gtk30 pango

USE_GITLAB=	yes
GL_ACCOUNT=	kicad/code
GL_PROJECT=	kicad

CXXFLAGS+=	-I${WRKSRC}/include -I${LOCALBASE}/include
CXXFLAGS_powerpc=	-O0
# not using "bundled glew" breaks the 3d viewer
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}	\
		-DwxWidgets_USE_UNICODE=ON			\
		-DwxWidgets_wxrc_EXECUTABLE=${WXRC_CMD}		\
		-DKICAD_SPICE_QA=ON				\
		-DKICAD_USE_SENTRY=OFF				\
		-DKICAD_SIGNAL_INTEGRITY=ON			\
		-DKICAD_BUILD_QA_TESTS=ON			\
		-DKICAD_SCRIPTING_WXPYTHON=ON			\
		-DKICAD_UPDATE_CHECK=OFF			\
		-DKICAD_USE_EGL=ON				\
		-DKICAD_USE_BUNDLED_GLEW=ON 			\
		-DKICAD_WAYLAND=ON				\
		-DKICAD_INSTALL_DEMOS=ON			\
		-DNANODBC_ENABLE_BOOST=ON			\
		-DOCC_INCLUDE_DIR=${LOCALBASE}/include/OpenCASCADE
CMAKE_ENV+=	DODBC_PATH=${LOCALBASE}
USE_LDCONFIG=	yes

# SOVERSION helps testing rc packages
PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||} \
		SOVERSION=${PORTVERSION:C/.r[0-9]*//}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_BOOL= KICAD_BUILD_I18N

CONFLICTS_INSTALL=	kicad-devel # bin/_cvpcb.kiface

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local/bin/xdg-open|${LOCALBASE}/bin/xdg-open|' \
		${WRKSRC}/common/pgm_base.cpp

.include <bsd.port.mk>
