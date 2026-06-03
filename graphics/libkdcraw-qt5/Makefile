PORTNAME=	libkdcraw
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications
PKGNAMESUFFIX=	-qt5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LibRaw interface for KDE
WWW=		https://invent.kde.org/graphics/libkdcraw

LICENSE=	GPLv2+

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		liblcms.so:graphics/lcms \
		libraw.so:graphics/libraw \
		libxml2.so:textproc/libxml2

USES=		cmake compiler:c++11-lang jpeg kde:5 pkgconfig \
		qt:5 tar:xz
USE_KDE=	ecm:build
USE_QT=		core gui buildtools:build qmake:build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_RAWSPEED=True \
		-DQT_MAJOR_VERSION=5 \
		-DWITH_OpenMP:BOOL=False

KDE_APPLICATIONS_VERSION=	25.12.3
PORTSCOUT=	ignore:1

.include <bsd.port.mk>
