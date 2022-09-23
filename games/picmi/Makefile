PORTNAME=	picmi
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://games.kde.org/

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons doctools i18n jobwidgets kdeclarative kio \
		libkdegames newstuff service solid widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network svg testlib widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
