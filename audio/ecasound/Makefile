# Created by: The Anarcat <anarcat@anarcat.dyndns.org>
# $FreeBSD$

PORTNAME=	ecasound
PORTVERSION=	2.9.0
CATEGORIES=	audio
MASTER_SITES=	http://ecasound.seul.org/download/ \
		http://nosignal.fi/download/ \
		http://ecawave.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multitrack audio processing software

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

OPTIONS_DEFINE=	ALSA AUDIOFILE JACK LIBLO LIBOIL PYTHON SAMPLERATE SNDFILE
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	PYTHON

USES=		gmake readline
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-liblilv \
		--disable-rubyecasound \
		--enable-sys-readline \
		--disable-arts
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

ALSA_CONFIGURE_ENABLE=	alsa
ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
AUDIOFILE_CONFIGURE_ENABLE=	audiofile
AUDIOFILE_LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile
JACK_CONFIGURE_ENABLE=	jack
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
LO_CONFIGURE_ENABLE=	liblo
LO_LIB_DEPENDS=		liblo.so:${PORTSDIR}/audio/liblo
OIL_CONFIGURE_ENABLE=	liboil
OIL_LIB_DEPENDS=	liboil-0.3.so:${PORTSDIR}/devel/liboil
PYTHON_CONFIGURE_ENABLE=pyecasound
SAMPLERATE_CONFIGURE_ENABLE=	libsamplerate
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
SNDFILE_CONFIGURE_ENABLE=	sndfile
SNDFILE_LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/ s|==|=|g ; \
		 s| $$EXTRAGCCFLAGS||g ; \
		 s| $$EXTRACPPFLAGS||g ; \
		 s| -D_P1003_1B_VISIBLE||' ${WRKSRC}/configure

.include <bsd.port.mk>
