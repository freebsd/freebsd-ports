PORTNAME=	marble
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	7
CATEGORIES=	astro education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Virtual globe and world atlas for KDE
WWW=		https://marble.kde.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		kde:5 qt:5 shared-mime-info tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		crash doctools i18n jobwidgets kio package parts phonon \
		plasma-framework plasma-workspace-wallpapers runner service solid \
		sonnet textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_LDCONFIG=	yes
USE_QT=		concurrent core dbus declarative designer gui network \
		printsupport serialport sql svg widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

CMAKE_OFF=	MOBILE

# Override shared library version
KDE_APPLICATIONS_SHLIB_VER=	${KDE_APPLICATIONS_SHLIB_G_VER}

OPTIONS_DEFINE=		DOCS GPS WEBENGINE
OPTIONS_DEFAULT=	GPS
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE
OPTIONS_SUB=		yes

GPS_DESC=		Support for GPS position provider
GPS_USE=		QT=location
GPS_LIB_DEPENDS=	libgps.so:astro/gpsd
GPS_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_libgps

WEBENGINE_DESC=		Build various plugins that require qt5-webengine
WEBENGINE_USE=		QT=location,webchannel,webengine
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets

.include <bsd.port.mk>
