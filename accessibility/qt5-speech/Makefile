# $FreeBSD$

PORTNAME=	speech
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	accessibility
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibilty features for Qt5

LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher

USES=		compiler:c++11-lang pkgconfig qmake:outsource qt-dist:5,speech
USE_QT=		core gui buildtools_build qmake_build

.include <bsd.port.mk>
