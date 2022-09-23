PORTNAME=	kreversi
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://www.kde.org/applications/games/kreversi/

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons i18n iconthemes itemviews \
		jobwidgets kdeclarative kio libkdegames package service \
		solid widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network svg widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
