PORTNAME=	dolphin-plugins
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugins for Dolphin file manager
WWW=		https://www.kde.org/

BUILD_DEPENDS=	dolphin:x11-fm/dolphin
RUN_DEPENDS=	dolphin:x11-fm/dolphin

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes itemviews \
		jobwidgets kio notifications parts service solid sonnet \
		syntaxhighlighting texteditor textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
