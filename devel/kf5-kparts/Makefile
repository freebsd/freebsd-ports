# Created by: tcberner
# $FreeBSD$

PORTNAME=	kparts
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 document centric plugin system

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		i18n iconthemes jobwidgets kio notifications service \
		sonnet textwidgets widgetsaddons xmlgui
USE_QT5=	buildtools_build core dbus gui network qmake_build widgets \
		xml

.include <bsd.port.mk>
