PORTNAME=	kontrast
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics accessibility kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Color contrast checker
WWW=		https://apps.kde.org/en/kontrast

PATCH_SITES=	https://invent.kde.org/accessibility/kontrast/-/commit/
PATCHFILES+=	1fb315a862c30c20e99dd70967ca5be82d249dd4.patch:-p1

LIB_DEPENDS=	libQCoro5Core.so:devel/qcoro@qt5 \
		libfuturesql5.so:databases/futuresql

USES=		compiler:c++11-lang cmake pkgconfig \
		kde:5 qt:5 tar:xz
USE_KDE=	coreaddons i18n kirigami2 \
		ecm:build
USE_QT=		core dbus declarative gui network quickcontrols2 sql svg widgets \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
