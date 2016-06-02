# $FreeBSD$

PORTNAME=	kcoloredit
PORTVERSION=	${APP_VER}.${EXTRA_VER}
PORTREVISION=	5
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/extragear
DISTNAME=	${PORTNAME}-${APP_VER}-kde${EXTRA_VER}
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Palette files editor for KDE

USE_KDE4=	kdelibs automoc4
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USES=		cmake gettext tar:bzip2

APP_VER=	2.0.0
EXTRA_VER=	4.4.0

.include <bsd.port.mk>
