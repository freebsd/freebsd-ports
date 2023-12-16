PORTNAME=	blinken
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Memory enhancement game
WWW=		https://edu.kde.org/blinken/

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons crash dbusaddons \
		doctools guiaddons i18n phonon widgetsaddons xmlgui \
		ecm:build
USE_QT=		core dbus gui svg widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
