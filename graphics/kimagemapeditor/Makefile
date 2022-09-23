PORTNAME=	kimagemapeditor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE generator of HTML image maps
WWW=		https://www.kde.org/applications/development/kimagemapeditor/

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 qt:5 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes itemviews \
		jobwidgets js kdelibs4support khtml kio notifications \
		parts service solid sonnet textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus declarative gui location network printsupport \
		webchannel webengine widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
