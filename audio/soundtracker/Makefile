# Created by: Kristopher Zentner <kzentner@u.washington.edu>
# $FreeBSD$

PORTNAME=	soundtracker
PORTVERSION=	0.6.8
PORTREVISION=	17
CATEGORIES=	audio
MASTER_SITES=	http://www.soundtracker.org/dl/v${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mod player/tracking tool which supports XM and MOD formats

LICENSE=	GPLv2

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

GNU_CONFIGURE=	yes
USES=		compiler pathfix pkgconfig
USE_GNOME=	esound gdkpixbuf

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	JACK SDL NLS
OPTIONS_DEFINE_i386=	ASM
OPTIONS_SUB=	yes
ASM_DESC=	Use optimized assembly (potentially unstable)

CONFIGURE_ARGS+=	--disable-gnome

DESKTOP_ENTRIES="SoundTracker" "Pattern-oriented music editor" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
		"soundtracker" "AudioVideo;Audio;AudioVideoEditing;" false

ASM_CONFIGURE_ON=	--enable-asm

JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CONFIGURE_OFF=	--disable-jack

SDL_USE=		SDL=sdl
SDL_CONFIGURE_OFF=	--disable-sdl

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MASM} && ${CHOSEN_COMPILER_TYPE} == "clang"
CFLAGS+=	-no-integrated-as
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

pre-build-NLS-on:
	cd ${WRKSRC}/po && ${LOCALBASE}/bin/msgfmt -c -o ja.gmo ja.po

post-install:
	${INSTALL_DATA} ${WRKSRC}/sharp.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps/soundtracker.xpm

.include <bsd.port.post.mk>
