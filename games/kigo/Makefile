PORTNAME=	kigo
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://www.kde.org/applications/games/kigo/

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 qt:5 tar:xz xorg
USE_KDE=	attica auth codecs completion config configwidgets \
		coreaddons crash dbusaddons i18n jobwidgets kio \
		libkdegames newstuff notifyconfig service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network svg widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
