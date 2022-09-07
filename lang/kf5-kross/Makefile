PORTNAME=	kross
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	lang kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 multi-language application scripting
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kross/html/index.html

USES=		cmake compiler:c++11-lib gettext gl kde:5 qt:5 tar:xz xorg
USE_GL=		gl
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons i18n iconthemes itemviews \
		jobwidgets kio parts service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		doctools_build ecm_build
USE_QT=		concurrent core dbus gui network script uiplugin \
		uitools widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11

.include <bsd.port.mk>
