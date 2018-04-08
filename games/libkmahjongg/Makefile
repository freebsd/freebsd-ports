# $FreeBSD$

PORTNAME=	libkmahjongg
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for the Mahjongg Solitaire for KDE 5

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 tar:xz
USE_KDE=	completion config configwidgets coreaddons ecm i18n widgetsaddons
USE_QT5=	core gui svg widgets \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
