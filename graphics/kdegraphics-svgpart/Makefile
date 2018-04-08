# $FreeBSD$

PORTNAME=	svgpart
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications
PKGNAMEPREFIX=	kdegraphics-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SVG KPart

USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons ecm \
		i18n jobwidgets kio parts service sonnet textwidgets \
		widgetsaddons xmlgui
USE_QT5=	core dbus gui network svg widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
