PORTNAME=	colord-kde
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Color profiles manager
WWW=		https://invent.kde.org/graphics/colord-kde

LIB_DEPENDS=	liblcms2.so:graphics/lcms2

USES=		cmake gettext kde:6 pkgconfig qt:6 tar:xz xorg
USE_KDE=	coreaddons dbusaddons i18n itemmodels kcmutils \
		widgetsaddons windowsystem  \
		ecm:build
USE_QT=		base declarative
USE_XORG=	x11 xcb xrandr

.include <bsd.port.mk>
