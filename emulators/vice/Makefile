# Created by: dchapes@ddm.on.ca
# $FreeBSD$

PORTNAME=	vice
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.zimmers.net/anonftp/pub/cbm/crossplatform/emulators/VICE/ \
		ftp://ftp.zimmers.net/pub/cbm/crossplatform/emulators/VICE/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Emulator for Commodore C64, C128, VIC20, PET, and CBM-II

LICENSE=	GPLv2

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontdir:x11-fonts/mkfontdir \
		mkfontscale:x11-fonts/mkfontscale
LIB_DEPENDS=	libpng.so:graphics/png \
		libgif.so:graphics/giflib \
		libportaudio.so:audio/portaudio \
		libmp3lame.so:audio/lame \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libavcodec.so:multimedia/ffmpeg \
		libFLAC.so:audio/flac \
		libpci.so:devel/libpci \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpcre2-8.so:devel/pcre2 \
		libgnutls.so:security/gnutls

RESTRICTED=	ROMs are copyrighted by Commodore Business Machines

USES=		pkgconfig makeinfo gmake iconv jpeg
USE_XORG=	xpm ice sm xext xv xt x11 xmu xxf86vm
USE_XORG+=	xrender xinerama xi xrandr xcursor xcomposite xdamage xfixes
GNU_CONFIGURE=	yes
MAKE_ENV+=	MAKEINFOFLAGS="--no-split"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--enable-fullscreen --enable-ipv6 \
			--enable-external-ffmpeg \
			--disable-dependency-tracking

LMLINKS=	vice.1 x64.1 \
		vice.1 x128.1 \
		vice.1 xvic.1 \
		vice.1 xpet.1 \
		vice.1 xplus4.1 \
		vice.1 xcbm2.1

OPTIONS_DEFINE=	SDL ALSA PULSEAUDIO DOCS
OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=	GNOMEUI3 GNOMEUI2 XAW
OPTIONS_DEFAULT?=	GNOMEUI3 SDL ALSA
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
GNOMEUI3_DESC=	use gnome3 user interface
GNOMEUI2_DESC=	use gnome2 user interface
XAW_DESC=	use plain Xaw library
SDL_DESC=	build with SDL2 sound system support

GNOMEUI2_CONFIGURE_ENABLE=	gnomeui
GNOMEUI3_CONFIGURE_ENABLE=	gnomeui3
SDL_USE=		SDL=sdl2
SDL_CONFIGURE_ON=	--with-sdlsound
ALSA_CONFIGURE_OFF=	--without-alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
PULSEAUDIO_CONFIGURE_OFF=	--without-pulse
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

.include <bsd.port.options.mk>

.if !defined(BUILDING_INDEX)
__pmlinks1!=	${ECHO_CMD} '${LMLINKS:S/    / /}' | ${AWK} \
	'{ if (NF % 2 != 0) { print "broken"; exit; } \
	for (i=1; i<=NF; i++) { \
		if ( i % 2 == 0) { print " " $$i " ;"; } \
		else { printf "${LN} -s " $$i " "; } \
	} }'
.endif

.if ${PORT_OPTIONS:MGNOMEUI2}
USE_GNOME+=	gtk20 vte cairo gdkpixbuf2 pangox-compat
USE_GL+=	glu gl
LIB_DEPENDS+=	libgdkglext-x11-1.0.so:x11-toolkits/gtkglext
.endif

.if ${PORT_OPTIONS:MGNOMEUI3}
.if ${PORT_OPTIONS:MNLS}
USES+=		gettext-runtime
.endif
USE_GNOME+=	gtk30 vte3 cairo gdkpixbuf2
USE_GL+=	glu gl
.endif

.if ${PORT_OPTIONS:MXAW}
USE_XORG+=	xaw
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls --localedir=${LOCALBASE}/share/locale
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
INFO+=		vice
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl2
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's|enum PixelFormat|enum AVPixelFormat|g' \
		${WRKSRC}/src/gfxoutputdrv/ffmpeglib.h
.for i in da.po de.po es.po fr.po hu.po it.po nl.po pl.po sv.po tr.po
	${MV} "${WRKSRC}/po/${i}" "${WRKSRC}/po/${i}.latin"
	${ICONV_CMD} -f latin1 -t utf-8 < "${WRKSRC}/po/${i}.latin" > "${WRKSRC}/po/${i}"
.endfor

pre-configure:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/man/vice.1
	${REINPLACE_CMD} -e 's|^localedir.*|localedir = $$(DESTDIR)${LOCALBASE}/share/locale|' \
		${WRKSRC}/po/Makefile.in.in
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's| doc||' ${WRKSRC}/Makefile.in
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vice/fonts
	${INSTALL_DATA} ${WRKSRC}/data/fonts/vice-cbm.bdf \
		${STAGEDIR}${PREFIX}/lib/vice/fonts/

pre-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install:
	( cd ${STAGEDIR}${PREFIX}/man/man1 && ${__pmlinks1} )

post-install-DOCS-on:
	${LN} -sf vice_toc.html ${STAGEDIR}${DOCSDIR}/index.html

.include <bsd.port.mk>
