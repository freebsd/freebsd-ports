# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	siren
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	http://www.kariliq.nl/${PORTNAME}/dist/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Text-based audio player

LICENSE=	ISCL

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libmad.so:${PORTSDIR}/audio/libmad \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libwavpack.so:${PORTSDIR}/audio/wavpack \
		libopusfile.so:${PORTSDIR}/audio/opusfile

USES=		ncurses pkgconfig
HAS_CONFIGURE=	yes
USE_CSTD=	c99

OPTIONS_MULTI=	SOUND
OPTIONS_MULTI_SOUND=	OSS PULSEAUDIO
OPTIONS_DEFAULT=	OSS
OSS_CONFIGURE_ON=	oss=yes pulse=no
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ON=	oss=no pulse=yes
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	sndfile=no \
		alsa=no \
		ao=no \
		sndio=no \
		sun=no \
		portaudio=no \
		aac=no

post-patch:
	@${REINPLACE_CMD} -e 's|-lcurses|-lncurses|' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/siren
	${FIND} ${STAGEDIR}${PREFIX}/lib/siren -path '*.so' \
		| ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
