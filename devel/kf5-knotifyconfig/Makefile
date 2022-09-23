PORTNAME=	knotifyconfig
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 configuration system for KNotify

LIB_DEPENDS=	libcanberra.so:audio/libcanberra

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	completion config coreaddons i18n jobwidgets kio \
		service solid widgetsaddons windowsystem \
		ecm:build
USE_QT=		concurrent core dbus gui network phonon4 widgets \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=		AUDIO
OPTIONS_DEFAULT=	AUDIO

AUDIO_DESC=		Audio notifications/text-to-speech support
AUDIO_USE=		QT=speech

.include <bsd.port.mk>
