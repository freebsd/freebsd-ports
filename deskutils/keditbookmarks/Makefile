PORTNAME=	keditbookmarks
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Bookmark Organizer and Editor
WWW=		https://kde.org

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons i18n iconthemes jobwidgets kio parts service \
		solid sonnet textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
