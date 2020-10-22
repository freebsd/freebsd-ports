# $FreeBSD$

PORTNAME=	libkdcraw
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LibRaw interface for KDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		liblcms.so:graphics/lcms \
		libxml2.so:textproc/libxml2 \
		libraw.so:graphics/libraw

USES=		cmake compiler:c++11-lang jpeg kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		core gui \
		buildtools_build qmake_build
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DWITH_OpenMP:BOOL=False \
		-DENABLE_RAWSPEED=True

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
