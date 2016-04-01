# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	siren
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	http://www.kariliq.nl/${PORTNAME}/dist/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Text-based audio player

LICENSE=	ISCL

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libid3tag.so:audio/libid3tag \
		libmad.so:audio/libmad \
		libvorbis.so:audio/libvorbis \
		libwavpack.so:audio/wavpack \
		libopusfile.so:audio/opusfile

USES=		ncurses pkgconfig
HAS_CONFIGURE=	yes
USE_CSTD=	c99

OPTIONS_MULTI=	SOUND
OPTIONS_MULTI_SOUND=	OSS PULSEAUDIO
OPTIONS_DEFAULT=	OSS
OSS_CONFIGURE_ON=	oss=yes pulse=no
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
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
