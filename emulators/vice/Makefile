# Created by: dchapes@ddm.on.ca
# $FreeBSD$

PORTNAME=	vice
PORTVERSION=	2.4
PORTREVISION=	10
CATEGORIES=	emulators
MASTER_SITES=	http://www.zimmers.net/anonftp/pub/cbm/crossplatform/emulators/VICE/ \
		ftp://ftp.zimmers.net/pub/cbm/crossplatform/emulators/VICE/
PKGNAMESUFFIX?=	${GNOME_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Emulator for Commodore C64, C128, VIC20, PET, and CBM-II

LICENSE=	GPLv2

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontdir:x11-fonts/mkfontdir \
		mkfontscale:x11-fonts/mkfontscale
LIB_DEPENDS=	libpng.so:graphics/png \
		libgif.so:graphics/giflib \
		libmp3lame.so:audio/lame \
		libavcodec.so:multimedia/ffmpeg

RESTRICTED=	ROMs are copyrighted by Commodore Business Machines

USES=		iconv:patch gmake pkgconfig makeinfo
USE_XORG=	xpm ice sm xext xv xt x11 xmu
USE_XORG+=	xrender xinerama xi xrandr xcursor xcomposite xdamage xfixes
GNU_CONFIGURE=	yes
MAKE_ENV+=	MAKEINFOFLAGS="--no-split"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-fullscreen --enable-ipv6 \
			--disable-dependency-tracking
#CONFIGURE_ARGS+=	--enable-ethernet
# libpcap or libnet
#CONFIGURE_ARGS+=	--enable-sdlui
#CONFIGURE_ARGS+=	--enable-gp2x
#CONFIGURE_ARGS+=	--enable-wiz
#CONFIGURE_ARGS+=	--enable-parsid
#CONFIGURE_ARGS+=	--enable-memmap

LMLINKS=	vice.1 x64.1 \
		vice.1 x128.1 \
		vice.1 xvic.1 \
		vice.1 xpet.1 \
		vice.1 xplus4.1 \
		vice.1 xcbm2.1

FIX_XAW=	src/arch/unix/x11/xaw/about.c \
		src/arch/unix/x11/xaw/uicartridge.c \
		src/arch/unix/x11/xaw/uiedisk.c \
		src/arch/unix/x11/xaw/uimenu.c \
		src/arch/unix/x11/xaw/uipalcontrol.c \
		src/arch/unix/x11/xaw/uiscreenshot.c \
		src/arch/unix/x11/xaw/uisnapshot.c \
		src/arch/unix/x11/xaw/uivsidcontrol.c \
		src/arch/unix/x11/xaw/x11ui.c \
		src/arch/unix/x11/xaw/widgets/FileSel.c \
		src/arch/unix/x11/xaw/widgets/FileSelP.h \
		src/arch/unix/x11/xaw/widgets/MultiList.h \
		src/arch/unix/x11/xaw/widgets/MultiListP.h \
		src/arch/unix/x11/xaw/widgets/ScrList.c \

OPTIONS_DEFINE=	SDL ASOUND PULSE DOCS
OPTIONS_SINGLE= GUI
OPTIONS_SINGLE_GUI=	GNOMEUI XAW3D XAW
OPTIONS_DEFAULT?=	GNOMEUI SDL
NO_OPTIONS_SORT=yes
GNOMEUI_DESC=	use gnomeui toolkit
XAW3D_DESC=	use Xaw3d library
XAW_DESC=	use plain Xaw library
SDL_DESC=	build with SDL sound system support
ASOUND_DESC=	build with asound support
PULSE_DESC=	build with pulseaudio support

GNOMEUI_CONFIGURE_ENABLE=	gnomeui
XAW3D_CONFIGURE_WITH=	xaw3d
XAW3D_LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d
SDL_USE=		SDL=sdl
SDL_CONFIGURE_ON=	--with-sdlsound
SDL_CPPFLAGS=		-I${LOCALBASE}/include/SDL
ASOUND_CONFIGURE_OFF=	--without-alsa
ASOUND_LIB_DEPENDS=	libasound.so:audio/alsa-lib
PULSE_CONFIGURE_OFF=	--without-pulse
PULSE_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

.include <bsd.port.options.mk>

.if !defined(BUILDING_INDEX)
__pmlinks1!= ${ECHO_CMD} '${LMLINKS:S/    / /}' | ${AWK} \
	'{ if (NF % 2 != 0) { print "broken"; exit; } \
	for (i=1; i<=NF; i++) { \
		if ( i % 2 == 0) { print " " $$i " ;"; } \
		else { printf "${LN} -s " $$i " "; } \
	} }'
.endif

.if ${PORT_OPTIONS:MXAW3D}
GNOME_SUFFIX=   -xaw3d
CONFLICTS?=     vice-gnome-1.* vice-1.*
.endif

.if ${PORT_OPTIONS:MGNOMEUI}
GNOME_SUFFIX=   -gnome
USE_GNOME=      gtk20 vte
CONFLICTS?=     vice-1.* vice-xaw3d-1.*
.endif

.if ${PORT_OPTIONS:MXAW}
CONFLICTS?=     vice-xaw3d-1.* vice-gnome-1.*
USE_XORG+=      xaw
.endif

.if exists(${LOCALBASE}/bin/fc-cache)
PLIST_SUB+=		FCCACHE=""
PLIST_SUB+=		NOFCCACHE="@comment "
.else
PLIST_SUB+=		FCCACHE="@comment "
PLIST_SUB+=		NOFCCACHE=""
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls --localedir=${LOCALBASE}/share/locale
# causes vice to crash:
#LDFLAGS+=		-lgettextlib
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
INFO+=		vice
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
.endif

post-extract:
	@${RM} ${WRKSRC}/doc/vice.info*

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/man/vice.1
	${REINPLACE_CMD} -e 's|^localedir.*|localedir = $$(DESTDIR)${LOCALBASE}/share/locale|' \
		${WRKSRC}/po/Makefile.in.in
	${REINPLACE_CMD} -e 's|lungif|lgif|g' -e 's|== "x|= "x|' \
		-e 's|"DATADIRNAME"/locale|share/locale|' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|CODEC_ID_|AV_CODEC_ID_|' \
		-e 's|PIX_FMT_|AV_PIX_FMT_|' \
		${WRKSRC}/src/gfxoutputdrv/ffmpegdrv.c
	${REINPLACE_CMD} \
		-e 's|enum PixelFormat|enum AVPixelFormat|g' \
		${WRKSRC}/src/gfxoutputdrv/ffmpeglib.h
.for i in da.po de.po fr.po hu.po it.po nl.po pl.po sv.po tr.po
	${MV} "${WRKSRC}/po/${i}" "${WRKSRC}/po/${i}.latin"
	${ICONV_CMD} -f latin1 -t utf-8 < "${WRKSRC}/po/${i}.latin" > "${WRKSRC}/po/${i}"
.endfor
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's| doc||' ${WRKSRC}/Makefile.in
.endif
.if ${PORT_OPTIONS:MXAW3D}
.for i in ${FIX_XAW}
	${REINPLACE_CMD} -e 's|X11/Xaw/|X11/Xaw3d/|' ${WRKSRC}/${i}
.endfor
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vice/fonts
.if exists(${LOCALBASE}/bin/fc-cache)
	${INSTALL_DATA} ${WRKSRC}/data/fonts/vice-cbm.bdf \
		${STAGEDIR}${PREFIX}/lib/vice/fonts/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.endif

post-install:
	( cd ${STAGEDIR}${PREFIX}/man/man1 && ${__pmlinks1} )
.if ${PORT_OPTIONS:MDOCS}
	${LN} -sf vice_toc.html ${STAGEDIR}${DOCSDIR}/index.html
.endif

.include <bsd.port.mk>
