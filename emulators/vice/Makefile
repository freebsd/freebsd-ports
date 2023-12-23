PORTNAME=	vice
PORTVERSION=	3.7.1
PORTREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	SF/vice-emu/releases

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Emulator for Commodore C64, C128, VIC20, PET, and CBM-II
WWW=		https://vice-emu.sourceforge.io/

LICENSE=	GPLv2 ROM
LICENSE_COMB=	multi
LICENSE_NAME_ROM=	Commodore ROMs
LICENSE_TEXT_ROM=	ROMs are copyrighted by Commodore Business Machines
LICENSE_PERMS_ROM=	auto-accept

BUILD_DEPENDS=	xa65:devel/xa65 \
		xdg-open:devel/xdg-utils
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
		libgnutls.so:security/gnutls \
		libharfbuzz.so:print/harfbuzz

BROKEN_FreeBSD_aarch64=		undeclared function 'inb'

USES=		compiler:c++11-lang pkgconfig perl5 localbase:ldflags \
		gmake iconv:wchar_t jpeg readline gettext xorg
USE_XORG=	xpm ice sm xext xv xt x11 xmu xxf86vm
USE_XORG+=	xrender xinerama xi xrandr xcursor xcomposite xdamage xfixes
HAS_CONFIGURE=	yes
MAKE_ENV+=	XDG_DATA_DIRS=${STAGEDIR}${PREFIX}/share
CFLAGS+=	-fcommon
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--enable-ipv6 \
			--enable-x64 \
			--disable-realdevice \
			--disable-pdf-docs \
			--localedir="${LOCALBASE}/share/locale" \
			--disable-dependency-tracking \
			DOS2UNIX=true

OPTIONS_DEFINE=	SDLSOUND ALSA PULSEAUDIO FFMPEG DOCS
OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=	GTK3UI SDLUI2
OPTIONS_DEFAULT?=	GTK3UI SDLSOUND ALSA
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
GTK3UI_DESC=	use GTK3 user interface
SDLUI2_DESC=	use SDL2 user interface
SDLSOUND_DESC=	build with SDL2 sound system support
FFMPEG_CONFIGURE_ENABLE=	ffmpeg

GTK3UI_USES=			desktop-file-utils
GTK3UI_CONFIGURE_ENABLE=	gtk3ui desktop-files
GTK3UI_BUILD_DEPENDS=		bash:shells/bash
SDLUI2_USES=			sdl
SDLUI2_USE=			SDL=sdl2 SDL=image2
SDLUI2_CONFIGURE_ENABLE=	sdl2ui
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

pre-configure:
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's| doc||' ${WRKSRC}/Makefile.in
.endif

# workaround for xdg-desktop-menu
pre-install-GTK3UI-on:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/desktop-directories

.include <bsd.port.mk>
