# $FreeBSD$

PORTNAME=	libkexiv2
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Exiv2 library interface for KDE

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		cmake:outsource compiler:c++11-lang kde:5 pkgconfig tar:xz
USE_KDE=	ecm
USE_QT5=	core gui \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
