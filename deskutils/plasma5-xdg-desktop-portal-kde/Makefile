PORTNAME=	xdg-desktop-portal-kde
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	deskutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Backend implementation for xdg-desktop-portal

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		cmake kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons i18n itemviews jobwidgets kdeclarative kio \
		kirigami2 notifications package plasma-framework service solid \
		wayland widgetsaddons windowsystem xmlgui \
		ecm_build plasma-wayland-protocols_build
USE_QT=		concurrent core dbus declarative gui network printsupport \
		widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
