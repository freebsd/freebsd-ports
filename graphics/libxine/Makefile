# New ports collection makefile for:    libxine
# Date created:         14 Oct 2000
# Whom:                 alex
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	0.9.12
CATEGORIES=	graphics
MASTER_SITES=	http://xine.sourceforge.net/files/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	lib
DISTNAME=	${PORTNAME}-lib-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libavcodec.a:${PORTSDIR}/graphics/ffmpeg \
		${LOCALBASE}/lib/libdjbfft.a:${PORTSDIR}/math/djbfft
LIB_DEPENDS=	a52.0:${PORTSDIR}/audio/liba52 \
		aa.1:${PORTSDIR}/graphics/aalib \
		SDL-1.1:${PORTSDIR}/devel/sdl12 \
		intl.2:${PORTSDIR}/devel/gettext \
		iconv.3:${PORTSDIR}/converters/libiconv \
		divxdecore.1:${PORTSDIR}/graphics/libdivxdecore-devel

WRKSRC=		${WRKDIR}/${PORTNAME}-lib-${PORTVERSION}

USE_X_PREFIX=	yes
USE_ESOUND=	yes
USE_IMLIB=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
USE_MESA=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		SDL_CONFIG="${LOCALBASE}/bin/sdl11-config" \
		THREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		THREAD_LIBS="${PTHREAD_LIBS}" \
		X_EXTRA_LIBS="-lGL -lGLU -lXext -lX11 -lm"
CONFIGURE_ARGS=	--with-w32-path=${LOCALBASE}/lib/win32 \
		--disable-dxr3 --disable-vidix --disable-dha-kmod \
		--disable-alsa
INSTALLS_SHLIB=	yes

MAN1=		xine-config.1
MAN3=		ao_driver_t.3 ao_functions_t.3 autoplay_group.3 \
		audio_cap.3 audio_group.3 audio_prop.3 \
		browse_group.3 build_info.3 cfg_data_t.3 config_group.3 \
		config_values_s.3 config_values_t.3 demux_strategy.3 \
		event_group.3 loadplugins_group.3 mrl_t.3 mrl_types.3 \
		status_group.3 ui_callbacks.3 version_group.3 video_cap.3 \
		video_group.3 video_prop.3 video_ratio.3 visual_types.3 \
		vo_driver_s.3 vo_driver_t.3 vo_frame_t.3 vo_overlay_t.3 \
		xine-lib.3 xine.h.3 xine_api.3 xine_init.3 xine_management.3 \
		xine_t.3 xine_version.3

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} >= 4
PLIST_SUB=	HAVE_LIBXV=""
.else
PLIST_SUB=	HAVE_LIBXV="@comment "
.endif

.if exists(${LOCALBASE}/bin/artsc-config)
PLIST_SUB+=	HAVE_ARTS=""
.else
PLIST_SUB+=	HAVE_ARTS="@comment "
.endif

.if exists(${LOCALBASE}/include/vorbis/codec.h)
LIB_DEPENDS+=	vorbis.1:${PORTSDIR}/audio/libvorbis

PLIST_SUB+=	HAVE_VORBIS=""
.else
PLIST_SUB+=	HAVE_VORBIS="@comment "
.endif

.if exists(${LOCALBASE}/include/ogg/ogg.h)
LIB_DEPENDS+=	ogg.3:${PORTSDIR}/audio/libogg

PLIST_SUB+=	HAVE_OGG=""
.else
PLIST_SUB+=	HAVE_OGG="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -i.bak -e \
		's|THREAD_LIBS=.*$$|THREAD_LIBS="\$$THREAD_LIBS"|g ; \
		 s|THREAD_CFLAGS=.*$$|THREAD_CFLAGS="\$$THREAD_CFLAGS"|g ; \
		 s|-L/usr/local/lib||g ; \
		 s|-I/usr/local/include||g ; \
		 s|-lgiconv|-liconv|g ; \
		 s|-malign-loops|-falign-loops|g ; \
		 s|-malign-jumps|-falign-jumps|g ; \
		 s|-malign-functions|-falign-functions|g ; \
		 s|-funroll-loops||g' ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -i.bak -e \
		's|aclocal,|${ACLOCAL},|g ; \
		 s|autoconf,|${AUTOCONF},|g ; \
		 s|automake,|${AUTOMAKE},|g ; \
		 s|autoheader,|${AUTOHEADER},|g' ${WRKSRC}/aclocal.m4

.include <bsd.port.post.mk>
