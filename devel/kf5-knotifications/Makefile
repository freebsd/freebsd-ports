PORTNAME=	knotifications
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 abstraction for system notifications

LIB_DEPENDS=	libcanberra.so:audio/libcanberra

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	config coreaddons windowsystem \
		ecm:build
USE_QT=		core dbus declarative gui linguisttools network widgets x11extras \
		buildtools:build qmake:build
USE_XORG=	x11 xtst

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_dbusmenu-qt5

OPTIONS_DEFINE=		AUDIO
OPTIONS_DEFAULT=	AUDIO

AUDIO_DESC=		Audio notifications/text-to-speech support
AUDIO_USE=		QT=speech

.include <bsd.port.mk>
