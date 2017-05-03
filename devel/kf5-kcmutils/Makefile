# Created by: tcberner
# $FreeBSD$

PORTNAME=	kcmutils
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 utilities for working with KCModules

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons ecm i18n \
		iconthemes itemviews kdeclarative package service \
		widgetsaddons xmlgui
USE_QT5=	buildtools_build core dbus gui network qmake_build \
		qml quick widgets xml

.include <bsd.port.mk>
