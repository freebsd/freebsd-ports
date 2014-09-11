# $FreeBSD$

PORTNAME=	kstars
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	astro kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 desktop planetarium

LIB_DEPENDS=	libcfitsio.so:${PORTSDIR}/astro/cfitsio \
		libwcs.so:${PORTSDIR}/astro/wcslib
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2 \
		xplanet:${PORTSDIR}/astro/xplanet
RUN_DEPENDS=	xplanet:${PORTSDIR}/astro/xplanet

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USES=		cmake:outsource compiler:c++11-lib tar:xz
USE_QT4=	opengl qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
