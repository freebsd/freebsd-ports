# New ports collection makefile for:	audacity-devel
# Date created:				14 Sep 2006
# Whom:					Jackson Low <xxjack12xx@gmail.com>
#
# $FreeBSD$

PORTNAME=	audacity
PORTVERSION=	1.3.14
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE \
		SF/${PORTNAME}/${PORTNAME}-unstable/${PORTVERSION}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-minsrc-${PORTVERSION}-beta

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	Audacity is a GUI editor for digital audio waveforms

LIB_DEPENDS=	jack:${PORTSDIR}/audio/jack \
		sndfile.1:${PORTSDIR}/audio/libsndfile

CONFLICTS=	audacity-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}-beta

USE_AUTOTOOLS=	aclocal autoconf
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_WX=		2.8
WX_UNICODE=	yes
WX_COMPS=	wx
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes
MAN1=		audacity.1
MANCOMPRESSED=	yes

OPTIONS=	FFMPEG		"Use ffmpeg for import and export support" on \
		FLAC		"Use libFLAC for FLAC support" on \
		ID3TAG		"Use libid3tag for mp3 id3 tag support" on \
		LADSPA		"LADSPA plug-in support" on \
		MAD		"Use libmad for mp2/3 decoding support"	on \
		NYQUIST		"Nyquist plug-in support" on \
		PORTMIXER	"Compile with PortMixer" on \
		SAMPLERATE	"Use libresample for sample rate conversion" on \
		SBSMS		"Use libsbsms for pitch and tempo changing" on \
		SOUNDTOUCH 	"Use libSoundTouch for pitch and tempo changing" on\
		TAGLIB		"Use TagLib for metadata support" on \
		TWOLAME		"Use libtwolame for MP2 export support" on \
		VORBIS		"Use libvorbis for Ogg Vorbis support"	on \
		VAMP		"Use libvamp for Vamp plug-in support" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
SSE_CFLAGS=	-mno-sse -mno-sse2
.endif

ACLOCAL_ARGS+=	-I ${WRKSRC}/m4
AUTOCONF_ARGS+=	-I ${WRKSRC}/m4

CONFIGURE_ARG+	=--destdir=/
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${WRKSRC}/lib-src/portsmf -I${WRKSRC}/lib-src/portaudio-v19/include -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}
CXXFLAGS+=	-I${WRKSRC}/lib-src/portsmf -I${WRKSRC}/lib-src/portaudio-v19/include -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}
CFLAGS+=	-I${WRKSRC}/lib-src/portsmf -I${WRKSRC}/lib-src/portaudio-v19/include -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}

CONFIGURE_ENV+=	WX_CONFIG="${WX_CONFIG}"

.if !defined(NOPORTDOCS)
MAKE_ENV=	DOC=yes
.endif

CONFIGURE_ARGS+=	--with-lib-preference="local system"
CONFIGURE_ARGS+=	--with-portaudio
CONFIGURE_ARGS+=	--enable-unicode

.if defined(WITH_FFMPEG)
CONFIGURE_ARGS+=	--with-ffmpeg
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if defined(WITH_FLAC)
CONFIGURE_ARGS+=	--with-libflac
.else
CONFIGURE_ARGS+=	--without-libflac
.endif

.if defined(WITH_ID3TAG)
LIB_DEPENDS+=		id3tag:${PORTSDIR}/audio/libid3tag
CONFIGURE_ARGS+=	--with-libid3tag
.else
CONFIGURE_ARGS+=	--without-libid3tag
.endif

.if defined(WITH_LADSPA)
CONFIGURE_ARGS+=	--enable-ladspa
.else
CONFIGURE_ARGS+=	--disable-ladspa
.endif

.if defined(WITH_MAD)
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=	--with-libmad
.else
CONFIGURE_ARGS+=	--without-libmad
.endif

.if defined(WITH_NYQUIST)
CONFIGURE_ARGS+=	--enable-nyquist
.else
CONFIGURE_ARGS+=	--disable-nyquist
.endif

.if defined(WITH_PORTMIXER)
CONFIGURE_ARGS+=	--with-portmixer
.else
CONFIGURE_ARGS+=	--without-portmixer
.endif

.if defined(WITH_SAMPLERATE)
CONFIGURE_ARGS+=	--with-libresample
.else
CONFIGURE_ARGS+=	--without-libresample
.endif

.if defined(WITH_SBSMS)
CONFIGURE_ARGS+=	--with-sbsms
.else
CONFIGURE_ARGS+=	--without-sbsms
.endif

.if defined(WITH_SOUNDTOUCH)
LIB_DEPENDS+=		SoundTouch:${PORTSDIR}/audio/soundtouch
CONFIGURE_ARGS+=	--with-soundtouch
.else
CONFIGURE_ARGS+=	--without-soundtouch
.endif

.if defined(WITH_TWOLAME)
LIB_DEPENDS+=		twolame:${PORTSDIR}/audio/twolame
CONFIGURE_ARGS+=	--with-libtwolame
.else
CONFIGURE_ARGS+=	--without-libtwolame
.endif

.if defined(WITH_TAGLIB)
LIB_DEPENDS+=		tag:${PORTSDIR}/audio/taglib
CONFIGURE_ARGS+=	--with-taglib
.else
CONFIGURE_ARGS+=	--without-taglib
.endif

.if defined(WITH_VAMP)
CONFIGURE_ARGS+=	--with-libvamp
.else
CONFIGURE_ARGS+=	--without-libvamp
.endif

.if defined(WITH_VORBIS)
CONFIGURE_ARGS+=	--with-libvorbis
.else
CONFIGURE_ARGS+=	--without-libvorbis
.endif

.include <bsd.port.post.mk>
