PORTNAME=	libkdcraw
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications
PKGNAMESUFFIX=	-qt6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LibRaw interface for KDE
WWW=		https://invent.kde.org/graphics/libkdcraw

LICENSE=	GPLv2+

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		liblcms.so:graphics/lcms \
		libraw.so:graphics/libraw \
		libxml2.so:textproc/libxml2

USES=		cmake compiler:c++11-lang jpeg kde:6 pkgconfig \
		qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_RAWSPEED=True \
		-DWITH_OpenMP:BOOL=False

.include <bsd.port.mk>
