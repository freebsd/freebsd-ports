# $FreeBSD$

PORTNAME=	kreversi
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm i18n iconthemes itemviews \
		jobwidgets kdeclarative kio libkdegames package service \
		solid widgetsaddons xmlgui
USE_QT=		concurrent core dbus declarative gui network svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
