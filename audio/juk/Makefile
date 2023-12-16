PORTNAME=	juk
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Jukebox, tagger and music collection manager
WWW=		https://www.kde.org/applications/multimedia/juk/

LICENSE=	GPLv2

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons globalaccel i18n iconthemes itemviews \
		jobwidgets kio notifications phonon service solid sonnet textwidgets \
		wallet widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network svg widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
