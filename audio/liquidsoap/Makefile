# Created by: Mykola Dzham <i@levsha.me>
# $FreeBSD$

PORTNAME=	liquidsoap
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	SF/savonet/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-full

MAINTAINER=	i@levsha.me
COMMENT=	The audio stream generator of the Savonet project

LICENSE=	GPLv2

BUILD_DEPENDS=	${OCAMLFIND_DEPEND} \
		${LOCALBASE}/${OCAML_SITELIBDIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre	\
		${LOCALBASE}/${OCAML_SITELIBDIR}/camomile/camomile.a:${PORTSDIR}/devel/ocaml-camomile

RUN_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/camomile/camomile.a:${PORTSDIR}/devel/ocaml-camomile

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

DOCS_BUILD_DEPENDS=	p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM

OPTIONS_DEFINE=	AACPLUS AO CRY DOCS DSSI FAAD FESTIVAL FLAC GAVL GSTREAMER JACK LADSPA LO \
		MAD OGG VOAACENC VORBIS SCHROEDINGER SPEEX THEORA SAMPLERATE PULSEAUDIO \
		TAGLIB WGET DOCS EXAMPLES
OPTIONS_DEFAULT=	AACPLUS CRY FAAD FESTIVAL JACK MAD OGG VOAACENC VORBIS TAGLIB WGET
AACPLUS_DESC=		AAC+ encoding
AO_DESC=		portable and stable, but it does only output
CRY_DESC=		streaming to icecast and compatible servers
DSSI_DESC=		standard for synthesizer plugins (need LADSPA)
FESTIVAL_DESC=		speech synthesis (say)
GAVL_DESC=		converts from and to many formats
GSTREAMER_DESC=		used to provide V4l inputs
JACK_DESC=		audio connection kit, designed for low latency
LADSPA_DESC=		audio plugins providing sound effects
LO_DESC=		OSC protocol to have external controls
OGG_DESC=		ogg/vorbis and ogg/theora encoding and decoding
VOAACENC_DESC=		AAC encoding
VORBIS_DESC=		ogg/vorbis encoding and decoding (need OGG)
SCHROEDINGER_DESC=	ogg/dirac encoding and decoding (need OGG)
SPEEX_DESC=		ogg/speex encoding and decoding (need OGG)
THEORA_DESC=		ogg/theora encoding and decoding (need OGG)
SAMPLERATE_DESC=	for having better quality resampling
SOUNDTOUCH_DESC=	for changing pitch and tempo of sound
TAGLIB_DESC=		for MP3 ID3 tag reading
WGET_DESC=		for downloading remote files (http, https, ftp)

# xmplapalylist disabled now: missing ocaml-xmlm port
#		XMLPLAYLIST	"support various xml format (rss/podcast/etc)"	Off \
# lastfm requires xmlplaylist
#		LASTFM		"radios and the audioscrobbler (need XMLPLAYLIST)"	Off
#		port unbuildable now without lame. Enabled permanently
#		LAME		"for MP3 encoding"	On
#	portuaudio unbuildable now
#		PORTAUDIO	"portable audio library with both input and output"	Off

MAKE_JOBS_UNSAFE=	yes

USE_BZIP2=	yes
NO_STAGE=	yes

USE_RC_SUBR=	liquidsoap

USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes

USE_AUTOTOOLS=	autoconf:env automake:env
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
USES=		gmake pkgconfig

CONFIGURE_ARGS=	--disable-gui --localstatedir=/var
CFLAGS+=	-I${LOCALBASE}/${OCAML_LIBDIR}

MAKE_ENV+=	OCAMLMKLIB_FLAGS="-L${LOCALBASE}/lib"
MAN1=	liquidsoap.1

LIQUIDSOAP_USER=	liquidsoap
LIQUIDSOAP_GROUP=	${LIQUIDSOAP_USER}
USERS=	${LIQUIDSOAP_USER}
GROUPS=	${LIQUIDSOAP_GROUP}
LOGDIR=	/var/log/liquidsoap
PIDDIR=	/var/run/liquidsoap

SUB_LIST=	LIQUIDSOAP_USER=${LIQUIDSOAP_USER} LIQUIDSOAP_GROUP=${LIQUIDSOAP_GROUP} \
	PIDDIR=${PIDDIR}
PLIST_SUB=	RELVER=${PORTVERSION} \
	LIQUIDSOAP_USER=${LIQUIDSOAP_USER} LIQUIDSOAP_GROUP=${LIQUIDSOAP_GROUP} \
	LOGDIR=${LOGDIR} PIDDIR=${PIDDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
MAKE_ENV+=	PORTDOCS="@: "
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
MAKE_ENV+=	PORTEXAMPLES="@: "
.endif

PORT_OPTIONS+=	LAME

# alsa and portaudio disabled permanently - alsa is linux only, portaudio broken
_ALL_PACKAGES=	aacplus alsa ao cry dssi faad flac gavl gstreamer ladspa lame lo mad ogg vorbis schroedinger speex theora samplerate soundtouch voaacenc portaudio pulseaudio taglib xmlplaylist lastfm

LIB_DEPENDS_aacplus=	libaacplus.so:${PORTSDIR}/audio/libaacplus
LIB_DEPENDS_ao=		libao.so:${PORTSDIR}/audio/libao
BUILD_DEPENDS_dssi=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi
LIB_DEPENDS_faad=	libfaad.so:${PORTSDIR}/audio/faad
LIB_DEPENDS_gavl=	libgavl.so:${PORTSDIR}/multimedia/gavl
BUILD_DEPENDS_gstreamer=${LOCALBASE}/lib/ocaml/libcamlidl.a:${PORTSDIR}/lang/ocaml-camlidl
LIB_DEPENDS_gstreamer=	libgstreamer-0.10:${PORTSDIR}/multimedia/gstreamer \
			libgstapp-0.10:${PORTSDIR}/multimedia/gstreamer-plugins
BUILD_DEPENDS_ladspa=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS_lame=	libmp3lame.so:${PORTSDIR}/audio/lame
LIB_DEPENDS_mad=	libmad.so:${PORTSDIR}/audio/libmad
LIB_DEPENDS_ogg=	libogg.so:${PORTSDIR}/audio/libogg
LIB_DEPENDS_vorbis=	libvorbis.so:${PORTSDIR}/audio/libvorbis
LIB_DEPENDS_speex=	libspeex.so:${PORTSDIR}/audio/speex
LIB_DEPENDS_theora=	libtheora.so:${PORTSDIR}/multimedia/libtheora
LIB_DEPENDS_samplerate=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
LIB_DEPENDS_soundtouch=	libSoundTouch.so:${PORTSDIR}/audio/soundtouch bpm:${PORTSDIR}/audio/libbpm
LIB_DEPENDS_portaudio=	libportaudio.so:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS_pulseaudio=	libpulse.so:${PORTSDIR}/audio/pulseaudio
LIB_DEPENDS_taglib=	libtag.so:${PORTSDIR}/audio/taglib
LIB_DEPENDS_voaacenc=	libvo-aacenc.so:${PORTSDIR}/audio/vo-aacenc

.if ${PORT_OPTIONS:MFESTIVAL}
RUN_DEPENDS+=	${LOCALBASE}/bin/festival:${PORTSDIR}/audio/festival
.endif

.if ${PORT_OPTIONS:MWGET}
RUN_DEPENDS+=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget
.endif

.if ${PORT_OPTIONS:MVORBIS} && ! ${PORT_OPTIONS:MDOCS}
IGNORE=	ogg required for vorbis. please rerun make config and select ogg
.endif

.if ${PORT_OPTIONS:MSPEEX} && ! ${PORT_OPTIONS:MOGG}
IGNORE=	ogg required for speex. please rerun make config and select ogg
.endif

.if ${PORT_OPTIONS:MTHEORA} && ( ! ${PORT_OPTIONS:MOGG} || ! ${PORT_OPTIONS:MVORBIS} )
IGNORE=	ogg and vorbis required for theora. Please rerun make config and select ogg and vorbis
.endif

.if ${PORT_OPTIONS:MLASTFM} && ${PORT_OPTIONS:MXMLPLAYLIST}
IGNORE=	xmlplaylist required for lastfm. please rerun make config and select xmlplaylist
.endif

.if ${PORT_OPTIONS:MDSSI} &&  ! ${PORT_OPTIONS:MLADSPA}
IGNORE=	ladspa required for dssi. Please rerun make config and select ladspa
.endif

#Server is known as JACK, but module named ocaml-bjack
.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack
.else
_DISABLE_SED_ARGS+=	-e "s/^ocaml-bjack/\#ocaml-bjack/"
CONFIGURE_ARGS+=	--disable-bjack
.endif

.for i in ${_ALL_PACKAGES}
.if ${PORT_OPTIONS:M${i:U}}
.if defined(LIB_DEPENDS_${i})
LIB_DEPENDS+=	${LIB_DEPENDS_${i}}
.endif
.if defined(BUILD_DEPENDS_${i})
BUILD_DEPENDS+=	${BUILD_DEPENDS_${i}}
.endif
.else
_DISABLE_SED_ARGS+=	-e "s/^ocaml-${i}/\#ocaml-${i}/"
CONFIGURE_ARGS+=	--disable-${i}
.endif
.endfor

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET=	all doc
.endif

post-patch:
	${SED} ${_DISABLE_SED_ARGS} ${WRKSRC}/PACKAGES.default > ${WRKSRC}/PACKAGES

pre-configure:
	(cd ${WRKSRC} && ${GMAKE} bootstrap && ${SED} -i '' -e 's/^RUNNING_USER="$$USER"/RUNNING_USER=liquidsoap/' */configure)

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not install on powerpc: dumps core
.endif

.include <bsd.port.post.mk>
