PORTNAME=	kipi-plugins
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugin architecture for image applications
WWW=		https://github.com/kde/kipi-plugins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig \
		qt:5 tar:xz xorg
USE_KDE=	kio libkipi solid archive auth bookmarks codecs completion \
		config configwidgets coreaddons i18n itemviews jobwidgets \
		service widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network printsupport widgets xml xmlpatterns \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=		DOCS MEDIAWIKI KVKONTAKTE
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
OPTIONS_SUB=		yes

MEDIAWIKI_DESC=		MediaWiki Plugin
MEDIAWIKI_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF5MediaWiki
MEDIAWIKI_LIB_DEPENDS=	libKF5MediaWiki.so:net/libmediawiki

KVKONTAKTE_DESC=	vk.com Plugin
KVKONTAKTE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_KF5Vkontakte
KVKONTAKTE_LIB_DEPENDS=	libKF5Vkontakte.so:net/libkvkontakte

.include <bsd.port.mk>
