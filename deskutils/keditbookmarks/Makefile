# $FreeBSD$

PORTNAME=	keditbookmarks
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Bookmark Organizer and Editor

USES=		cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons ecm i18n iconthemes jobwidgets kio parts service \
		sonnet textwidgets widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
