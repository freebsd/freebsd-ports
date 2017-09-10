# $FreeBSD$

PORTNAME=	kstars
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	astro kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 desktop planetarium

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libwcs.so:astro/wcslib
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:math/eigen3 \
		xplanet:astro/xplanet
RUN_DEPENDS=	xplanet:astro/xplanet

USES=		cmake:outsource compiler:c++11-lib kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	opengl qmake_build moc_build rcc_build uic_build

OPTIONS_DEFINE=	PYKDE

PYKDE_DESC=	Support for updating supernovae data
PYKDE_USE=	KDE=pykde4_run

.include <bsd.port.mk>
