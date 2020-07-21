# $FreeBSD$

PORTNAME=	knotifyconfig
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 configuration system for KNotify

LIB_DEPENDS=	libcanberra.so:audio/libcanberra

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	completion config coreaddons ecm i18n jobwidgets kio \
		service widgetsaddons windowsystem
USE_QT=		concurrent core dbus gui network phonon4 widgets \
		buildtools_build qmake_build

OPTIONS_DEFINE=		AUDIO
OPTIONS_DEFAULT=	AUDIO

AUDIO_DESC=		Audio notifications/text-to-speech support
AUDIO_USE=		QT=speech

.include <bsd.port.mk>
