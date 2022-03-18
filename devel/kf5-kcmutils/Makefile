PORTNAME=	kcmutils
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

PATCH_SITES=	https://invent.kde.org/frameworks/kcmutils/-/commit/
PATCHFILES=	c9c58de65c07c8a940cb4c9b91777450698f635c.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 utilities for working with KCModules

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons guiaddons i18n \
		itemviews kdeclarative package service \
		widgetsaddons xmlgui \
		ecm_build
USE_QT=		core dbus declarative gui network widgets xml \
		buildtools_build qmake_build testlib_build

.include <bsd.port.mk>
