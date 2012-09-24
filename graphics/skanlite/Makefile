# $FreeBSD$

PORTNAME=	skanlite
PORTVERSION=	0.9
CATEGORIES=	graphics kde
MASTER_SITES=	SF/sanewidget/Skanlite/
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image scanning application for KDE

LIB_DEPENDS=	ksane.0:${PORTSDIR}/graphics/libksane

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

# Fix build with no-default PREFIX
CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH=${KDE4_PREFIX}

.include <bsd.port.mk>
