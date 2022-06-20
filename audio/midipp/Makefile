# Created by: Hans Petter Selasky <hselasky@FreeBSD.org>

PORTNAME=	midipp
DISTVERSIONPREFIX=	v
DISTVERSION=		2.1.4
CATEGORIES=	audio

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	MIDI playback, recording, and live performance tool

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	libumidi>=2.1.3:audio/libumidi
LIB_DEPENDS=	libumidi20.so:audio/libumidi

USES=		compiler:c++11-lang gl qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		buildtools_build core gui network printsupport widgets

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

PLIST_FILES= \
	bin/midipp \
	share/pixmaps/midipp.png \
	share/applications/midipp.desktop

.include <bsd.port.mk>
