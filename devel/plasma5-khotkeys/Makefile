# $FreeBSD$

PORTNAME=	khotkeys
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 library for hotkeys

USES=		cmake compiler:c++11-lib cpe gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm emoticons globalaccel \
		guiaddons i18n iconthemes init itemmodels itemviews jobwidgets \
		kcmutils kdelibs4support kio notifications parts \
		plasma-framework plasma-workspace service solid sonnet \
		textwidgets unitconversion widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui network printsupport widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	x11 xtst

.include <bsd.port.mk>
