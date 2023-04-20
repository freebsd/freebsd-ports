PORTNAME=	kamera
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Digital camera manager for KDE
WWW=		https://www.kde.org

LIB_DEPENDS=	libgphoto2.so:graphics/libgphoto2

USES=		cmake compiler:c++11-lang gettext kde:5 localbase qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons doctools i18n \
		kcmutils kio service widgetsaddons xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
