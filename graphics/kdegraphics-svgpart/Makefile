# $FreeBSD$

PORTNAME=	svgpart
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications
PKGNAMEPREFIX=	kdegraphics-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SVG KPart

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons ecm \
		i18n jobwidgets kio parts service sonnet textwidgets \
		widgetsaddons xmlgui
USE_QT=		core dbus gui network svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
