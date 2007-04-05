# New ports collection makefile for:	gnash
# Date created:				12 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	gnash
PORTVERSION=	0.7.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	GNU Flash movie player

LIB_DEPENDS=	boost_thread.3:${PORTSDIR}/devel/boost \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		curl.4:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig libxml2
USE_XLIB=	yes

PLUGIN_DIR=	${PREFIX}/lib/browser_plugins

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -Wl,--rpath,${PREFIX}/lib/gnash" \
		CFLAGS="-I${LOCALBASE}/include ${CFLAGS}"

CONFIGURE_ARGS=	--libdir="${PREFIX}/lib/gnash" \
		--with-plugindir=${PLUGIN_DIR} \
		--enable-jpeg --disable-klash

MAN1=		gnash.1

OPTIONS=	PLUGIN	"Enable browser plugin" on \
		GTK	"Enable GTK GUI (required for plugin)"	on \
		SOUND	"Enable sound"	on \
		GSTREAMER	"Use GStreamer sound output instead of SDL"	off \
		MAD	"Support mp3 decoding through libmad"	on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GTK)
USE_SDL+=		sdl
CONFIGURE_ARGS+=	--enable-gui=SDL
.else
CONFIGURE_ARGS+=	--enable-gui=GTK
USE_GNOME+=		atk pango gtk20
LIB_DEPENDS+=		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext
.endif

.if defined(WITHOUT_SOUND)
CONFIGURE_ARGS+=	--enable-sound=NO
.else
.    if defined(WITH_GSTREAMER)
USE_GSTREAMER=		yes
CONFIGURE_ARGS+=	--enable-sound=GST
.    else
USE_SDL+=		sdl
CONFIGURE_ARGS+=	--enable-sound=SDL
.        if defined(WITHOUT_MAD)
CONFIGURE_ARGS+=	--without-mp3-decoder
.        else
CONFIGURE_ARGS+=	--with-mp3-decoder=mad
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
.        endif
.    endif
.endif

.if defined(WITHOUT_PLUGIN) || defined(WITHOUT_GTK)
PLIST_SUB+=	PLUGIN="@comment "
CONFIGURE_ARGS+=	--disable-plugin
.else
PLIST_SUB+=	PLUGIN=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g;s|/usr/X11R6|${X11BASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
