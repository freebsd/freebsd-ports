PORTNAME=	kross
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	lang kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 multi-language application scripting

USES=		cmake compiler:c++11-lib gettext gl kde:5 qt:5 tar:xz xorg
USE_GL=		gl
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons i18n iconthemes itemviews \
		jobwidgets kio parts service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network script uiplugin \
		uitools widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
