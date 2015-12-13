# Created by: Marc van Woerkom <3d@FreeBSD.org>
# $FreeBSD$

PORTNAME=	audacity
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/audacity/audacity/archive/
DISTNAME=	Audacity-${PORTVERSION}

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	GUI editor for digital audio waveforms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

BUILD_DEPENDS+=	autogen:${PORTSDIR}/devel/autogen \
		bash:${PORTSDIR}/shells/bash \
		cmake:${PORTSDIR}/devel/cmake

WRKSRC=		${WRKDIR}/${PORTNAME}-Audacity-${PORTVERSION}

GNU_CONFIGURE=	yes
USES=		compiler:c11 cpe desktop-file-utils gmake pkgconfig shared-mime-info shebangfix dos2unix
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes
USE_WX=		2.8+
WX_COMPS=	wx
INSTALLS_ICONS=	yes
PORTDOCS=	README.txt
INSTALL_TARGET=	install-strip
DOS2UNIX_GLOB=	Makefile.* *.c* *.h

OPTIONS_DEFINE=	NLS DEBUG DOCS FLAC ID3TAG LADSPA LAME MAD MIDI \
		SBSMS SOUNDTOUCH TWOLAME VAMP VORBIS VST
OPTIONS_DEFAULT=	FLAC ID3TAG LADSPA MAD MIDI \
			SBSMS SOUNDTOUCH TWOLAME VAMP VORBIS VST

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	${MACHINE_CPU:tu:MSSE}

DEBUG_DESC=	Enable debug support
LAME_DESC=	Use lame for import and export support
MAD_DESC=	Use libmad for mp2/3 decoding support
MIDI_DESC=	Use portSMF for Midi support
SBSMS_DESC=	Use libsbsms for pitch and tempo changing
SOUNDTOUCH_DESC=	Use libSoundTouch for pitch and tempo changing
TAGLIB_DESC=	Use TagLib for metadata support
TWOLAME_DESC=	Use libtwolame for MP2 export support
VAMP_DESC=	Vamp plug-in support
VST_DESC=	VST plug-in support

CONFIGURE_ENV+=	WX_CONFIG="${WX_CONFIG}"

CONFIGURE_ARGS+=	--with-lib-preference="local system" --without-lv2 --without-ffmpeg \
			--enable-portaudio --enable-unicode --with-libsoxr

CONFIGURE_SHELL?=${LOCALBASE}/bin/bash

DEBUG_CONFIGURE_WITH=	debug

DOCS_BUILD_DEPENDS=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man \
			docbook2man:${PORTSDIR}/textproc/docbook-utils

FLAC_CONFIGURE_WITH=	libflac
FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac

ID3TAG_CONFIGURE_WITH=	libid3tag
ID3TAG_LIB_DEPENDS=	libid3tag.so:${PORTSDIR}/audio/libid3tag

JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack

LADSPA_CONFIGURE_ENABLE=	ladspa
LADSPA_RUN_DEPENDS=	listplugins:${PORTSDIR}/audio/ladspa

MAD_CONFIGURE_WITH=	libmad
MAD_LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad

MIDI_CONFIGURE_WITH=	midi

LAME_CONFIGURE_WITH=	lame
LAME_LIB_DEPENDS=	libmp3lame.so:${PORTSDIR}/audio/lame

SBSMS_CONFIGURE_WITH=	sbsms

SOUNDTOUCH_CONFIGURE_WITH=	soundtouch
SOUNDTOUCH_LIB_DEPENDS=	libSoundTouch.so:${PORTSDIR}/audio/soundtouch

SSE_CONFIGURE_ENABLE=	sse

TWOLAME_CONFIGURE_WITH=	libtwolame
TWOLAME_LIB_DEPENDS=	libtwolame.so:${PORTSDIR}/audio/twolame

VAMP_CONFIGURE_WITH=	libvamp

VORBIS_CONFIGURE_WITH=	libvorbis
VORBIS_LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis

VST_CONFIGURE_ENABLE=	vst

LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
CPPFLAGS+=	-I${WRKSRC}/lib-src/portsmf
CXXFLAGS+=	-I${WRKSRC}/lib-src/portsmf
CFLAGS+=	-I${WRKSRC}/lib-src/portsmf \
		-I${WRKSRC}/lib-src/portaudio-v19/include \
		-I${WRKSRC}/lib-src/lame -I${LOCALBASE}/include

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
