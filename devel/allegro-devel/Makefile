# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	allegro
DISTVERSION=	5.0.9
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	SF/alleg/allegro/${PORTVERSION}
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform library for games and multimedia programming

LICENSE=	ZLIB BSD3CLAUSE
LICENSE_COMB=	dual

LIB_DEPENDS=	libjack.so:audio/jack \
		libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libFLAC.so:audio/flac \
		libphysfs.so:devel/physfs

USES=		cmake:insource compiler:c++11-lang gl gnome jpeg \
		openal:soft pkgconfig xorg
USE_XORG=	x11 xpm xext xcursor xxf86vm xxf86dga
USE_GL=		glu
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

CFLAGS+=	-isystem${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_SUB=	SHLIB_VER="${PORTVERSION}" SHLIB_VER1="${PORTVERSION:R}"

# Wrong versioning upstream
PORTSCOUT=	limitw:1,even skipv:5.0.10

PORTDOCS=	*
PORTEXAMPLES=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=		ALSA DOCS EXAMPLES PULSEAUDIO DEMOS
OPTIONS_DEFAULT=	DEMOS
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	${LOCALBASE}/bin/pandoc:textproc/hs-pandoc
ALSA_LIB_DEPENDS=	libasound.so.2:audio/alsa-lib
ALSA_CMAKE_BOOL=	WANT_ALSA
ALSA_BROKEN=		ALSA support is broken  # confirmed by running demos, leads to assertion at startup
DEMOS_IMPLIES=		EXAMPLES
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WANT_PULSEAUDIO

DEMOS_DESC=		Install demo programs
DEMOS_CMAKE_BOOL=	WANT_DEMO
DEMOS_SUB_FILES=	cosmic_protector speed pkg-message
DEMOS_MASTER_SITES=	SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DEMOS_DISTFILES=	cosmic_protector.png:icons speed.png:icons
DEMOS_DESKTOP_ENTRIES=	"Cosmic Protector" \
			"Protect the earth from a deadly meteor shower" \
			"cosmic_protector" \
			"cosmic_protector" \
			"Game;ArcadeGame;" \
			"" \
			"SPEED" \
			"Simultaneous Projections Employing an Ensemble of Displays" \
			"speed" \
			"speed" \
			"Game;ArcadeGame;" \
			""

post-patch:
	@${REINPLACE_CMD} -e 's|lib$${LIB_SUFFIX}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/addons/audio/pulseaudio.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/* ${STAGEDIR}${MAN3PREFIX}/man/man3/

post-install-DOCS-on:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "README.txt docs/src docs/html" ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.for l in ex_acodec ex_acodec_multi ex_audio_chain ex_audio_props ex_audio_simple \
	ex_bitmap ex_bitmap_flip ex_bitmap_target ex_blend ex_blend2 \
	ex_blend_bench ex_blend_test ex_blit ex_clip ex_color ex_config ex_convert \
	ex_dir ex_disable_screensaver ex_display_events ex_display_options \
	ex_draw ex_draw_bitmap ex_drawpixels ex_dualies ex_expose ex_file_slice \
	ex_filter ex_font ex_font_justify ex_fs_resize ex_fs_window ex_get_path \
	ex_gldepth ex_glext ex_haiku ex_icon ex_icon2 ex_joystick_events \
	ex_joystick_hotplugging ex_kcm_direct ex_keyboard_events ex_keyboard_focus \
	ex_lines ex_lockbitmap ex_logo ex_membmp ex_memfile ex_mixer_chain \
	ex_mixer_pp ex_monitorinfo ex_mouse ex_mouse_cursor ex_mouse_events \
	ex_mouse_focus ex_multisample ex_multiwin ex_native_filechooser ex_nodisplay \
	ex_noframe ex_opengl ex_opengl_pixel_shader ex_path ex_path_test ex_physfs \
	ex_pixelformat ex_premulalpha ex_prim ex_resample_test ex_resize ex_resize2 \
	ex_rotate ex_saw ex_scale ex_stream_file ex_stream_seek ex_subbitmap \
	ex_synth ex_threads ex_threads2 ex_timedwait ex_timer ex_transform ex_ttf \
	ex_user_events ex_utf8 ex_vsync ex_warp_mouse ex_windows ex_winfull
	${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/${l}
.endfor

post-install-DEMOS-on:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_SCRIPT} ${WRKDIR}/cosmic_protector ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${_DISTDIR}/cosmic_protector.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@(cd ${STAGEDIR}${EXAMPLESDIR}/demos/cosmic_protector && ${CHMOD} 755 cosmic_protector)
	${INSTALL_SCRIPT} ${WRKDIR}/speed ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/speed.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	@(cd ${STAGEDIR}${EXAMPLESDIR}/demos/speed && ${CHMOD} 755 speed)
	${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/demos/cosmic_protector/cosmic_protector
	${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/demos/speed/speed

.include <bsd.port.mk>
