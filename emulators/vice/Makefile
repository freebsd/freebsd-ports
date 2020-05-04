# Created by: dchapes@ddm.on.ca
# $FreeBSD$

PORTNAME=	vice
PORTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/vice-emu/releases

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Emulator for Commodore C64, C128, VIC20, PET, and CBM-II

LICENSE=	GPLv2

BUILD_DEPENDS=	xa65:devel/xa65
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
USES=		compiler:c++11-lang pkgconfig makeinfo localbase:ldflags \
		gmake iconv:wchar_t jpeg readline gettext xorg
USE_XORG=	xpm ice sm xext xv xt x11 xmu xxf86vm
USE_XORG+=	xrender xinerama xi xrandr xcursor xcomposite xdamage xfixes
HAS_CONFIGURE=	yes
MAKE_ENV+=	MAKEINFOFLAGS="--no-split"
CFLAGS+=	-fcommon
CONFIGURE_ARGS+=	--enable-ipv6 \
			--enable-external-ffmpeg \
			--enable-x64 \
			--disable-realdevice \
			--mandir="${PREFIX}/man" \
			--infodir="${PREFIX}/${INFO_PATH}" \
			--localedir="${LOCALBASE}/share/locale" \
			--disable-dependency-tracking

LMLINKS=	vice.1 x64.1 \
		vice.1 x128.1 \
		vice.1 xvic.1 \
		vice.1 xpet.1 \
		vice.1 xplus4.1 \
		vice.1 xcbm2.1

OPTIONS_DEFINE=	SDLSOUND ALSA PULSEAUDIO DOCS
OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=	GTK3UI SDLUI2
OPTIONS_DEFAULT?=	GTK3UI SDLSOUND ALSA
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
GTK3UI_DESC=	use GTK3 user interface
SDLUI2_DESC=	use SDL2 user interface
SDLSOUND_DESC=	build with SDL2 sound system support

GTK3UI_CONFIGURE_ENABLE=	native-gtk3ui
GTK3UI_BUILD_DEPENDS=		${LOCALBASE}/bin/bash:shells/bash
SDLUI2_USES=			sdl
SDLUI2_USE=			SDL=sdl2
SDLUI2_CONFIGURE_ENABLE=	sdlui2
SDLSOUND_USES=			sdl
SDLSOUND_USE=			SDL=sdl2
SDLSOUND_CONFIGURE_ON=		--with-sdlsound
ALSA_CONFIGURE_OFF=		--without-alsa
ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
PULSEAUDIO_CONFIGURE_OFF=	--without-pulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

.include <bsd.port.options.mk>

.if !defined(BUILDING_INDEX)
__pmlinks1!=	${ECHO_CMD} '${LMLINKS:S/    / /}' | ${AWK} \
	'{ if (NF % 2 != 0) { print "broken"; exit; } \
	for (i=1; i<=NF; i++) { \
		if ( i % 2 == 0) { print " " $$i " ;"; } \
		else { printf "${LN} -s " $$i " "; } \
	} }'
.endif

.if ${PORT_OPTIONS:MGTK3UI}
USES+=		gnome gl
USE_GNOME+=	gtk30 vte3 cairo gdkpixbuf2 pango
USE_GL+=	glu gl glew
.endif

.if ${PORT_OPTIONS:MDOCS}
INFO+=		vice
.endif

pre-configure:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/man/vice.1
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's| doc||' ${WRKSRC}/Makefile.in
.endif

pre-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install:
	( cd ${STAGEDIR}${PREFIX}/man/man1 && ${__pmlinks1} )

post-install-DOCS-on:
	${LN} -sf vice_toc.html ${STAGEDIR}${DOCSDIR}/index.html

.include <bsd.port.mk>
