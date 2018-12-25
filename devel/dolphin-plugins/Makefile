# $FreeBSD$

PORTNAME=	dolphin-plugins
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugins for Dolphin file manager

BUILD_DEPENDS=	dolphin:x11-fm/dolphin
RUN_DEPENDS=	dolphin:x11-fm/dolphin

USES=		cmake gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes itemviews jobwidgets \
		kdelibs4support kio notifications parts service solid sonnet \
		texteditor textwidgets unitconversion widgetsaddons \
		windowsystem xmlgui
USE_QT=		core dbus gui network printsupport widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
