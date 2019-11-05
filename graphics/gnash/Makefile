# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	gnash
PORTVERSION=	0.8.10
PORTREVISION=	44
CATEGORIES=	graphics
MASTER_SITES=	http://git.savannah.gnu.org/cgit/gnash.git/snapshot/
DISTNAME=	gnash-2b3bdede0305c4fc3ad21a0a4197330606c9b880

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNU Flash movie player

LICENSE=	GPLv3

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libnspr4.so:devel/nspr \
		libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libcurl.so:ftp/curl \
		libspeex.so:audio/speex \
		libspeexdsp.so:audio/speexdsp \
		libboost_thread.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

CONFLICTS=	gnash-devel-[0-9]*

USES=		cpe tar:bzip2 compiler:c++11-lang autoreconf gl gmake gnome \
		libtool pkgconfig jpeg gnome gl desktop-file-utils xorg
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
WANT_GSTREAMER=	yes
USE_GNOME=	atk gconf2 gtk20 libxml2 pango
USE_XORG=	x11 xau xdmcp xext xi xinerama ice sm xv
USE_GL=		egl
INSTALLS_ICONS=	yes
SYSCONFIGDIR=	${PREFIX}/etc

# jemalloc leads to infinite recursion on FreeBSD
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-boost-incl="${LOCALBASE}/include" \
		--with-boost-lib="${LOCALBASE}/lib" \
		--with-plugins-install=prefix \
		--sysconfdir="${SYSCONFIGDIR}" \
		--enable-gui=gtk \
		--disable-testsuite \
		--disable-kparts3 \
		--disable-jemalloc

GNASHVER=	0.8.11dev
CONFIG_FILES=	gnashpluginrc gnashrc

WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_SUB+=	GNASHVER="${GNASHVER}"

USE_LDCONFIG=	${PREFIX}/lib/gnash

OPTIONS_DEFINE=	CYGNAL VAAPI DOCS NLS
OPTIONS_SINGLE=	MEDIA RENDERER
OPTIONS_SINGLE_MEDIA=	FFMPEG GSTREAMER
OPTIONS_SINGLE_RENDERER=AGG OPENGL CAIRO
OPTIONS_DEFAULT=AGG FFMPEG VAAPI

NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
CYGNAL_DESC=	Cygnal media server
AGG_DESC=	AGG renderer
OPENGL_DESC=	OpenGL renderer (experimental)
CAIRO_DESC=	Cairo renderer
FFMPEG_DESC=	ffmpeg media handler
GSTREAMER_DESC=	GStreamer media handler
VAAPI_DESC=	VAAPI support (requires FFMPEG)

CYGNAL_CONFIGURE_ENABLE=	cygnal

.include <bsd.port.options.mk>

# Cygnal option processing
.if ${PORT_OPTIONS:MCYGNAL}
CONFIG_FILES+=	cygnalrc
.endif

# NLS option processing (not sure if --disable-nls actually has any effect)
.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

CONFIGURE_ARGS+=	--disable-npapi --disable-kparts4

#
# Renderer options processing
#
GNASH_RENDERERS=

.if ${PORT_OPTIONS:MAGG}
LIB_DEPENDS+=		libagg.so:graphics/agg
GNASH_RENDERERS+=	agg
.endif

.if ${PORT_OPTIONS:MOPENGL}
IGNORE=		support for OpenGL is currently broken, use option AGG
GNASH_RENDERERS+=	ogl
LIB_DEPENDS+=		libgdkglext-x11-1.0.so:x11-toolkits/gtkglext
. if ${PORT_OPTIONS:MVAAPI}
LIB_DEPENDS+=		libva-glx.so:multimedia/libva-glx
. endif
.endif

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=		libcairo.so:graphics/cairo
GNASH_RENDERERS+=	cairo
.endif

.if ${GNASH_RENDERERS} == ""
IGNORE=			needs at least one renderer enabled. Please rerun 'make config' and enable AGG, OPENGL or CAIRO
.endif

CONFIGURE_ARGS+=	--enable-renderer=${GNASH_RENDERERS:S/^ //W:S/ /,/gW}

#
# Hardware acceleration options processing
#
.if ${PORT_OPTIONS:MVAAPI}
.if empty(PORT_OPTIONS:MFFMPEG)
IGNORE=			option VAAPI currently works only with FFMPEG. Please rerun 'make config' and enable FFMPEG
.endif
LIB_DEPENDS+=		libva.so:multimedia/libva
CONFIGURE_ARGS+=	--enable-device=egl,x11,vaapi
.else
CONFIGURE_ARGS+=	--enable-hwaccel=none # XVideo
CONFIGURE_ARGS+=	--enable-device=egl,x11
.endif

#
# Media handler options processing
#
.if ${PORT_OPTIONS:MFFMPEG} && empty(PORT_OPTIONS:MGSTREAMER)
LIB_DEPENDS+=		libavcodec.so:multimedia/ffmpeg \
			libtheora.so:multimedia/libtheora \
			libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis
CONFIGURE_ARGS+=	--enable-media=ffmpeg \
			--with-ffmpeg-incl=${LOCALBASE}/include/libavcodec \
			--with-ffmpeg-lib=${LOCALBASE}/lib
USE_SDL+=		sdl
MAKE_ARGS+=		INCLUDES="-I${LOCALBASE}/include/ffmpeg"
.elif ${PORT_OPTIONS:MGSTREAMER} && empty(PORT_OPTIONS:MFFMPEG)
USE_GSTREAMER=		ffmpeg mad vorbis
CONFIGURE_ARGS+=	--enable-media=gst
USE_SDL+=		sdl
.else
CONFIGURE_ARGS+=	--enable-media=none
IGNORE=			can't be built with multiple media handlers enabled. Please rerun 'make config' and leave one or none of them (ffmpeg|gstreamer)
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|lib64|lib|g' -e 's|lib32|lib|g' \
		${WRKSRC}/macros/libslist
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
			-e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/macros/incllist
	${REINPLACE_CMD} -e 's|CODEC_ID_|AV_CODEC_ID_|' \
		${WRKSRC}/libmedia/ffmpeg/VideoDecoderFfmpegVaapi.cpp

post-install:
	# eglinfo conflicts with mesa-demos
	${MV} ${STAGEDIR}/${PREFIX}/bin/eglinfo ${STAGEDIR}/${PREFIX}/bin/eglinfo-gnash
.for conf in ${CONFIG_FILES}
	${MV} ${STAGEDIR}/${SYSCONFIGDIR}/${conf} ${STAGEDIR}${SYSCONFIGDIR}/${conf}.dist
.endfor

.include <bsd.port.post.mk>
