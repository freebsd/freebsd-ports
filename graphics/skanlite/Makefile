# $FreeBSD$

PORTNAME=	skanlite
PORTVERSION=	1.0
CATEGORIES=	graphics kde
MASTER_SITES=	SF/sanewidget/Skanlite/
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image scanning application for KDE

LIB_DEPENDS=	ksane.0:${PORTSDIR}/graphics/libksane

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build
USES=		cmake

# Fix build with no-default PREFIX
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH=${KDE4_PREFIX}

NO_STAGE=	yes
.include <bsd.port.mk>
