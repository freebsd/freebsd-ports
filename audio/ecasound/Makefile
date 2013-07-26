# Created by: The Anarcat <anarcat@anarcat.dyndns.org>
# $FreeBSD$

PORTNAME=	ecasound
PORTVERSION=	2.9.0
CATEGORIES=	audio
MASTER_SITES=	http://ecasound.seul.org/download/ \
		http://eca.cx/download/ \
		http://ecawave.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multitrack audio processing software

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa

OPTIONS_DEFINE=	ALSA AUDIOFILE JACK LO OIL PYTHON SAMPLERATE
OPTIONS_DEFAULT=PYTHON
AUDIOFILE_DESC=	Enable libaudiofile support
LO_DESC=	Enable liblo support
OIL_DESC=	Enable liboil support

USES=		readline
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-liblilv \
		--disable-rubyecasound \
		--enable-sys-readline \
		--disable-arts
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		ecaconvert.1 ecafixdc.1 ecalength.1 ecamonitor.1 \
		ecanormalize.1 ecaplay.1 ecasignalview.1 ecasound.1 \
		ecasound-iam.1 ecatools.1
MAN5=		ecasoundrc.5

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if ${PORT_OPTIONS:MAUDIOFILE}
LIB_DEPENDS+=	audiofile:${PORTSDIR}/audio/libaudiofile
.else
CONFIGURE_ARGS+=	--disable-audiofile
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if ${PORT_OPTIONS:MLO}
LIB_DEPENDS+=	lo:${PORTSDIR}/audio/liblo
.else
CONFIGURE_ARGS+=	--disable-liblo
.endif

.if ${PORT_OPTIONS:MOIL}
LIB_DEPENDS+=	oil-0.3:${PORTSDIR}/devel/liboil
.else
CONFIGURE_ARGS+=	--disable-liboil
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--enable-pyecasound
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=	samplerate:${PORTSDIR}/audio/libsamplerate
.else
CONFIGURE_ARGS+=	--disable-libsamplerate --disable-sndfile
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g ; \
		 s| $$EXTRAGCCFLAGS||g ; \
		 s| $$EXTRACPPFLAGS||g ; \
		 s| -pthread||g ; \
		 s| -D_THREAD_SAFE||g ; \
		 s| -D_P1003_1B_VISIBLE||' ${WRKSRC}/configure

.include <bsd.port.mk>
