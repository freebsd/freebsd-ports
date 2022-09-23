PORTNAME=	kcolorchooser
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE application to select colors from the screen or from a palette
WWW=		https://www.kde.org/applications/graphics/kcolorchooser

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons i18n \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		core dbus gui widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
