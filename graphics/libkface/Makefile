# $FreeBSD$

PORTNAME=	libkface
PORTVERSION=	${KDE4_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/${KDE4_APPLICATIONS_BRANCH}/applications/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for face recognition

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi

LIB_DEPENDS=	libopencv_legacy.so:graphics/opencv2

USES=		cmake:outsource kde:4 pathfix pkgconfig tar:xz
USE_KDE=	kdelibs automoc4 marble
USE_LDCONFIG=	yes
USE_QT4=	network phonon xml moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
