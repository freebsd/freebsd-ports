# $FreeBSD$

PORTNAME=	kbookmarks
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for bookmarks and the XBEL format

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons ecm \
		iconthemes widgetsaddons xmlgui
USE_QT=		core dbus gui linguisttools widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
