PORTNAME=	fractgen
DISTVERSION=	3.0.11
CATEGORIES=	graphics
MASTER_SITES=	https://www.nntb.no/~dreibh/fractalgenerator/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	Fractal Generator
WWW=		https://www.nntb.no/~dreibh/fractalgenerator/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++23-lang gl qt:6 tar:xz
USE_GL=		opengl
USE_QT=		base tools:build imageformats:run

OPTIONS_DEFINE=			FRACTGEN_CLI \
				FRACTGEN_KDE \
				FRACTGEN_QT \
				EXAMPLES

OPTIONS_DEFAULT=		${OPTIONS_DEFINE:NFRACTGEN_KDE}
OPTIONS_SUB=			yes

EXAMPLES_DESC=			Include example files
FRACTGEN_CLI_DESC=		Build the command-line version
FRACTGEN_KDE_DESC=		Build the KDE version
FRACTGEN_QT_DESC=		Build the Qt version

EXAMPLES_CMAKE_BOOL=		WITH_EXAMPLES

FRACTGEN_CLI_CMAKE_BOOL=	WITH_CLI

FRACTGEN_KDE_LIB_DEPENDS=	libKF6ConfigWidgets.so:x11-toolkits/kf6-kconfigwidgets \
				libKF6ColorScheme.so:x11-themes/kf6-kcolorscheme \
				libKF6ConfigGui.so:devel/kf6-kconfig \
				libKF6ConfigCore.so:devel/kf6-kconfig \
				libKF6GuiAddons.so:x11-toolkits/kf6-kguiaddons
FRACTGEN_KDE_USES=		desktop-file-utils kde:6 shared-mime-info
FRACTGEN_KDE_USE=		KDE=ecm:build,coreaddons,widgetsaddons,xmlgui
FRACTGEN_KDE_CMAKE_BOOL=	WITH_KDE

FRACTGEN_QT_USES=		desktop-file-utils shared-mime-info
FRACTGEN_QT_CMAKE_BOOL=		WITH_QT

.include <bsd.port.mk>
