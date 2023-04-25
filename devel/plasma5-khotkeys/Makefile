PORTNAME=	khotkeys
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 library for hotkeys
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
# kdelibs4support needs doctools
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons globalaccel guiaddons \
		i18n iconthemes init itemmodels itemviews jobwidgets kcmutils \
		kdelibs4support kio notifications parts plasma-framework \
		plasma-workspace service solid sonnet textwidgets \
		unitconversion widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network printsupport widgets \
		x11extras xml \
		buildtools:build qmake:build
USE_XORG=	x11 xtst

.include <bsd.port.mk>
