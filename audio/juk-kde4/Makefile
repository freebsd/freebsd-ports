# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	juk
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	audio kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Jukebox, tagger and music collection manager

LICENSE=	GPLv2

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	automoc4 kdelibs
USE_QT=		moc_build qmake_build rcc_build uic_build

CMAKE_ARGS=	-DWITH_TunePimp:BOOL=OFF

.include <bsd.port.mk>
