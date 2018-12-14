# $FreeBSD$

PORTNAME=	marble
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	astro kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Virtual globe and world atlas for KDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libquazip5.so:archivers/quazip@qt5

USES=		cmake:outsource compiler:c++11-lang desktop-file-utils gettext \
		kde:5 qt:5 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		crash doctools ecm i18n jobwidgets kio newstuff package parts \
		plasma-framework runner service sonnet textwidgets wallet \
		widgetsaddons xmlgui
USE_QT=		concurrent core dbus declarative designer gui location network opengl \
		phonon4 printsupport script sql svg webchannel webengine widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null
# We have to set QT_IMPORTS_PATH, as it does not get picked up
CMAKE_ARGS=	-DMOBILE:BOOL=FALSE \
		-DQT_IMPORTS_DIR:PATH=${QT_IMPORTDIR}

OPTIONS_DEFINE=	GPS DOCS
OPTIONS_DEFAULT=GPS
OPTIONS_SUB=	yes

GPS_DESC=		Support for GPS position provider
GPS_LIB_DEPENDS=	libgps.so:astro/gpsd
GPS_CMAKE_OFF=		-DWITH_libgps:BOOL=FALSE

.include <bsd.port.mk>
