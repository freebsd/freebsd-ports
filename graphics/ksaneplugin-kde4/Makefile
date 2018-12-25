# $FreeBSD$

PORTNAME=	ksaneplugin
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	graphics kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 plugin for scanning through libksane

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs libksane automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
