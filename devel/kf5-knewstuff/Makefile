# Created by: tcberner
# $FreeBSD$

PORTNAME=	knewstuff
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for downloading application assets from the network

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 tar:xz
USE_KDE=	archive attica5 auth codecs completion config \
		configwidgets coreaddons ecm i18n iconthemes itemviews \
		jobwidgets kio service sonnet textwidgets widgetsaddons \
		xmlgui
USE_QT5=	buildtools_build core dbus gui network qmake_build \
		quick widgets xml

.include <bsd.port.mk>
