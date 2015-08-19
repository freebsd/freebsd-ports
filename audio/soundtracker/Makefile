# Created by: Kristopher Zentner <kzentner@u.washington.edu>
# $FreeBSD$

PORTNAME=	soundtracker
PORTVERSION=	0.6.8
PORTREVISION=	16
CATEGORIES=	audio
MASTER_SITES=	http://www.soundtracker.org/dl/v${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mod player/tracking tool which supports XM and MOD formats

LICENSE=	GPLv2

LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig
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

ASM_CONFIGURE_ENABLE=	asm

JACK_LIB_DEPENDS=		libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_ENABLE=	jack

DSL_USE=	SDL=sdl
DSL_CONFIGURE_ENABLE=	sdl

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

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

.include <bsd.port.mk>
