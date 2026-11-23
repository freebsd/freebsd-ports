PORTNAME=	kcmutils
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 utilities for working with KCModules

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons guiaddons i18n \
		itemviews kdeclarative package service \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		core dbus declarative gui network widgets xml \
		buildtools:build qmake:build testlib:build

.include <bsd.port.mk>
