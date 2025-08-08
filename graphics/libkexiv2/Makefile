PORTNAME=	libkexiv2
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications
PKGNAMESUFFIX=	-qt6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Exiv2 library interface for KDE
WWW=		https://invent.kde.org/graphics/libkexiv2

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		cmake compiler:c++11-lang kde:6 pkgconfig \
		qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

.include <bsd.port.mk>
