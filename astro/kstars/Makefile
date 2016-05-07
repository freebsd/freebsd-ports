# $FreeBSD$

PORTNAME=	kstars
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	astro kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 desktop planetarium

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libwcs.so:astro/wcslib
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen3.pc:math/eigen3 \
		xplanet:astro/xplanet
RUN_DEPENDS=	xplanet:astro/xplanet

USE_KDE4=	kdelibs kdeprefix automoc4
USES=		cmake:outsource compiler:c++11-lib tar:xz
USE_QT4=	opengl qmake_build moc_build rcc_build uic_build

OPTIONS_DEFINE=	PYKDE

PYKDE_DESC=	Support for updating supernovae data
PYKDE_USE=	KDE4=pykde4_run

.include <bsd.port.mk>
