# Created by: Kristopher Zentner <kzentner@u.washington.edu>
# $FreeBSD$

PORTNAME=	soundtracker
PORTVERSION=	0.6.8
PORTREVISION=	13
CATEGORIES=	audio gnome
MASTER_SITES=	http://www.soundtracker.org/dl/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mod player/tracking tool which supports XM and MOD formats

LICENSE=	GPLv2

LIB_DEPENDS=	sndfile:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
USE_GNOME=	esound gdkpixbuf gnomehack

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	GNOME1 JACK SDL NLS
OPTIONS_DEFINE_i386=	ASM
GNOME1_DESC=	Use GNOME 1.x (enables envelope editing)
ASM_DESC=	Use optimized assembly (potentially unstable)

DESKTOP_ENTRIES="SoundTracker" "Pattern-oriented music editor" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
		"soundtracker" "AudioVideo;Audio;AudioVideoEditing;" false

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MASM}
CONFIGURE_ARGS+=	--enable-asm
.endif

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	gnomelibs gnomeprefix
CONFIGURE_ARGS+=	--enable-gnome
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=		jack:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|soundtracker.desktop||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's| install-exec-local||' \
		${WRKSRC}/app/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|PREFIX"/share/soundtracker|DATADIR"|' \
		${WRKSRC}/app/gui.c

pre-build:
.if ${PORT_OPTIONS:MNLS}
	cd ${WRKSRC}/po && ${LOCALBASE}/bin/msgfmt -c -o ja.gmo ja.po
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/sharp.xpm \
		${PREFIX}/share/pixmaps/soundtracker.xpm

.include <bsd.port.post.mk>
