PORTNAME=	kmix
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Sound mixer for KDE
WWW=		https://www.kde.org/applications/multimedia/kmix/

LICENSE=	GPLv2

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	auth codecs config configwidgets coreaddons dbusaddons \
		globalaccel i18n iconthemes itemmodels itemviews kcmutils \
		notifications package statusnotifieritem service solid \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

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
