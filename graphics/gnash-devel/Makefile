# New ports collection makefile for:	gnash
# Date created:				12 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	gnash
PORTVERSION=	20081208
PORTREVISION=	3
CATEGORIES=	graphics
# gnashdev.org is slower
MASTER_SITES=	http://mirror.amdmi3.ru/ \
		http://www.gnashdev.org/dev_snapshots/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-trunk-${REVISION}
EXTRACT_SUFX=	.tar.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GNU Flash movie player

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		curl.5:${PORTSDIR}/ftp/curl \
		ungif.5:${PORTSDIR}/graphics/libungif

CONFLICTS=	gnash-[0-9]*

IGNORE=		please use graphics/gnash instead, it is currently newer

REVISION=	10395

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WANT_SDL=	yes
WANT_GNOME=	yes
USE_GCC=	4.2+	# triggers compiler error on gcc 3.4
WANT_GSTREAMER=	yes
USE_GNOME=	pkgconfig libxml2
USE_XORG=	x11 xau xdmcp xext xi xinerama ice sm
USE_AUTOTOOLS=	libltdl:15 libtool:15:env
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS} ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-boost-incl="${LOCALBASE}/include" \
		--with-boost-lib="${LOCALBASE}/lib" \
		--with-npapi-plugindir="${WEBPLUGINS_DIR}" \
		--with-kde-pluginprefix="${PREFIX}"

GNASHVER=	trunk

WRKSRC=		${WRKDIR}/${PORTNAME}-${GNASHVER}
PLIST_SUB+=	GNASHVER="${GNASHVER}"

USE_LDCONFIG=	${PREFIX}/lib/gnash

MAN1=		cygnal.1 dumpshm.1 flvdumper.1 gnash.1 gprocessor.1 soldumper.1

OPTIONS=	PLUGIN		"Enable browser plugin" on \
		CYGNAL		"Enable Cygnal media server" off \
		GTK		"GUI: GTK (required for Mozilla/Firefox plugin)" on \
		KDE		"GUI: KDE (required for Konqueror plugin)" off \
		AGG		"Renderer: AGG" on \
		OPENGL		"Renderer: OpenGL (broken)" off \
		CAIRO		"Renderer: Cairo (experimental)" off \
		FFMPEG		"Media handler: ffmpeg (+SDL sound output)" on \
		GSTREAMER	"Media handler: GStreamer" off \
		SPEEX		"Speex codec support" on

.include <bsd.port.pre.mk>

# Plugin option processing
.if !defined(WITHOUT_GTK) && !defined(WITHOUT_PLUGIN)
USE_WEBPLUGINS=		native
WEBPLUGINS_FILES=	libgnashplugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
PLIST_SUB+=	FFPLUGIN=""
.else
PLIST_SUB+=	FFPLUGIN="@comment "
CONFIGURE_ARGS+=	--disable-nsapi
.endif

.if defined(WITH_KDE) && !defined(WITHOUT_PLUGIN)
PLIST_SUB+=	KONQPLUGIN=""
USE_LDCONFIG+=	${PREFIX}/lib/kde3
.else
PLIST_SUB+=	KONQPLUGIN="@comment "
CONFIGURE_ARGS+=	--disable-kparts
.endif

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

.if !defined(WITHOUT_GTK)
USE_GNOME=	gtk20
GNASH_GUIS+=	gtk
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

.if defined(WITH_KDE)
GNASH_GUIS+=	kde
PLIST_SUB+=	KDE=""
# We have to use this lame way to depend on kdelibs, as USE_KDELIBS_VER won't
# work after bsd.port.pre.mk, and bsd.port.options.mk is unavailable until
# 5.5/6.2 EOL. We could also include bsd.kde.mk here, but that's much more
# likely to bring more trouble
LIB_DEPENDS+=	kimproxy:${PORTSDIR}/x11/kdelibs3
.else
PLIST_SUB+=	KDE="@comment "
.endif

.if ${GNASH_GUIS} == ""
IGNORE=		needs at least one GUI enabled. Please rerun 'make config' and enable GTK, KDE or both GUIs
.endif

CONFIGURE_ARGS+=	--enable-gui=`${ECHO} ${GNASH_GUIS} | ${TR} ' ' ,`

#
# Renderer options processing
#
.if defined(WITH_AGG) && !defined(WITH_OPENGL) && !defined(WITH_CAIRO)
LIB_DEPENDS+=		agg.2:${PORTSDIR}/graphics/agg
CONFIGURE_ARGS+=	--enable-renderer=agg
.elif !defined(WITH_AGG) && defined(WITH_OPENGL) && !defined(WITH_CAIRO)
USE_GL=			yes
.	if !defined(WITHOUT_GTK)
LIB_DEPENDS+=		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext
.	endif
CONFIGURE_ARGS+=	--enable-renderer=ogl
.elif !defined(WITH_AGG) && !defined(WITH_OPENGL) && defined(WITH_CAIRO)
.	if defined(WITH_KDE)
IGNORE=			doesn't support Cairo renderer with KDE gui. Please rerun 'make config' and select different renderer or disable KDE GUI
.	endif
LIB_DEPENDS+=		cairo.2:${PORTSDIR}/graphics/cairo
CONFIGURE_ARGS+=	--enable-renderer=cairo
.else
IGNORE=			can't be built with multiple or without renderers enabled. Please rerun 'make config' and select exactly one renderer (agg|opengl|cairo)
.endif

#
# Media handler options processing
#
.if defined(WITH_FFMPEG) && !defined(WITH_GSTREAMER)
LIB_DEPENDS+=		avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-media=ffmpeg \
			--with-ffmpeg-incl=${LOCALBASE}/include/ffmpeg
USE_SDL+=		sdl
.elif !defined(WITH_FFMPEG) && defined(WITH_GSTREAMER)
USE_GSTREAMER=		yes
CONFIGURE_ARGS+=	--enable-media=gst
USE_SDL+=		sdl
.elif !defined(WITH_FFMPEG) && !defined(WITH_GSTREAMER)
CONFIGURE_ARGS+=	--enable-media=none
.else
IGNORE=			can't be built with multiple media handlers enabled. Please rerun 'make config' and leave one or none of them (ffmpeg|gstreamer)
.endif

#
# Other options
#
.if !defined(WITHOUT_SPEEX)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
CONFIGURE_ARGS+=	--enable-speex
.else
CONFIGURE_ARGS+=	--disable-speex
.endif

pre-everything::
.if defined(WITH_OPENGL)
	@${ECHO_CMD} "OpenGL support is currently broken (Gnash hangs using 100% CPU). Use at your own risk"
	@sleep 3
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^PTHREAD_[LC][IF]*=/ d; s|-lpthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; \
		s|/lib64|/lib|g; s|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/configure ${WRKSRC}/macros/libslist \
		${WRKSRC}/macros/incllist
	@${REINPLACE_CMD} -e '/sysconfDATA_INSTALL/ s|/$$$$f|&.dist|' \
		${WRKSRC}/libbase/Makefile.in

post-install:
	if [ ! -f ${PREFIX}/etc/gnashrc ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/gnashrc.dist \
			${PREFIX}/etc/gnashrc; \
	fi
	if [ ! -f ${PREFIX}/etc/gnashpluginrc ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/gnashpluginrc.dist \
			${PREFIX}/etc/gnashpluginrc; \
	fi

.if !defined(WITHOUT_PLUGIN)
.if !defined(WITHOUT_GTK)
	@cd ${INSTALL_WRKSRC}/plugin && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install-plugin
.endif
.if defined(WITH_KDE)
	@cd ${INSTALL_WRKSRC}/plugin/klash && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install-plugin
.endif
.endif

.include <bsd.port.post.mk>
