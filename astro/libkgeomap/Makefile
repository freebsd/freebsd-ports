# $FreeBSD$

PORTNAME=	libkgeomap
PORTVERSION=	${KDE4_APPLICATIONS_VERSION}
CATEGORIES=	astro kde
MASTER_SITES=	KDE/${KDE4_APPLICATIONS_BRANCH}/applications/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for browsing photos on a map

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/buffer_concepts.hpp:devel/boost-libs

USE_KDE4=	kdelibs kdeprefix automoc4 marble
USES=		cmake:outsource pathfix tar:xz
USE_LDCONFIG=	yes
USE_QT4=	network phonon xml moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
