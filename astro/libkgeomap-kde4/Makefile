# $FreeBSD$

PORTNAME=	libkgeomap
PORTVERSION=	${KDE4_APPLICATIONS_VERSION}
PORTREVISION=	13
CATEGORIES=	astro kde
MASTER_SITES=	KDE/${KDE4_APPLICATIONS_BRANCH}/applications/${PORTVERSION}/src
PKGNAMESUFFIX=	-kde4
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for browsing photos on a map

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/buffer_concepts.hpp:devel/boost-libs

USES=		cmake:outsource kde:4 pathfix qt:4 tar:xz
USE_KDE=	kdelibs automoc4 marble
USE_LDCONFIG=	yes
USE_QT=		network phonon xml moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
