# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	midipp
PORTVERSION=	2.0.3
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://home.selasky.org/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	MIDI playback, recording, and live performance tool

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	libumidi>=2.1.0:audio/libumidi
LIB_DEPENDS=	libumidi20.so:audio/libumidi

USES=		compiler:c++11-lang gl qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		buildtools_build core gui network printsupport widgets

PLIST_FILES= \
	bin/midipp \
	share/pixmaps/midipp.png \
	share/applications/midipp.desktop

.include <bsd.port.mk>
