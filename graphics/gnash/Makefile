PORTNAME=	gnash
PORTVERSION=	0.8.10
PORTREVISION=	51
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
		libfontconfig.so:x11-fonts/fontconfig \
		libavcodec.so:multimedia/ffmpeg \
		libtheora.so:multimedia/libtheora \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libdca.so:multimedia/libdca \
		libgsm.so:audio/gsm

CONFLICTS=	gnash-devel

USES=		cpe tar:bzip2 compiler:c++11-lang autoreconf gmake libtool \
		pkgconfig jpeg gnome gl sdl desktop-file-utils xorg
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
USE_GNOME=	atk gtk20 libxml2 pango
USE_XORG=	x11 xau xdmcp xext xi xinerama ice sm xv
USE_GL=		egl
USE_SDL=	sdl
SYSCONFIGDIR=	${PREFIX}/etc

# jemalloc leads to infinite recursion on FreeBSD
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/ffmpeg
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-boost-incl="${LOCALBASE}/include" \
		--with-boost-lib="${LOCALBASE}/lib" \
		--with-plugins-install=prefix \
		--sysconfdir="${SYSCONFIGDIR}" \
		--enable-gui=gtk \
		--enable-media=ffmpeg \
		--with-ffmpeg-incl=${LOCALBASE}/include/libavcodec \
		--with-ffmpeg-lib=${LOCALBASE}/lib \
		--disable-testsuite \
		--disable-kparts3 \
		--disable-jemalloc \
		--without-gconf
#MAKE_ARGS+=	INCLUDES="-I${LOCALBASE}/include/ffmpeg"

GNASHVER=	0.8.11dev
CONFIG_FILES=	gnashpluginrc gnashrc

WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_SUB+=	GNASHVER="${GNASHVER}"

USE_LDCONFIG=	${PREFIX}/lib/gnash

OPTIONS_DEFINE=	CYGNAL VAAPI DOCS NLS
OPTIONS_SINGLE=	MEDIA RENDERER
OPTIONS_SINGLE_RENDERER=AGG OPENGL CAIRO
OPTIONS_DEFAULT=AGG VAAPI

NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
CYGNAL_DESC=	Cygnal media server
AGG_DESC=	AGG renderer
OPENGL_DESC=	OpenGL renderer (experimental)
CAIRO_DESC=	Cairo renderer
VAAPI_DESC=	VAAPI support

CYGNAL_CONFIGURE_ENABLE=	cygnal
VAAPI_CPPFLAGS=	-I../libdevice/vaapi

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
LIB_DEPENDS+=		libva.so:multimedia/libva
CONFIGURE_ARGS+=	--enable-device=egl,x11,vaapi
.else
CONFIGURE_ARGS+=	--enable-hwaccel=none # XVideo
CONFIGURE_ARGS+=	--enable-device=egl,x11
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
