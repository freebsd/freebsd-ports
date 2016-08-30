# $FreeBSD$

PORTNAME=	kmousetool
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Automatic mouse click tool for KDE

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_XORG=	xtst

.include <bsd.port.mk>
