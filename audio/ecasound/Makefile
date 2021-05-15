# Created by: The Anarcat <anarcat@anarcat.dyndns.org>

PORTNAME=	ecasound
PORTVERSION=	2.9.3
CATEGORIES=	audio
MASTER_SITES=	http://ecasound.seul.org/download/ \
		http://nosignal.fi/download/ \
		http://ecawave.sourceforge.net/download/

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Multitrack audio processing software

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa

USES=		gmake libtool localbase:ldflags ncurses pkgconfig \
		readline shebangfix
SHEBANG_FILES=	ecatools/ecamonitor
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-liblilv \
		--disable-rubyecasound \
		--enable-sys-readline=no \
		--disable-arts

LDFLAGS+=	-pthread

OPTIONS_DEFINE=	ALSA AUDIOFILE JACK LIBLO LIBOIL PYTHON SAMPLERATE SNDFILE
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

ALSA_CONFIGURE_ENABLE=	alsa
# Prevent from linking libasound.so if ALSA disabled.
ALSA_CONFIGURE_ENV_OFF=	ac_cv_search_snd_pcm_open=no
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

post-install-PYTHON-off:
	${RM} -R ${STAGEDIR}${PREFIX}/bin/ecamonitor
	${RM} -R ${STAGEDIR}${MANPREFIX}/man/man1/ecamonitor.1.gz

.include <bsd.port.mk>
