PORTNAME=	blinken
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Memory enhancement game
WWW=		https://edu.kde.org/blinken/

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons crash dbusaddons \
		doctools guiaddons i18n phonon widgetsaddons xmlgui \
		ecm:build
USE_QT=		base multimedia

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
