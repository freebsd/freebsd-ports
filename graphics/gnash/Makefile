# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	gnash
PORTVERSION=	0.8.10
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	GNU/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNU Flash movie player

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libspeex.so:${PORTSDIR}/audio/speex \
		libnspr4.so:${PORTSDIR}/devel/nspr

CONFLICTS=	gnash-devel-[0-9]*

USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
WANT_SDL=	yes
WANT_GNOME=	yes
USE_GCC=	any
WANT_GSTREAMER=	yes
USE_GNOME=	libxml2
USE_XORG=	x11 xau xdmcp xext xi xinerama ice sm xv
INSTALLS_ICONS=	yes
SYSCONFIGDIR=	${PREFIX}/etc

# jemalloc leads to infinite recursion on FreeBSD
CONFIGURE_ARGS=	--with-boost-incl="${LOCALBASE}/include" \
		--with-boost-lib="${LOCALBASE}/lib" \
		--disable-testsuite \
		--with-plugins-install=prefix \
		--sysconfdir="${SYSCONFIGDIR}" \
		--disable-kparts3 \
		--disable-jemalloc \
		--disable-silent-rules

GNASHVER=	${PORTVERSION}
CONFIG_FILES=	gnashpluginrc gnashrc

WRKSRC=		${WRKDIR}/${PORTNAME}-${GNASHVER}
PLIST_SUB+=	GNASHVER="${GNASHVER}"

USE_LDCONFIG=	${PREFIX}/lib/gnash

OPTIONS_DEFINE=	PLUGIN CYGNAL VAAPI
OPTIONS_SINGLE=	MEDIA GUI RENDERER
OPTIONS_SINGLE_MEDIA=	FFMPEG FFMPEG2 GSTREAMER
OPTIONS_SINGLE_GUI=	GTK2 KDE4
OPTIONS_SINGLE_RENDERER=AGG OPENGL CAIRO
OPTIONS_DEFAULT=GTK2 PLUGIN AGG FFMPEG VAAPI

NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
PLUGIN_DESC=	browser plugin
CYGNAL_DESC=	Cygnal media server
AGG_DESC=	AGG renderer
OPENGL_DESC=	OpenGL renderer
CAIRO_DESC=	Cairo renderer (experimental)
FFMPEG_DESC=	ffmpeg0 media handler
FFMPEG2_DESC=	ffmpeg2 media handler (broken)
GSTREAMER_DESC=	GStreamer media handler
VAAPI_DESC=	VAAPI support (requires FFMPEG)

CYGNAL_CONFIGURE_ENABLE=	cygnal

.include <bsd.port.options.mk>

.if ${OSVERSION} > 1000000
BROKEN=	unable to link in libboost_system
.endif

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

#
# Plugin configuration
#
.if ${PORT_OPTIONS:MGTK2} && ${PORT_OPTIONS:MPLUGIN}
USES+=	webplugin:native
WEBPLUGIN_NAME=		gnash
WEBPLUGIN_FILES=	libgnashplugin.so
WEBPLUGIN_DIR=${_WEBPLUGIN_LIBDIR:S,^${LOCALBASE}/,${PREFIX}/,}/${WEBPLUGIN_NAME}
PLIST_SUB+=	NPAPI=""
CONFIGURE_ARGS+=--with-npapi-plugindir="${WEBPLUGIN_DIR}"
BUILD_DEPENDS+=	${LOCALBASE}/bin/xulrunner:${PORTSDIR}/www/libxul
RUN_DEPENDS+=	${LOCALBASE}/bin/xulrunner:${PORTSDIR}/www/libxul
.else
PLIST_SUB+=	NPAPI="@comment "
CONFIGURE_ARGS+=	--disable-npapi
.endif

.if ${PORT_OPTIONS:MKDE4} && ${PORT_OPTIONS:MPLUGIN}
PLIST_SUB+=	KPARTS4=""
USE_LDCONFIG+=	${KDE4_PREFIX}/lib/kde4
CONFIGURE_ARGS+=	--with-kde4_prefix=${PREFIX}/kde4
.else
PLIST_SUB+=	KPARTS4="@comment "
CONFIGURE_ARGS+=	--disable-kparts4
.endif

#
# GUI options processing
#
GNASH_GUIS=

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20 atk gconf2
GNASH_GUIS+=	gtk
.endif

.if ${PORT_OPTIONS:MKDE4}
GNASH_GUIS+=	kde4
USE_QT4=	moc_build
QT_NONSTANDARD=	yes
USE_KDE4=	kdehier kdelibs
CONFIGURE_ENV+=	KDE4_CONFIG="${KDE4_PREFIX}/bin/kde4-config"
.endif

.if ${GNASH_GUIS} == ""
IGNORE=		needs at least one GUI enabled. Please rerun 'make config' and enable GTK or KDE4
.endif

CONFIGURE_ARGS+=--enable-gui=`${ECHO} ${GNASH_GUIS} | ${TR} ' ' ,`

#
# Renderer options processing
#
GNASH_RENDERERS=

.if ${PORT_OPTIONS:MAGG}
LIB_DEPENDS+=		libagg.so:${PORTSDIR}/graphics/agg
GNASH_RENDERERS+=	agg
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=			yes
GNASH_RENDERERS+=	ogl
.if ${PORT_OPTIONS:MGTK2}
LIB_DEPENDS+=		libgdkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext
.endif
.endif

.if ${PORT_OPTIONS:MCAIRO}
.if ${PORT_OPTIONS:MKDE4}
IGNORE=			doesn't support Cairo renderer with KDE4 gui. Please rerun 'make config' and select different renderer or disable KDE4 GUI
.endif
LIB_DEPENDS+=		libcairo.so:${PORTSDIR}/graphics/cairo
GNASH_RENDERERS+=	cairo
.endif

.if ${GNASH_RENDERERS} == ""
IGNORE=			needs at least one renderer enabled. Please rerun 'make config' and enable AGG, OPENGL or CAIRO
.endif

CONFIGURE_ARGS+=	--enable-renderer=`${ECHO} ${GNASH_RENDERERS} | ${TR} ' ' ,`

#
# Hardware acceleration options processing
#
.if ${PORT_OPTIONS:MVAAPI}
.if empty(PORT_OPTIONS:MFFMPEG) && empty(PORT_OPTIONS:MFFMPEG2)
IGNORE=			VAAPI currently works only with FFMPEG. Please rerun 'make config' and enable FFMPEG
.endif
LIB_DEPENDS+=		libva.so:${PORTSDIR}/multimedia/libva
.else
CONFIGURE_ARGS+=	--enable-hwaccel=none # XVideo
.endif

#
# Media handler options processing
#
.if ${PORT_OPTIONS:MFFMPEG2} && empty(PORT_OPTIONS:MFFMPEG) && empty(PORT_OPTIONS:MGSTREAMER)
LIB_DEPENDS+=		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-media=ffmpeg \
			--with-ffmpeg-incl=${LOCALBASE}/include/libavcodec \
			--with-ffmpeg-lib=${LOCALBASE}/lib
USE_SDL+=		sdl
MAKE_ARGS+=		INCLUDES="-I${LOCALBASE}/include/ffmpeg"
.elif ${PORT_OPTIONS:MFFMPEG} && empty(PORT_OPTIONS:MFFMPEG2) && empty(PORT_OPTIONS:MGSTREAMER)
EXTRA_PATCHES+=		${FILESDIR}/ffmpeg0.patch
LIB_DEPENDS+=		libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0
CONFIGURE_ARGS+=	--enable-media=ffmpeg \
			--with-ffmpeg-incl=${LOCALBASE}/include/ffmpeg0/libavcodec \
			--with-ffmpeg-lib=${LOCALBASE}/lib/ffmpeg0
USE_SDL+=		sdl
MAKE_ARGS+=		INCLUDES="-I${LOCALBASE}/include/ffmpeg0"
.elif ${PORT_OPTIONS:MGSTREAMER} && empty(PORT_OPTIONS:MFFMPEG) && empty(PORT_OPTIONS:MFFMPEG2)
USE_GSTREAMER=		yes
CONFIGURE_ARGS+=	--enable-media=gst
USE_SDL+=		sdl
.else
CONFIGURE_ARGS+=	--enable-media=none
IGNORE=			can't be built with multiple media handlers enabled. Please rerun 'make config' and leave one or none of them (ffmpeg|gstreamer)
.endif

.include <bsd.port.pre.mk>

pre-everything::
.if ${PORT_OPTIONS:MOPENGL}
	@${ECHO_CMD} "OpenGL support is currently broken (Gnash hangs using 100% CPU). Use at your own risk"
	@sleep 3
.endif

post-patch:
	${REINPLACE_CMD} -e '/^PTHREAD_[LC][IF]*=/ d; s|-lpthread|${PTHREAD_LIBS}|' \
		-e '/KDE4_APPSDATADIR=/ s|share/kde4|share|' \
		-e 's|/usr/local|${LOCALBASE}|g; \
		s|/lib64|/lib|g; \
		s|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/configure \
		${WRKSRC}/macros/libslist ${WRKSRC}/macros/incllist
	${REINPLACE_CMD} -e '/^pkgconfigdir =/ s|libdir)|exec_prefix)/libdata|' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e '/^man1dir =/ s|=.*|= ${MAN1PREFIX}/man/man1|' \
		${WRKSRC}/doc/C/Makefile.in

post-install:
.for conf in ${CONFIG_FILES}
	${MV} ${STAGEDIR}/${SYSCONFIGDIR}/${conf} ${STAGEDIR}${SYSCONFIGDIR}/${conf}.dist
.endfor
.if ${PORT_OPTIONS:MPLUGIN}
.if ${PORT_OPTIONS:MGTK2}
	cd ${INSTALL_WRKSRC}/plugin && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install-plugin
.endif
.if ${PORT_OPTIONS:MKDE4}
	cd ${INSTALL_WRKSRC}/plugin/klash4 && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install-plugin
.endif
.endif

.include <bsd.port.post.mk>
