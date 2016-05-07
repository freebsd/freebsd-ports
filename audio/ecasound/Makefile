# Created by: The Anarcat <anarcat@anarcat.dyndns.org>
# $FreeBSD$

PORTNAME=	ecasound
PORTVERSION=	2.9.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://ecasound.seul.org/download/ \
		http://nosignal.fi/download/ \
		http://ecawave.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multitrack audio processing software

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

OPTIONS_DEFINE=	ALSA AUDIOFILE JACK LIBLO LIBOIL PYTHON SAMPLERATE SNDFILE
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

USES=		gmake libtool pkgconfig readline:port
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-liblilv \
		--disable-rubyecasound \
		--enable-sys-readline=no \
		--disable-arts
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

ALSA_CONFIGURE_ENABLE=	alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
AUDIOFILE_CONFIGURE_ENABLE=	audiofile
AUDIOFILE_LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile
JACK_CONFIGURE_ENABLE=	jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack
LIBLO_CONFIGURE_ENABLE=	liblo
LIBLO_LIB_DEPENDS=	liblo.so:audio/liblo
LIBOIL_CONFIGURE_ENABLE=liboil
LIBOIL_LIB_DEPENDS=	liboil-0.3.so:devel/liboil
PYTHON_CONFIGURE_ENABLE=pyecasound
PYTHON_CONFIGURE_ENV=	PYTHONPATH="${PYTHON_CMD}"
PYTHON_USES=		python
SAMPLERATE_CONFIGURE_ENABLE=	libsamplerate
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SNDFILE_CONFIGURE_ENABLE=	sndfile
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile

post-patch:
	@${REINPLACE_CMD} -e '/test/ s|==|=|g ; \
		 s| $$EXTRAGCCFLAGS||g ; \
		 s| $$EXTRACPPFLAGS||g ; \
		 s| -D_P1003_1B_VISIBLE|| ; \
		 s|python -c|$$PYTHONPATH -c|' ${WRKSRC}/configure

.include <bsd.port.mk>
