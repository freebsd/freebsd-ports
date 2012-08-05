# New ports collection makefile for: liquidsoap
# Date created:                4 Nov 2009
# Whom:                        Mykola Dzham <i@levsha.me>
#
# $FreeBSD$
#

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

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM
.endif

OPTIONS=	AACPLUS		"AAC+ encoding"	On	\
		AO		"portable and stable, but it does only output"	Off \
		CRY		"streaming to icecast and compatible servers"	On	\
		DSSI		"standard for synthesizer plugins (need LADSPA)"	Off	\
		FAAD		"AAC decoding"	On \
		FESTIVAL	"speech synthesis (say)"	On	\
		FLAC		"flac format decoding and encoding" Off	\
		GAVL		"converts from and to many formats"	Off \
		GSTREAMER	"used to provide V4l inputs"	Off \
		JACK		"audio connection kit, designed for low latency"	On \
		LADSPA		"audio plugins providing sound effects"	Off \
		LO		"OSC protocol to have external controls"	Off	\
		MAD		"for MP3 decoding"	On \
		OGG		"ogg/vorbis and ogg/theora encoding and decoding"	On \
		VOAACENC	"AAC encoding"	On	\
		VORBIS		"ogg/vorbis encoding and decoding (need OGG)"	On \
		SCHROEDINGER	"for ogg/dirac encoding and decoding (need OGG)"	Off	\
		SPEEX		"ogg/speex encoding and decoding (need OGG)"	Off \
		THEORA		"ogg/theora encoding and decoding (need OGG)"	Off \
		SAMPLERATE	"for having better quality resampling"	Off \
		SOUNDTOUCH	"for changing pitch and tempo of sound" Off \
		PULSEAUDIO	"cross-platform audio sound server"	Off \
		TAGLIB		"for MP3 ID3 tag reading"	On \
		WGET		"for downloading remote files (http, https, ftp)"	On

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

USE_RC_SUBR=	liquidsoap

USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes

USE_AUTOTOOLS=	autoconf:env automake:env
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
USE_GMAKE=	yes

CONFIGURE_ARGS=	--disable-gui --localstatedir=/var
CFLAGS+=	-I${LOCALBASE}/${OCAML_LIBDIR}

MAKE_ENV+=	OCAMLMKLIB_FLAGS="-L${LOCALBASE}/lib"
.if defined(NOPORTDOCS)
MAKE_ENV+=	PORTDOCS="@: "
.endif
.if defined(NOPORTEXAMPLES)
MAKE_ENV+=	PORTEXAMPLES="@: "
.endif

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

WITH_LAME=	yes

# alsa and portaudio disabled permanently - alsa is linux only, portaudio broken
_ALL_PACKAGES=	aacplus alsa ao cry dssi faad flac gavl gstreamer ladspa lame lo mad ogg vorbis schroedinger speex theora samplerate soundtouch voaacenc portaudio pulseaudio taglib xmlplaylist lastfm

LIB_DEPENDS_aacplus=	aacplus.2:${PORTSDIR}/audio/libaacplus
LIB_DEPENDS_ao=		ao.4:${PORTSDIR}/audio/libao
BUILD_DEPENDS_dssi=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi
LIB_DEPENDS_faad=	faad.2:${PORTSDIR}/audio/faad
LIB_DEPENDS_gavl=	gavl.1:${PORTSDIR}/multimedia/gavl
BUILD_DEPENDS_gstreamer=${LOCALBASE}/lib/ocaml/libcamlidl.a:${PORTSDIR}/lang/ocaml-camlidl
LIB_DEPENDS_gstreamer=	gstreamer-0.10.0:${PORTSDIR}/multimedia/gstreamer \
			gstapp-0.10.0:${PORTSDIR}/multimedia/gstreamer-plugins
BUILD_DEPENDS_ladspa=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS_lame=	mp3lame.0:${PORTSDIR}/audio/lame
LIB_DEPENDS_mad=	mad.2:${PORTSDIR}/audio/libmad
LIB_DEPENDS_ogg=	ogg:${PORTSDIR}/audio/libogg
LIB_DEPENDS_vorbis=	vorbis.4:${PORTSDIR}/audio/libvorbis
LIB_DEPENDS_speex=	speex.1:${PORTSDIR}/audio/speex
LIB_DEPENDS_theora=	theora.0:${PORTSDIR}/multimedia/libtheora
LIB_DEPENDS_samplerate=	samplerate.1:${PORTSDIR}/audio/libsamplerate
LIB_DEPENDS_soundtouch=	SoundTouch.0:${PORTSDIR}/audio/soundtouch bpm:${PORTSDIR}/audio/libbpm
LIB_DEPENDS_portaudio=	portaudio.2:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS_pulseaudio=	pulse.0:${PORTSDIR}/audio/pulseaudio
LIB_DEPENDS_taglib=	tag.1:${PORTSDIR}/audio/taglib
LIB_DEPENDS_voaacenc=	vo-aacenc.0:${PORTSDIR}/audio/vo-aacenc

.if defined(WITH_FESTIVAL)
RUN_DEPENDS+=	${LOCALBASE}/bin/festival:${PORTSDIR}/audio/festival
.endif

.if defined(WITH_WGET)
RUN_DEPENDS+=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget
.endif

.if defined(WITH_VORBIS) && !defined(WITH_OGG)
IGNORE=	ogg required for vorbis. please rerun make config and select ogg
.endif

.if defined(WITH_SPEEX) && !defined(WITH_OGG)
IGNORE=	ogg required for speex. please rerun make config and select ogg
.endif

.if defined(WITH_THEORA) && ( !defined(WITH_OGG) || !defined(WITH_VORBIS) )
IGNORE=	ogg and vorbis required for theora. Please rerun make config and select ogg and vorbis
.endif

.if defined(WITH_LASTFM) && !defined(WITH_XMLPLAYLIST)
IGNORE=	xmlplaylist required for lastfm. please rerun make config and select xmlplaylist
.endif

.if defined(WITH_DSSI) && !defined(WITH_LADSPA)
IGNORE=	ladspa required for dssi. Please rerun make config and select ladspa
.endif

#Server is known as JACK, but module named ocaml-bjack
.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
_DISABLE_SED_ARGS+=	-e "s/^ocaml-bjack/\#ocaml-bjack/"
CONFIGURE_ARGS+=	--disable-bjack
.endif

.for i in ${_ALL_PACKAGES}
.if defined(WITH_${i:U})
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

.if	!defined(NOPORTDOCS)
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
