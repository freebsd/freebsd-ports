PORTNAME=	plasma-pa
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	audio kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma applet for audio volume management using PulseAudio

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libpulse.so:audio/pulseaudio \
		libKF6PulseAudioQt.so:audio/pulseaudio-qt
RUN_DEPENDS=	${LOCALBASE}/share/sounds/freedesktop/index.theme:audio/freedesktop-sound-theme \
		libcanberra-pulse>0:audio/libcanberra-pulse

USES=		cmake compiler:c++17-lang gettext gl gnome kde:6 pkgconfig \
		qt:6 tar:xz
USE_KDE=	config coreaddons dbusaddons doctools globalaccel i18n \
		kcmutils kdeclarative kirigami2 libplasma \
		statusnotifieritem svg \
		ecm:build \
		itemmodels:run kirigami-addons:run
USE_GL=		gl opengl
USE_GNOME=	glib20
USE_QT=		base declarative

.include <bsd.port.mk>
