# $FreeBSD$

PORTNAME=	libkdcraw
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LibRaw interface for KDE

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		liblcms.so:graphics/lcms \
		libxml2.so:textproc/libxml2 \
		libraw.so:graphics/libraw

CMAKE_ARGS+=	-DWITH_OpenMP:BOOL=False \
		-DENABLE_RAWSPEED=True

USES=		cmake:outsource compiler:c++11-lang jpeg kde:5 pkgconfig tar:xz
USE_KDE=	ecm
USE_QT5=	core gui \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
