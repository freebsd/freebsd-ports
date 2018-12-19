# Created by: Edward Tomasz Napierala <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	ardour
PORTVERSION=	2.8.16
PORTREVISION=	14
CATEGORIES=	audio
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Multichannel digital audio workstation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto
LIB_DEPENDS=	libaubio.so:audio/aubio \
		libboost_date_time.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgnomecanvasmm-2.6.so:graphics/libgnomecanvasmm26 \
		libjack.so:audio/jack \
		liblo.so:audio/liblo \
		liblrdf.so:textproc/liblrdf \
		libraptor2.so:textproc/raptor2 \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile

USES=		cpe gettext scons pkgconfig tar:bzip2
MAKE_ARGS+=	SYSLIBS=yes PREFIX=${PREFIX} NLS=yes
CFLAGS+=	-I${LOCALBASE}/include -DHAVE_AUBIO4
USE_GNOME=	atk atkmm cairo cairomm gdkpixbuf2 glib20 glibmm gtk20 gtkmm24 \
		libartlgpl2 libgnomecanvas libsigc++20 libxslt pango pangomm

USE_LDCONFIG=	${PREFIX}/lib/ardour2 ${PREFIX}/lib/ardour2/surfaces

PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS VST
VST_DESC=	VST plugins support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVST}
MAKE_ARGS+=	VST=yes
LIB_DEPENDS+=	libwine.so:emulators/wine
PLIST_SUB+=	NO_VST="@comment "
PLIST_SUB+=	VST=""
.else
PLIST_SUB+=	NO_VST=""
PLIST_SUB+=	VST="@comment "
.endif

# Upstream uses these flags by default
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -fomit-frame-pointer -ffast-math -fstrength-reduce
.  if ${ARCH} == "amd64"
MAKE_ARGS+=	DIST_TARGET=x86_64
MAKE_ARGS+=	FPU_OPTIMIZATION=1
.  elif ${MACHINE_CPU:Msse}
MAKE_ARGS+=	DIST_TARGET=i686
MAKE_ARGS+=	FPU_OPTIMIZATION=1
.  else
MAKE_ARGS+=	DIST_TARGET=i386
MAKE_ARGS+=	FPU_OPTIMIZATION=0
.  endif
.else
MAKE_ARGS+=	FPU_OPTIMIZATION=0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS}|' ${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e 's|alsa_pcm|oss|g' ${WRKSRC}/templates/*.template
	@${REINPLACE_CMD} -e 's|std::pair<double|std::pair<const double|' \
		${WRKSRC}/gtk2_ardour/tempo_lines.h
	@${REINPLACE_CMD} -e '/sigc++\/class_slot\.h/d' \
		${WRKSRC}/libs/ardour/audioregion.cc \
		${WRKSRC}/libs/ardour/region.cc
	@${REINPLACE_CMD} -e 's|time_t|& *|' \
		${WRKSRC}/libs/ardour/audiosource.cc
	@${REINPLACE_CMD} -e '/sigc++\/retype\.h/d' \
		${WRKSRC}/libs/ardour/audio_track.cc \
		${WRKSRC}/gtk2_ardour/editor_markers.cc \
		${WRKSRC}/libs/ardour/session.cc \
		${WRKSRC}/libs/ardour/session_transport.cc \
		${WRKSRC}/libs/ardour/track.cc
	@${REINPLACE_CMD} -e '/missing_source = /s,;, != NULL;,' \
		${WRKSRC}/gtk2_ardour/editor_region_list.cc
	@${REINPLACE_CMD} -E 's,(graph_gc|layout) == 0,!&,' \
		${WRKSRC}/gtk2_ardour/fft_graph.cc \
		${WRKSRC}/gtk2_ardour/panner2d.cc
	@${REINPLACE_CMD} -e 's,( *bind,(sigc::bind,' \
		${WRKSRC}/libs/gtkmm2ext/gtk_ui.cc \
		${WRKSRC}/gtk2_ardour/ardour_ui2.cc \
		${WRKSRC}/gtk2_ardour/ardour_ui_ed.cc \
		${WRKSRC}/gtk2_ardour/audio_clock.cc \
		${WRKSRC}/gtk2_ardour/audio_region_editor.cc \
		${WRKSRC}/gtk2_ardour/crossfade_edit.cc \
		${WRKSRC}/gtk2_ardour/editor.cc \
		${WRKSRC}/gtk2_ardour/editor_audio_import.cc \
		${WRKSRC}/gtk2_ardour/editor_canvas.cc \
		${WRKSRC}/gtk2_ardour/editor_markers.cc \
		${WRKSRC}/gtk2_ardour/editor_ops.cc \
		${WRKSRC}/gtk2_ardour/editor_selection.cc \
		${WRKSRC}/gtk2_ardour/editor_tempodisplay.cc \
		${WRKSRC}/gtk2_ardour/generic_pluginui.cc \
		${WRKSRC}/gtk2_ardour/io_selector.cc \
		${WRKSRC}/gtk2_ardour/level_meter.cc \
		${WRKSRC}/gtk2_ardour/mixer_strip.cc \
		${WRKSRC}/gtk2_ardour/mixer_ui.cc \
		${WRKSRC}/gtk2_ardour/option_editor.cc \
		${WRKSRC}/gtk2_ardour/plugin_ui.cc \
		${WRKSRC}/gtk2_ardour/route_time_axis.cc \
		${WRKSRC}/gtk2_ardour/time_axis_view_item.cc

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ardour2/templates
	${INSTALL_DATA} ${WRKSRC}/templates/*.template \
		${STAGEDIR}${PREFIX}/share/ardour2/templates

.include <bsd.port.mk>
