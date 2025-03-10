PORTNAME=	skanlite
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image scanning application
WWW=		https://www.kde.org/applications/graphics/skanlite

LICENSE=	GPLv2

LIB_DEPENDS=	libKSaneWidgets6.so:graphics/libksane \
		libpng.so:graphics/png

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons i18n \
		jobwidgets kio service solid widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		base
USE_XORG=	x11

.include <bsd.port.mk>
