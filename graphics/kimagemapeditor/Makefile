PORTNAME=	kimagemapeditor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE generator of HTML image maps
WWW=		https://www.kde.org/applications/development/kimagemapeditor/

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes itemviews \
		jobwidgets kio notifications parts service solid sonnet \
		textwidgets unitconversion widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base webengine
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
