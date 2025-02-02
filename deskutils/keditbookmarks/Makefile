PORTNAME=	keditbookmarks
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Bookmark Organizer and Editor
WWW=		https://kde.org

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons i18n iconthemes jobwidgets kio parts service solid \
		sonnet textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
