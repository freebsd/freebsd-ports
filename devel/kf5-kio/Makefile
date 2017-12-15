# $FreeBSD$

PORTNAME=	kio
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 resource and network access abstraction

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils \
		gettext kde:5 ssl tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive auth bookmarks codecs completion config \
		configwidgets coreaddons dbusaddons doctools ecm \
		i18n iconthemes itemviews jobwidgets \
		notifications service solid sonnet textwidgets wallet \
		widgetsaddons windowsystem xmlgui
USE_QT5=	buildtools_build concurrent core dbus gui network \
		qmake_build script widgets x11extras xml

.include <bsd.port.mk>
