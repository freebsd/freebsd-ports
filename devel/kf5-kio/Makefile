# $FreeBSD$

PORTNAME=	kio
DISTVERSION=	5.54.1 # Respin for bug 402665
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 resource and network access abstraction

USES=		cmake compiler:c++11-lib desktop-file-utils \
		gettext kde:5 qt:5 ssl tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive auth bookmarks codecs completion config \
		configwidgets coreaddons dbusaddons doctools ecm \
		i18n iconthemes itemviews jobwidgets \
		notifications service solid sonnet textwidgets wallet \
		widgetsaddons windowsystem xmlgui
USE_QT=		buildtools_build concurrent core dbus gui network \
		qmake_build script widgets x11extras xml

.include <bsd.port.mk>
