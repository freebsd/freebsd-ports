# $FreeBSD$

PORTNAME=	libkdegames
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries used by KDE games

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		cmake compiler:c++11-lang gettext kde:5 openal qt:5 \
		tar:xz
USE_KDE=	archive attica auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons dnssd ecm emoticons \
		globalaccel guiaddons i18n iconthemes init itemmodels \
		itemviews jobwidgets kdeclarative kdelibs4support kio newstuff \
		package service textwidgets widgetsaddons xmlgui
USE_QT=		core dbus declarative gui network svg testlib widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

SHLIB_VER=	7.0.0
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}" \
		SHLIB_SHVER="${SHLIB_VER:R:R}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
