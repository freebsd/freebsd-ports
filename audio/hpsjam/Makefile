# Created by: Hans Petter Selasky <hselasky@freebsd.org>
# $FreeBSD$

PORTNAME=	hpsjam
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.11
CATEGORIES=	audio

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Online jamming client and server tool

LICENSE=	BSD2CLAUSE

LIB_DEPENDS= \
	libfftw3.so:math/fftw3 \
	libjack.so:audio/jack

USES=		compiler:c++11-lang gl qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		buildtools_build core gui widgets svg

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky

PLIST_FILES= \
	bin/HpsJam \
	share/pixmaps/HpsJam.png \
	share/applications/HpsJam.desktop

.include <bsd.port.mk>
