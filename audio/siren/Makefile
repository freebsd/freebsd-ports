# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	siren
PORTVERSION=	0.4
CATEGORIES=	audio
MASTER_SITES=	http://www.kariliq.nl/${PORTNAME}/dist/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Text-based audio player

LICENSE=	ISCL

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
	libid3tag.so:${PORTSDIR}/audio/libid3tag \
	libmad.so:${PORTSDIR}/audio/libmad \
	libvorbis.so:${PORTSDIR}/audio/libvorbis \
	libwavpack.so:${PORTSDIR}/audio/wavpack

USES=	ncurses pkgconfig
HAS_CONFIGURE=	yes
USE_CSTD=	c99

OPTIONS_DEFINE=	PULSEAUDIO

CONFIGURE_ARGS=	sndfile=no \
	alsa=no \
	ao=no \
	sndio=no \
	sun=no

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=oss=no pulse=yes
PLIST_SUB+=	OSS="@comment " \
	PULSE=""
.else
CONFIGURE_ARGS+=oss=yes pulse=no
PLIST_SUB+=	OSS="" \
	PULSE="@comment "
.endif

.include <bsd.port.mk>
