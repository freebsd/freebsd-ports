# $FreeBSD$

PORTNAME=	libkgeomap
PORTVERSION=	${KDE4_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	astro kde
MASTER_SITES=	KDE/${KDE4_APPLICATIONS_BRANCH}/applications/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for browsing photos on a map

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/buffer_concepts.hpp:devel/boost-libs

USES=		cmake:outsource kde:4 pathfix tar:xz
USE_KDE=	kdelibs automoc4 marble
USE_LDCONFIG=	yes
USE_QT4=	network phonon xml moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
