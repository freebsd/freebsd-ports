PORTNAME=	libkdegames
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Libraries used by KDE games
WWW=		https://www.kde.org/applications/games/

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		cmake compiler:c++11-lang gettext kde:6 openal qt:6 tar:xz
USE_KDE=	archive attica auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons dnssd globalaccel \
		guiaddons i18n iconthemes itemmodels itemviews jobwidgets \
		kdeclarative kio newstuff package service textwidgets \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		base declarative
USE_LDCONFIG=	yes

_${PORTNAME}_PROJECT_VERSION=	6.0
PLIST_SUB+=	SHLIB_SHVER="${_${PORTNAME}_PROJECT_VERSION:R}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
