# $FreeBSD$

PORTNAME=	kcmutils
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

PATCH_SITES=	https://github.com/KDE/kcmutils/commit/
PATCHFILES=	ea7120ed901bf6161bb483ab73211a6491daac8f.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 utilities for working with KCModules

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons ecm i18n \
		iconthemes itemviews kdeclarative package service \
		widgetsaddons xmlgui
USE_QT=		buildtools_build core dbus declarative gui network qmake_build \
		widgets xml

.include <bsd.port.mk>
