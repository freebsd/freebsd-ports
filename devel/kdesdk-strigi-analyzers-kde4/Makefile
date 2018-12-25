# $FreeBSD$

PORTNAME=	kdesdk-strigi-analyzers
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel kde kde-kde4
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Strigi analyzers for SDK related file formats

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4 strigi
USE_QT=		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
