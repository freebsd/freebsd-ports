# $FreeBSD$

PORTNAME=	kcolorchooser
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE application to select colors from the screen or from a palette

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons ecm i18n \
		widgetsaddons xmlgui
USE_QT5=	core dbus gui widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
