# $FreeBSD$

PORTNAME=	giada
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.1
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	6712086d9d64c95dbf919ac74d14ca2e40fe18a5.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Hardcore loop machine

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfltk.so:x11-toolkits/fltk \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libjansson.so:devel/jansson \
		libpulse.so:audio/pulseaudio \
		librtmidi.so:audio/rtmidi \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile

USES=		autoreconf gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	monocasual
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=freebsd
USE_XORG=	x11 xext xft xpm

PLIST_FILES=	bin/giada

.include <bsd.port.mk>
