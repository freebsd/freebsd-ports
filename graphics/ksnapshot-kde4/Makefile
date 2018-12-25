# $FreeBSD$

PORTNAME=	ksnapshot
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	graphics kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 screen capture program

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs libkipi automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xext xfixes

.include <bsd.port.mk>
