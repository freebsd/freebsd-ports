# $FreeBSD$

PORTNAME=	kanagram
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Letter order game for KDE

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons crash \
		doctools ecm i18n kdeclarative kio libkeduvocdocument newstuff \
		package service sonnet widgetsaddons xmlgui
USE_QT5=	core dbus gui network opengl qml quick speech svg widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
