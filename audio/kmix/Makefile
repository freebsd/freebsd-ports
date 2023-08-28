PORTNAME=	kmix
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sound mixer for KDE
WWW=		https://www.kde.org/applications/multimedia/kmix/

LICENSE=	GPLv2

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons \
		emoticons globalaccel i18n iconthemes init itemmodels \
		itemviews kcmutils kdelibs4support notifications package \
		plasma-framework service solid widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		core dbus gui widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

# we want the KF5 version of kmix
CMAKE_ARGS=	-DKMIX_KF5_BUILD:BOOL=TRUE

OPTIONS_DEFINE=	PULSEAUDIO DOCS
# TODO: readd ALSA option
#
# ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
# ALSA_EXTRA_PATCHES_OFF=	${FILESDIR}/extrapatch-no_alsa

PULSEAUDIO_LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
			libpulse.so:audio/pulseaudio
PULSEAUDIO_USES=	gnome
PULSEAUDIO_USE=		GNOME=glib20
PULSEAUDIO_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Canberra \
				CMAKE_DISABLE_FIND_PACKAGE_PulseAudio

.include <bsd.port.mk>
