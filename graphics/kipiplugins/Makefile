# $FreeBSD$

PORTNAME=	kipiplugins
DISTVERSION=	5.9.0
PORTREVISION=	3
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/digikam
DIST_SUBDIR=	KDE/digikam/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugins for digikam

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 pkgconfig \
		qt:5 tar:xz
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons ecm i18n itemviews jobwidgets kio libkipi service \
		solid widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui network printsupport widgets xml xmlpatterns \
		buildtools_build qmake_build

CMAKE_ON=	DIGIKAMSC_COMPILE_KIPIPLUGINS
CMAKE_OFF=	DIGIKAMSC_COMPILE_DIGIKAM \
		DIGIKAMSC_COMPILE_DOC \
		DIGIKAMSC_COMPILE_PO

OPTIONS_DEFINE=		MEDIAWIKI KVKONTAKTE
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
OPTIONS_SUB=		yes

MEDIAWIKI_DESC=		MediaWiki Plugin
MEDIAWIKI_CMAKE_BOOL=	DIGIKAMSC_COMPILE_LIBMEDIAWIKI
MEDIAWIKI_LIB_DEPENDS=	libKF5MediaWiki.so:net/libmediawiki

KVKONTAKTE_DESC=	vk.com Plugin
KVKONTAKTE_CMAKE_BOOL=	DIGIKAMSC_COMPILE_LIBKVKONTAKTE
KVKONTAKTE_LIB_DEPENDS=	libKF5Vkontakte.so:net/libkvkontakte

DISTNAME=	digikam-${PORTVERSION}
DISTINFO_FILE=	${.CURDIR:H:H}/graphics/digikam/distinfo
DESCR=		${.CURDIR:H:H}/graphics/digikam/pkg-descr

PLIST_SUB=		SHLIB_VER=${DISTVERSION}

.include <bsd.port.mk>
