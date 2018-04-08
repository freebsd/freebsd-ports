# $FreeBSD$

PORTNAME=	khangman
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Hangman game for KDE 4

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		crash doctools ecm i18n kdeclarative libkeduvocdocument \
		newstuff notifications package service widgetsaddons xmlgui
USE_QT5=	core dbus gui network qml quick svg widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
