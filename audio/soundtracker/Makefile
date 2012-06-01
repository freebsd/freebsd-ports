# New ports collection makefile for:   soundtracker
# Date created:        28 November 1999
# Whom:                kzentner
#
# $FreeBSD$
#

PORTNAME=	soundtracker
PORTVERSION=	0.6.8
PORTREVISION=	13
CATEGORIES=	audio gnome
MASTER_SITES=	http://www.soundtracker.org/dl/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mod player/tracking tool which supports XM and MOD formats

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

USE_GNOME=	esound gdkpixbuf gnomehack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	GNOME1 I386_ASM JACK SDL NLS
GNOME1_DESC=	use GNOME 1.x (enables envelope editors)
I386_ASM_DESC=	i386 asm optimizations (potentially unstable)

DESKTOP_ENTRIES="SoundTracker" \
		"Compose music" \
		"soundtracker.xpm" \
		"soundtracker" \
		"" \
		false

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${PORT_OPTIONS:MI386_ASM}
CONFIGURE_ARGS+=	--enable-asm
.endif

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME+=	gnomelibs gnomeprefix
CONFIGURE_ARGS+=	--enable-gnome
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=		jack.0:${PORTSDIR}/audio/jack
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
	${INSTALL_DATA} ${WRKSRC}/sharp.xpm ${PREFIX}/share/pixmaps/soundtracker.xpm

.include <bsd.port.post.mk>
