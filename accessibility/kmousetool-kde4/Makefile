# $FreeBSD$

PORTNAME=	kmousetool
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	accessibility kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Automatic mouse click tool for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		qmake_build moc_build rcc_build uic_build
USE_XORG=	xtst

.include <bsd.port.mk>
