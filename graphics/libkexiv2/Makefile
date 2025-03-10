PORTNAME=	libkexiv2
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Exiv2 library interface for KDE
WWW=		https://www.digikam.org/

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		cmake compiler:c++11-lang kde:${FLAVOR:S/qt//} pkgconfig \
		qt:${FLAVOR:S/qt//} tar:xz
USE_KDE=	ecm:build
_USE_QT_qt5=	core gui buildtools:build qmake:build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

USE_LDCONFIG=	yes

PLIST=		pkg-plist.${FLAVOR}

.include <bsd.port.mk>
