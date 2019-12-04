# $FreeBSD$

PORTNAME=	marble
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	astro kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Virtual globe and world atlas for KDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libquazip5.so:archivers/quazip

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		kde:5 qt:5 shared-mime-info tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		crash doctools ecm i18n jobwidgets kio newstuff package parts \
		plasma-framework plasma-workspace-wallpapers runner service \
		sonnet textwidgets wallet widgetsaddons xmlgui
USE_QT=		concurrent core dbus declarative designer gui location network opengl \
		phonon4 printsupport script serialport sql svg webchannel widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null
# We have to set QT_IMPORTS_PATH, as it does not get picked up
CMAKE_ARGS=	-DMOBILE:BOOL=FALSE \
		-DQT_IMPORTS_DIR:PATH=${QT_IMPORTDIR}

OPTIONS_DEFINE=	GPS DOCS WEBENGINE
OPTIONS_DEFAULT=GPS
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE
OPTIONS_DEFAULT_powerpc64=	${OPTIONS_DEFAULT_powerpc64_${OSREL:R}}
OPTIONS_DEFAULT_powerpc64_13=	WEBENGINE
OPTIONS_SUB=	yes

GPS_DESC=		Support for GPS position provider
GPS_LIB_DEPENDS=	libgps.so:astro/gpsd
GPS_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_libgps

WEBENGINE_DESC=		Add dependency on qt5-webengine
WEBENGINE_USE=		QT=webengine
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets

.include <bsd.port.mk>
