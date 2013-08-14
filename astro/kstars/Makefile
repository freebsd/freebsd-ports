# $FreeBSD$

PORTNAME=	kstars
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 desktop planetarium

LIB_DEPENDS=	cfitsio.0:${PORTSDIR}/astro/cfitsio \
		wcs:${PORTSDIR}/astro/wcslib

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2 \
		xplanet:${PORTSDIR}/astro/xplanet

RUN_DEPENDS=	xplanet:${PORTSDIR}/astro/xplanet

CONFLICTS=	kdeedu-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USES=		cmake:outsource
USE_QT4=	opengl qmake_build moc_build rcc_build uic_build
USE_XZ=		yes

.include <bsd.port.mk>
