# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qaudiosonar
PORTVERSION=	1.7.0
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Quick Audio Sonar

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libportaudio.so:audio/portaudio

USES=		compiler:c++11-lang gl qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		buildtools_build core gui widgets

PLIST_FILES= \
	bin/qaudiosonar \
	share/pixmaps/qaudiosonar.png \
	share/applications/qaudiosonar.desktop

.include <bsd.port.mk>
