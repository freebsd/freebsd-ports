# $FreeBSD$

PORTNAME=	kanagram
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Letter order game for KDE

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons crash \
		doctools ecm i18n kdeclarative kio libkeduvocdocument newstuff \
		package service sonnet widgetsaddons xmlgui
USE_QT=		core dbus declarative gui network opengl speech svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
