PORTNAME=	ktechlab
DISTVERSIONPREFIX=	v
DISTVERSION=	0.51.0-426
DISTVERSIONSUFFIX=	-g9249fdbd
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	IDE for microcontrollers and electronics
WWW=		https://userbase.kde.org/KTechlab \
		https://github.com/ktechlab/ktechlab

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	msgfmt:devel/gettext-tools \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libgpsim.so:misc/gpsim

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl gnome kde:6 \
		localbase qt:6 pkgconfig shared-mime-info xorg
USE_GITHUB=	yes
USE_GL=		gl opengl
USE_QT=		5compat base serialport tools:build
USE_KDE=	colorscheme completion config configwidgets coreaddons \
		doctools guiaddons iconthemes i18n \
		jobwidgets kio parts service sonnet syntaxhighlighting \
		texteditor textwidgets \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_GNOME=	glib20
USE_XORG=	x11

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility, see https://github.com/ktechlab/ktechlab/issues/82

CXXFLAGS+=	-I${LOCALBASE}/lib/glib-2.0/include

OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

PORTSCOUT=	limit:^\d+\. # prevent alpha-numeric strings

.include <bsd.port.mk>
