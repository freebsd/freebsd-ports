PORTNAME=	skanlite
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image scanning application
WWW=		https://www.kde.org/applications/graphics/skanlite

LICENSE=	GPLv2

LIB_DEPENDS=	libKF5Sane.so:graphics/libksane \
		libpng.so:graphics/png

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth config configwidgets codecs completion \
		coreaddons i18n jobwidgets kio \
		service solid widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		core concurrent dbus gui network widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

.include <bsd.port.mk>
