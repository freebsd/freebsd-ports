PORTNAME=	dolphin-plugins
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications kde-devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugins for Dolphin file manager
WWW=		https://www.kde.org/

BUILD_DEPENDS=	dolphin:x11-fm/dolphin-devel
RUN_DEPENDS=	dolphin:x11-fm/dolphin-devel

USES=		cmake compiler:c++11-lang desktop-file-utils gettext gl kde:6 \
		qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	auth bookmarks codecs colorscheme completion config \
		configwidgets coreaddons crash guiaddons i18n iconthemes \
		itemviews jobwidgets kio notifications parts service solid \
		sonnet syntaxhighlighting texteditor textwidgets \
		unitconversion widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		5compat base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
