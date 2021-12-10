PORTNAME=	skanlite
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image scanning application

LICENSE=	GPLv2

LIB_DEPENDS=	libKF5Sane.so:graphics/libksane \
		libpng.so:graphics/png

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth config configwidgets codecs completion \
		coreaddons i18n jobwidgets kio \
		service widgetsaddons xmlgui \
		doctools_build ecm_build
USE_QT=		core concurrent dbus gui network widgets xml \
		buildtools_build qmake_build testlib_build

.include <bsd.port.mk>
