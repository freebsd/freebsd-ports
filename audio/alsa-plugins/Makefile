PORTNAME=	alsa-plugins
PORTVERSION=	1.2.12
CATEGORIES=	audio
MASTER_SITES=	https://www.alsa-project.org/files/pub/plugins/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ALSA compatibility library plugins
WWW=		https://www.alsa-project.org/

LICENSE=	LGPL21+

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		alias libtool:keepla localbase pkgconfig tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib/alsa-lib
GNU_CONFIGURE=	yes
MAKE_ARGS+=	RM="${RM}"
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${.CURDIR}/../alsa-lib/files

OPTIONS_DEFINE=		FFMPEG JACK PULSEAUDIO SAMPLERATE SPEEX
OPTIONS_SUB=		yes

FFMPEG_LIB_DEPENDS=		libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=	libav

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio

SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=	samplerate

SPEEX_LIB_DEPENDS=	libspeexdsp.so:audio/speexdsp
SPEEX_CONFIGURE_ON=	--with-speex=lib
SPEEX_CONFIGURE_OFF=	--without-speex

post-install:
# sanitize links
	cd ${STAGEDIR}${PREFIX}/etc/alsa/conf.d && for i in [0-9][0-9]-*.conf ; do \
		${LN} -sf ../../../share/alsa/alsa.conf.d/$$i . ; done

.include <bsd.port.mk>
