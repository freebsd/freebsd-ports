# $FreeBSD$

PORTNAME=	lokalize
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	devel kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Computer-aided translation system

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build \
		sql

.include <bsd.port.mk>
