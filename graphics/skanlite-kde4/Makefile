# $FreeBSD$

PORTNAME=	skanlite
PORTVERSION=	1.1
PORTREVISION=	7
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
PKGNAMESUFFIX=	-kde4
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image scanning application for KDE4

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/src/COPYING

LIB_DEPENDS=	libksane.so:graphics/libksane-kde4

USES=		cmake:outsource gettext kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		qmake_build moc_build rcc_build uic_build

CONFLICTS_INSTALL=	skanlite

.include <bsd.port.mk>
