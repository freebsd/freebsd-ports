# $FreeBSD$

PORTNAME=	kcoloredit
PORTVERSION=	${APP_VER}.${EXTRA_VER}
PORTREVISION=	7
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/extragear
DISTNAME=	${PORTNAME}-${APP_VER}-kde${EXTRA_VER}
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Palette files editor for KDE

USES=		cmake gettext kde:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build

APP_VER=	2.0.0
EXTRA_VER=	4.4.0

.include <bsd.port.mk>
