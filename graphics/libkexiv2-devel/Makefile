PORTNAME=	libkexiv2
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications kde-devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Exiv2 library interface for KDE
WWW=		https://www.digikam.org/

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		cmake compiler:c++11-lang kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		5compat base

CMAKE_ARGS=	-DQT_MAJOR_VERSION=6

.include <bsd.port.mk>
