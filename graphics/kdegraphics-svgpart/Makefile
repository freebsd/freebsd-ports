PORTNAME=	svgpart
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications
PKGNAMEPREFIX=	kdegraphics-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SVG KPart
WWW=		https://www.kde.org

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons i18n \
		jobwidgets kio parts service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

.include <bsd.port.mk>
