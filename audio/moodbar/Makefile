# $FreeBSD$

PORTNAME=	moodbar
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Generates mood files from audio files

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3

USES=		compiler:c++14-lang meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	exaile

USE_GNOME=	glib20
USE_GSTREAMER1=	yes good ogg vorbis

PLIST_FILES=	bin/moodbar

.include <bsd.port.mk>
