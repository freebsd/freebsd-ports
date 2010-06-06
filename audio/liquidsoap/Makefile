# New ports collection makefile for: liquidsoap
# Date created:                4 Nov 2009
# Whom:                        Mykola Dzham <i@levsha.me>
#
# $FreeBSD$
#

PORTNAME=	liquidsoap
PORTVERSION=	0.9.2
PORTREVISION?=	2
DISTVERSIONPREFIX=	full-
CATEGORIES=	audio net
MASTER_SITES=	SF/savonet/${PORTNAME}/${PORTVERSION}

MAINTAINER=	i@levsha.me
COMMENT=	The audio stream generator of the Savonet project

BUILD_DEPENDS=	${OCAMLFIND_DEPEND} \
		${LOCALBASE}/${OCAML_SITELIBDIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM
.endif

OPTIONS=	AO		"portable and stable, but it does only output"	Off \
		JACK		"audio connection kit, designed for low latency"	On \
		FAAC		"AAC encoding"	On \
		FAAD		"AAC decoding"	On \
		FESTIVAL	"speech synthesis (say)"	On	\
		GAVL		"converts from and to many formats"	Off \
		LADSPA		"audio plugins providing sound effects"	Off \
		LAME		"for MP3 encoding"	On \
		MAD		"for MP3 decoding"	On \
		OGG		"ogg/vorbis and ogg/theora encoding and decoding"	On \
		VORBIS		"ogg/vorbis encoding and decoding (need OGG)"	On \
		SPEEX		"ogg/speex encoding and decoding (need OGG)"	Off \
		THEORA		"ogg/theora encoding and decoding (need OGG)"	Off \
		SAMPLERATE	"for having better quality resampling"	Off \
		SOUNDTOUCH	"for changing pitch and tempo of sound" Off \
		PULSEAUDIO	"cross-platform audio sound server"	Off \
		TAGLIB		"for MP3 ID3 tag reading"	On \
		WGET	"for downloading remote files (http, https, ftp)"	On

# xmplapalylist disabled now: missing ocaml-xmlm port
#		XMLPLAYLIST	"support various xml format (rss/podcast/etc)"	Off \
# lastfm requires xmlplaylist
#		LASTFM		"radios and the audioscrobbler (need XMLPLAYLIST)"	Off

USE_RC_SUBR=	liquidsoap.sh

USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes

USE_AUTOTOOLS=	autoconf:262:env automake:110:env
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--disable-gui --localstatedir=/var

MAN1=	liquidsoap.1

LIQUIDSOAP_USER=	liquidsoap
LIQUIDSOAP_GROUP=	${LIQUIDSOAP_USER}
UID=	923
GID=	${UID}
LOGDIR=	/var/log/liquidsoap
PIDDIR=	/var/run/liquidsoap

SUB_FILES=	pkg-install
SUB_LIST=	LIQUIDSOAP_USER=${LIQUIDSOAP_USER} LIQUIDSOAP_GROUP=${LIQUIDSOAP_GROUP} UID=${UID} GID=${GID} PIDDIR=${PIDDIR}
PLIST_SUB=	PORTVERSION=${PORTVERSION} LIQUIDSOAP_USER=${LIQUIDSOAP_USER} LIQUIDSOAP_GROUP=${LIQUIDSOAP_GROUP} LOGDIR=${LOGDIR} PIDDIR=${PIDDIR}

.include <bsd.port.options.mk>

# alsa and portaudio disabled permanently - alsa is linux only, portaudio broken
_ALL_PACKAGES=	alsa ao faac faad gavl ladspa lame mad ogg vorbis speex theora samplerate soundtouch portaudio pulseaudio taglib xmlplaylist lastfm

LIB_DEPENDS_ao=	ao.4:${PORTSDIR}/audio/libao
LIB_DEPENDS_faac=	faac.0:${PORTSDIR}/audio/faac
LIB_DEPENDS_faad=	faad.2:${PORTSDIR}/audio/faad
LIB_DEPENDS_gavl=	gavl.1:${PORTSDIR}/multimedia/gavl
BUILD_DEPENDS_ladspa=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS_lame=	mp3lame.0:${PORTSDIR}/audio/lame
LIB_DEPENDS_mad=	mad.2:${PORTSDIR}/audio/libmad
LIB_DEPENDS_ogg=	ogg.7:${PORTSDIR}/audio/libogg
LIB_DEPENDS_vorbis=	vorbis.4:${PORTSDIR}/audio/libvorbis
LIB_DEPENDS_speex=	speex.1:${PORTSDIR}/audio/speex
LIB_DEPENDS_theora=	theora.0:${PORTSDIR}/multimedia/libtheora
LIB_DEPENDS_samplerate=	samplerate.1:${PORTSDIR}/audio/libsamplerate
LIB_DEPENDS_soundtouch=	SoundTouch.0:${PORTSDIR}/audio/soundtouch bpm:${PORTSDIR}/audio/libbpm
LIB_DEPENDS_pulseaudio=	pulse.0:${PORTSDIR}/audio/pulseaudio
LIB_DEPENDS_taglib=	tag.1:${PORTSDIR}/audio/taglib

.if defined(WITH_FESTIVAL)
RUN_DEPENDS+=	${LOCALBASE}/bin/festival:${PORTSDIR}/audio/festival
.endif

.if defined(WITH_WGET)
RUN_DEPENDS+=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget
.endif

.if defined(WITH_VORBIS) && !defined(WITH_OGG)
IGNORE=	OGG required for VORBIS. Please rerun make config and select OGG
.endif

.if defined(WITH_SPEEX) && !defined(WITH_OGG)
IGNORE=	OGG required for SPEEX. Please rerun make config and select OGG
.endif

.if defined(WITH_THEORA) && ( !defined(WITH_OGG) || !defined(WITH_VORBIS) )
IGNORE=	OGG and VORBIS required for THEORA. Please rerun make config and select OGG and VORBIS
.endif

.if defined(WITH_LASTFM) && !defined(WITH_XMLPLAYLIST)
IGNORE=	XMLPLAYLIST required for LASTFM. Please rerun make config and select XMLPLAYLIST
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

post-patch:
	${SED} ${_DISABLE_SED_ARGS} -i '' ${WRKSRC}/PACKAGES

pre-configure:
	(cd ${WRKSRC} && ./bootstrap)

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
