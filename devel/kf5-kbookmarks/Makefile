PORTNAME=	kbookmarks
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for bookmarks and the XBEL format

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		core dbus gui linguisttools widgets xml \
		buildtools:build qmake:build

.include <bsd.port.mk>
