PORTNAME=	kbounce
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://www.kde.org/applications/games/kbounce/

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons guiaddons i18n iconthemes jobwidgets kio \
		libkdegames notifyconfig phonon service solid textwidgets widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network svg \
		testlib widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
