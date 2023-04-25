PORTNAME=	plasma-pa
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	audio kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 Plasma pulse audio mixer
WWW=		https://www.kde.org/plasma-desktop

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libpulse.so:audio/pulseaudio

USES=		cmake compiler:c++11-lib gettext gnome kde:5 pkgconfig qt:5 \
		shebangfix tar:xz
USE_GNOME=	glib20
USE_KDE=	config configwidgets coreaddons ecm globalaccel i18n kcmutils \
		kdeclarative notifications package plasma-framework \
		doctools:build
USE_QT=		core dbus declarative gui network widgets xml \
		buildtools:build qmake:build

SHEBANG_FILES=	data/plasmaVolumeDisableKMixAutostart.pl
CMAKE_OFF=	USE_GCONF

.include <bsd.port.mk>
