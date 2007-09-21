# New ports collection makefile for:	gnash
# Date created:				12 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	gnash
PORTVERSION=	0.8.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	GNU Flash movie player

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		curl.4:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WANT_SDL=	yes
WANT_GNOME=	yes
WANT_GSTREAMER=	yes
USE_GNOME=	pkgconfig libxml2
USE_XLIB=	yes
USE_AUTOTOOLS=	libltdl:15

PLUGIN_DIR=	${PREFIX}/lib/browser_plugins

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS} ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-boost-incl="${LOCALBASE}/include" \
		--with-boost-lib="${LOCALBASE}/lib" \
		--with-plugindir="${PLUGIN_DIR}"

USE_LDCONFIG=	${PREFIX}/lib/gnash

MAN1=		gnash.1

# WITH_KDE option is untested - please uncomment related .if's below
# build gnash -DWITH_KDE -DWITH_PLUGIN. Check whether the plugin works
# and then contact the maintainer: plist and depends should be corrected
OPTIONS=	PLUGIN		"Enable browser plugin" on \
		CYGNAL		"Enable Cygnal media server" off \
		GTK		"GUI: GTK (required for FF plugin)" on \
		AGG		"Renderer: AGG" off \
		OPENGL		"Renderer: OpenGL" on \
		CAIRO		"Renderer: Cairo (experimental)" off \
		FFMPEG		"Media handler: ffmpeg (+SDL sound output)" on \
		GSTREAMER	"Media handler: GStreamer" off \
		MAD		"Media handler: MAD (+SDL sound output)" off  \
		DEBUGLOG	"Leave logfile in current directory on every run" off

#		KDE		"GUI: KDE (required for Konqueror plugin)" off \

.include <bsd.port.pre.mk>

# Plugin option processing
.if defined(WITH_GTK) && !defined(WITHOUT_PLUGIN)
PLIST_SUB+=	FFPLUGIN=""
.else
PLIST_SUB+=	FFPLUGIN="@comment "
CONFIGURE_ARGS+=	--disable-nsapi
.endif

#.if defined(WITH_KDE) && !defined(WITHOUT_PLUGIN)
#PLIST_SUB+=	KONQPLUGIN=""
#.else
#PLIST_SUB+=	KONQPLUGIN="@comment "
CONFIGURE_ARGS+=	--disable-kparts
#.endif

# Cygnal option processing
.if defined(WITH_CYGNAL)
PLIST_SUB+=	CYGNAL=""
CONFIGURE_ARGS+=	--enable-cygnal
.else
PLIST_SUB+=	CYGNAL="@comment "
CONFIGURE_ARGS+=	--disable-cygnal
.endif

# NLS option processing (not sure if --disable-nls actually has any effect)
.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

#
# GUI options processing
#
GNASH_GUIS=

.if defined(WITH_GTK)
USE_GNOME=	gtk20
GNASH_GUIS+=	gtk
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

#.if defined(WITH_KDE)
#GNASH_GUIS+=	kde
#PLIST_SUB+=	KDE=""
#.else
PLIST_SUB+=	KDE="@comment "
#.endif

CONFIGURE_ARGS+=	--enable-gui=`${ECHO} ${GNASH_GUIS} | ${TR} ' ' ,`

#
# Renderer options processing
#
.if defined(WITH_AGG) && !defined(WITH_OPENGL) && !defined(WITH_CAIRO)
LIB_DEPENDS+=		agg.2:${PORTSDIR}/graphics/agg
CONFIGURE_ARGS+=	--enable-renderer=agg
.elif !defined(WITH_AGG) && defined(WITH_OPENGL) && !defined(WITH_CAIRO)
USE_GL=			yes
.	if defined(WITH_GTK)
LIB_DEPENDS+=		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext
.	endif
CONFIGURE_ARGS+=	--enable-renderer=ogl
.elif !defined(WITH_AGG) && !defined(WITH_OPENGL) && defined(WITH_CAIRO)
LIB_DEPENDS+=		cairo.2:${PORTSDIR}/graphics/cairo
CONFIGURE_ARGS+=	--enable-renderer=cairo
.else
IGNORE=			can't be built with multiple or without renderers enabled. Please rerun 'make config' and select exactly one renderer (agg|opengl|cairo)
.endif

#
# Media handler options processing
#
.if defined(WITH_FFMPEG) && !defined(WITH_GSTREAMER) && !defined(WITH_MAD)
LIB_DEPENDS+=		avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-media=ffmpeg
USE_SDL+=		sdl
.elif !defined(WITH_FFMPEG) && defined(WITH_GSTREAMER) && !defined(WITH_MAD)
USE_GSTREAMER=		yes
CONFIGURE_ARGS+=	--enable-media=gst
.elif !defined(WITH_FFMPEG) && !defined(WITH_GSTREAMER) && defined(WITH_MAD)
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
CONFIGURE_ARGS+=	--enable-media=mad
USE_SDL+=		sdl
.elif !defined(WITH_FFMPEG) && !defined(WITH_GSTREAMER) && !defined(WITH_MAD)
CONFIGURE_ARGS+=	--enable-media=none
.else
IGNORE=			can't be built with multiple media handlers enabled. Please rerun 'make config' and leave one or none of them (ffmpeg|gstreamer|mad)
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^PTHREAD_[A-Z]*=/ d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/test/ s|==|=|; s|== x|= x|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; \
		s|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/configure \
		${WRKSRC}/macros/libslist ${WRKSRC}/macros/incllist
.if !defined(WITH_DEBUGLOG)
	@${REINPLACE_CMD} -e 's|gnash-dbg.log|/dev/null|' \
		${WRKSRC}/libbase/rc.cpp ${WRKSRC}/libbase/log.h
.endif

.include <bsd.port.post.mk>
