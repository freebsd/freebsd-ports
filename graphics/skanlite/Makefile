# $FreeBSD$

PORTNAME=	skanlite
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image scanning application for KDE

LIB_DEPENDS=	libksane.so:graphics/libksane

USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build
USES=		cmake:outsource gettext tar:xz

.include <bsd.port.mk>
