# New ports collection makefile for:	gstreamer plugins
# Date created:		Wed Jul 10 23:38:01 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.4.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-plugins
DISTNAME=	gst-plugins-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	glib-2.0.0:${PORTSDIR}/devel/glib20 \
		gstreamer.0:${PORTSDIR}/graphics/gstreamer \
		popt.0:${PORTSDIR}/devel/popt \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_BZIP2=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests \
		--disable-alsa \
		--disable-cdrom \
		--disable-mjpegtools \
		--disable-qcam \
		--disable-v4l
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		SDL_CONFIG=${SDL_CONFIG} \
		XMMS_CONFIG=${XMMS_CONFIG} \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_TARGET=
INSTALLS_SHLIB=	yes
PLIST_SUB=	LOCALBASE="${LOCALBASE}"

# for esound detection
USE_GNOMENG=	yes
WANT_GNOME=	yes

MAN1=	gst-launch-ext.1 gst-visualise.1

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"
SDL_CONFIG?="${LOCALBASE}/bin/sdl11-config"
XMMS_CONFIG?="${LOCALBASE}/bin/xmms-config"

post-patch:
# as of this writing, FreeBSD does not support lrint* C99 math functions
# do not prefix binary names with anything
	@${REINPLACE_CMD} -E -e \
		's|^#define.*LRINT.*$$||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# use proper dir
	@${REINPLACE_CMD} -E -e \
		's|^(pkgconfigdir).*$$|\1=${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
# remove version number from include dir name
	@${REINPLACE_CMD} -E -e \
		's|-@VERSION@||' \
		${WRKSRC}/gstreamer-libs.pc.in
# remove version number from include dir name
# respect CFLAGS
	@${FIND} ${WRKSRC} -type f -name Makefile.in | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E -e \
		's|^(lib[[:alpha:]]+includedir.+)-@VERSION@|\1|; \
		s,-O(2|3),,; \
		s|-mcpu=i486||'
# gconf is not working in this release
	@${REINPLACE_CMD} -E -e \
		's,^((DIST_SUBDIRS|SUBDIRS).+)gconf,\1,' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/gst-libs/gst/Makefile.in
# mcopidl takes the file as the last argument
	@${REINPLACE_CMD} -E -e \
		's|(mcopidl.+)(\$$<)(.+)$$|\1 \3 \2|' \
		${WRKSRC}/ext/arts/Makefile.in
# no linux/cdrom.h
	@${REINPLACE_CMD} -E -e \
		's|^#include[[:space:]]+.+linux/cdrom\.h.*$$||' \
		${WRKSRC}/ext/dvdread/dvdreadsrc.c
# malloc.h was deprecated in favor of stdlib.h
# inttypes.h not stdint.h
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|malloc.h|stdlib.h|; \
		s|stdint.h|inttypes.h|'

post-install:
# register plugins
	@${LOCALBASE}/bin/gst-register 2>/dev/null

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+= \
	--with-xmms-prefix=${LOCALBASE} \
	--with-xmms-exec-prefix=${LOCALBASE}

#--disable-cdparanoia
#--disable-dv
#--disable-dvdnav
#--disable-dxr3
#--disable-examples
#--disable-gnome_vfs
#--disable-hermes
#--disable-jack
#--disable-ladspa
#--disable-lcs
#--disable-libdvtest
#--disable-raw1394
#--disable-rtp
#--disable-shout
#--disable-sidplay
#--disable-smoothwave
#--disable-tarkin
#--disable-tests
#--disable-vcd
#--disable-vga
#--disable-xmms
#--disable-xvideo

##
## auto detect possible plugins
##

# aalib
.if exists(${LOCALBASE}/lib/libaa.a)
WITH_AALIB=yes
.endif

# arts
.if exists(${LOCALBASE}/lib/libartsc.so.0)
WITH_ARTS=yes
.endif

# avifile
.if exists(${LOCALBASE}/lib/libaviplay.a)
WITH_AVIFILE=yes
.endif

# esound
.if (${HAVE_GNOME:Mesound}!="")
WITH_ESOUND=yes
.endif

# flac
.if exists(${LOCALBASE}/lib/libFLAC.a)
WITH_FLAC=yes
.endif

# lame
.if exists(${LOCALBASE}/lib/libmp3lame.a)
WITH_LAME=yes
.endif

# gsm
.if exists(${LOCALBASE}/lib/libgsm.a)
WITH_GSM=yes
.endif

# jpeg
.if exists(${LOCALBASE}/lib/libjpeg.a)
WITH_JPEG=yes
.endif

# flac
.if exists(${LOCALBASE}/lib/libFLAC.a)
WITH_FLAC=yes
.endif

# liba52
.if exists(${LOCALBASE}/lib/liba52.a)
WITH_LIBA52=yes
.endif

# libaudiofile
.if exists(${LOCALBASE}/lib/libaudiofile.a)
WITH_LIBAUDIOFILE=yes
.endif

# libdvdread
.if exists(${LOCALBASE}/lib/libdvdread.a)
WITH_LIBDVDREAD=yes
.endif

# libfame
.if exists(${LOCALBASE}/lib/libfame.a)
WITH_LIBFAME=yes
.endif

# libmikmod
.if exists(${LOCALBASE}/lib/libmikmod.a)
WITH_LIBMIKMOD=yes
.endif

# libmpeg2
.if exists(${LOCALBASE}/lib/libmpeg2.a)
WITH_LIBMPEG2=yes
.endif

# mad
.if exists(${LOCALBASE}/lib/libmad.a)
WITH_MAD=yes
.endif

# openquicktime
.if exists(${LOCALBASE}/lib/libopenquicktime.so)
WITH_OPENQUICKTIME=yes
.endif

# png
.if exists(${LOCALBASE}/lib/libpng.a)
WITH_PNG=yes
.endif

# sdl
.if exists(${LOCALBASE}/lib/libSDL-1.1.a)
WITH_SDL=yes
.endif

# vorbis
.if exists(${LOCALBASE}/lib/libvorbis.a)
WITH_VORBIS=yes
.endif

##
## control CONFIGURE options
##

# aalib
.ifndef(WITH_AALIB)
CONFIGURE_ARGS+=	--disable-aalib \
			--disable-aalibtest
PLIST_SUB+=	AALIB="@comment "
.else
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib

CONFIGURE_ARGS+=	--with-aalib-prefix=${LOCALBASE}  \
			--with-aalib-exec-prefix=${LOCALBASE}
PLIST_SUB+=	AALIB=""
.endif

# arts
.ifndef(WITH_ARTS)
CONFIGURE_ARGS+=	--disable-arts \
			--disable-artsc \
			--disable-artstest
PLIST_SUB+=	ARTS="@comment "
.else
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts

CONFIGURE_ARGS+=	--with-arts-prefix=${LOCALBASE} \
			--with-arts-exec-prefix=${LOCALBASE}
PLIST_SUB+=	ARTS=""
.endif

# avifile
.ifndef(WITH_AVIFILE)
CONFIGURE_ARGS+=	--disable-avifile
PLIST_SUB+=	AVIFILE="@comment "
.else
LIB_DEPENDS+=	aviplay.0:${PORTSDIR}/graphics/avifile

PLIST_SUB+=	AVIFILE=""
.endif

# esound
.ifndef(WITH_ESOUND)
CONFIGURE_ARGS+=	--disable-esd \
			--disable-esdtest
PLIST_SUB+=	ESOUND="@comment "
.else
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--with-esd-prefix=${LOCALBASE}  \
			--with-esd-exec-prefix=${LOCALBASE}
PLIST_SUB+=	ESOUND=""
.endif

# flac
.ifndef(WITH_FLAC)
CONFIGURE_ARGS+=	--disable-flac
PLIST_SUB+=	FLAC="@comment "
.else
LIB_DEPENDS+=	FLAC.3:${PORTSDIR}/audio/flac

PLIST_SUB+=	FLAC=""
.endif

# gsm
.ifndef(WITH_GSM)
CONFIGURE_ARGS+=	--disable-gsm
PLIST_SUB+=	GSM="@comment "
.else
LIB_DEPENDS+=	gsm.1:${PORTSDIR}/audio/gsm

PLIST_SUB+=	GSM=""
.endif

# http
.ifndef(WITH_HTTP)
CONFIGURE_ARGS+=	--disable-http
PLIST_SUB+=	HTTP="@comment "
.else
PLIST_SUB+=	HTTP=""
.endif

# jpeg
.ifndef(WITH_JPEG)
CONFIGURE_ARGS+=	--disable-jpeg
PLIST_SUB+=	JPEG="@comment "
.else
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg

PLIST_SUB+=	JPEG=""
.endif

# lame
.ifndef(WITH_LAME)
CONFIGURE_ARGS+=	--disable-lame
PLIST_SUB+=	LAME="@comment "
.else
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame

PLIST_SUB+=	LAME=""
.endif

# liba52
.ifndef(WITH_LIBA52)
CONFIGURE_ARGS+=	--disable-a52dec
PLIST_SUB+=	LIBA52="@comment "
.else
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg

CONFIGURE_ARGS+=	--with-a52dec-prefix=${LOCALBASE}
PLIST_SUB+=	LIBA52=""
.endif

# libaudiofile
.ifndef(WITH_LIBAUDIOFILE)
CONFIGURE_ARGS+=	--disable-audiofile
PLIST_SUB+=	LIBAUDIOFILE="@comment "
.else
LIB_DEPENDS+=	audiofile.0:${PORTSDIR}/audio/libaudiofile

PLIST_SUB+=	LIBAUDIOFILE=""
.endif

# libdvdread
.ifndef(WITH_LIBDVDREAD)
CONFIGURE_ARGS+=	--disable-dvdread
PLIST_SUB+=	LIBDVDREAD="@comment "
.else
LIB_DEPENDS+=	dvdread.2:${PORTSDIR}/graphics/libdvdread

PLIST_SUB+=	LIBDVDREAD=""
.endif

# libfame
.ifndef(WITH_LIBFAME)
CONFIGURE_ARGS+=	--disable-libfame \
			--disable-libfametest
PLIST_SUB+=	LIBFAME="@comment "
.else
LIB_DEPENDS+=	fame-0.9.0:${PORTSDIR}/graphics/libfame

CONFIGURE_ARGS+=	--with-libfame-prefix=${LOCALBASE} \
			--with-libfame-exec-prefix=${LOCALBASE}
PLIST_SUB+=	LIBFAME=""
.endif

# libmikmod
.ifndef(WITH_LIBMIKMOD)
CONFIGURE_ARGS+=	--disable-libmikmodtest \
			--disable-mikmod
PLIST_SUB+=	LIBMIKMOD="@comment "
.else
LIB_DEPENDS+=	mikmod.2:${PORTSDIR}/audio/libmikmod

CONFIGURE_ARGS+=	--with-libmikmod-prefix=${LOCALBASE} \
			--with-libmikmod-exec-prefix=${LOCALBASE}
PLIST_SUB+=	LIBMIKMOD=""
.endif

# libmpeg2
.ifndef(WITH_LIBMPEG2)
CONFIGURE_ARGS+=	--disable-mpeg2dec
PLIST_SUB+=	LIBMPEG2="@comment "
.else
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/graphics/libmpeg2

CONFIGURE_ARGS+=	--with-mpeg2dec-prefix=${LOCALBASE}
PLIST_SUB+=	LIBMPEG2=""
.endif

# mad
.ifndef(WITH_MAD)
CONFIGURE_ARGS+=	--disable-mad
PLIST_SUB+=	LIBMAD="@comment "
.else
LIB_DEPENDS+=	mad.1:${PORTSDIR}/audio/mad

PLIST_SUB+=	LIBMAD=""
.endif

# openquicktime
.ifndef(WITH_OPENQUICKTIME)
CONFIGURE_ARGS+=	--disable-openquicktime
PLIST_SUB+=	OPENQUICKTIME="@comment "
.else
LIB_DEPENDS+=	openquicktime.0:${PORTSDIR}/graphics/openquicktime

PLIST_SUB+=	OPENQUICKTIME=""
.endif

# oss
.ifdef(WITHOUT_OSS)
CONFIGURE_ARGS+=	--disable-oss
PLIST_SUB+=	OSS="@comment "
.else
PLIST_SUB+=	OSS=""
.endif

# png
.ifndef(WITH_PNG)
CONFIGURE_ARGS+=	--disable-libpng
PLIST_SUB+=	PNG="@comment "
.else
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png

PLIST_SUB+=	PNG=""
.endif

# sdl
.ifndef(WITH_SDL)
CONFIGURE_ARGS+=	--disable-sdl \
			--disable-sdltest
PLIST_SUB+=	SDL="@comment "
.else
LIB_DEPENDS+=	SDL-1.1.4:${PORTSDIR}/devel/sdl12

CONFIGURE_ARGS+=	--with-sdl-prefix=${LOCALBASE}  \
			--with-sdl-exec-prefix=${LOCALBASE}
PLIST_SUB+=	SDL=""
.endif

# vorbis
.ifndef(WITH_VORBIS)
CONFIGURE_ARGS+=	--disable-vorbis \
			--disable-vorbistest
PLIST_SUB+=	VORBIS="@comment "
.else
LIB_DEPENDS+=	vorbis.2:${PORTSDIR}/audio/libvorbis

PLIST_SUB+=	VORBIS=""
.endif

pre-everything::
.ifndef(WITH_AALIB)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_AALIB to enable aalib Video plugin'
.endif
.ifndef(WITH_ARTS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_ARTS to enable arts Audio plugin'
.endif
.ifndef(WITH_AVIFILE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_AVIFILE to enable avifile Video plugin'
.endif
.ifndef(WITH_ESOUND)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_ESOUND to enable esound Audio plugin'
.endif
.ifndef(WITH_FLAC)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_FLAC to enable flac Audio plugin'
.endif
.ifndef(WITH_GSM)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_GSM to enable gsm Audio plugin'
.endif
.ifndef(WITH_HTTP)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_HTTP to enable http Network plugin'
.endif
.ifndef(WITH_JPEG)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_JPEG to enable jpeg Video plugin'
.endif
.ifndef(WITH_LAME)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LAME to enable lame MP3 Audio plugin'
.endif
.ifndef(WITH_LIBA52)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBA52 to enable liba52 AC3 Audio plugin'
.endif
.ifndef(WITH_LIBAUDIOFILE)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBAUDIOFILE to enable libaudiofile Audio plugin'
.endif
.ifndef(WITH_LIBDVDREAD)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBDVDREAD to enable libdvdread Video plugin'
.endif
.ifndef(WITH_LIBFAME)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBFAME to enable libfame Video plugin'
.endif
.ifndef(WITH_LIBMIKMOD)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBMIKMOD to enable libmikmod Audio plugin'
.endif
.ifndef(WITH_LIBMPEG2)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_LIBMPEG2 to enable libmpeg2 Video plugin'
.endif
.ifndef(WITH_MAD)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_MAD to enable mad Audio plugin'
.endif
.ifndef(WITH_OPENQUICKTIME)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_OPENQUICKTIME to enable openquicktime Video plugin'
.endif
.ifndef(WITHOUT_OSS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITHOUT_OSS to disable OSS Audio plugin'
.endif
.ifndef(WITH_PNG)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_PNG to enable png Video plugin'
.endif
.ifndef(WITH_SDL)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_SDL to enable SDL Video plugin'
.endif
.ifndef(WITH_VORBIS)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_VORBIS to enable vorbis Audio plugin'
.endif

.include <bsd.port.post.mk>
