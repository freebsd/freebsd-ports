# $FreeBSD$

PORTNAME=	kcmutils
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 utilities for working with KCModules

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons ecm guiaddons i18n \
		iconthemes itemviews kdeclarative package service \
		widgetsaddons xmlgui
USE_QT=		core dbus declarative gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
