PORTNAME=	mednafen
DISTVERSION=	1.32.1
PORTEPOCH=	1
PORTREVISION=	2
CATEGORIES=	emulators games
MASTER_SITES=	https://mednafen.github.io/releases/files/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Portable multi-system emulator
WWW=		https://mednafen.github.io

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFLAC.so:audio/flac \
		liblzo2.so:archivers/lzo2 \
		libtrio.so:devel/trio \
		libvorbisfile.so:audio/libvorbis \
		libzstd.so:archivers/zstd

USES=		autoreconf compiler:c++11-lang gettext-tools gl iconv \
		localbase pkgconfig sdl tar:xz
USE_GL=		egl
USE_SDL=	sdl2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-external-libzstd \
			--with-external-lzo \
			--with-external-tremor \
			--with-external-trio

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_DEFAULT=	ALSA APPLE2 GP GPA JACK LYNX MD NES NGP PCE PCFX PSX \
			SMS SNES SS VB WSWAN
OPTIONS_GROUP=		AUDIO
OPTIONS_GROUP_AUDIO=	ALSA JACK
OPTIONS_MULTI=		EMU
OPTIONS_MULTI_EMU=	APPLE2 GP GPA LYNX MD NES NGP PCE PCFX PSX SMS SNES SS \
			VB WSWAN
OPTIONS_SUB=		yes

APPLE2_DESC=	Apple II
GPA_DESC=	GameBoy Advance
GP_DESC=	GameBoy
LYNX_DESC=	Atari Lynx
MD_DESC=	Sega Genesis/Megadrive
NES_DESC=	Nintendo Entertainment System
NGP_DESC=	Neo Geo Pocket
PCE_DESC=	PC Engine/TurboGrafx 16
PCFX_DESC=	PC-FX
PSX_DESC=	Sony PlayStation
SMS_DESC=	Sega Game Gear + Sega Master System
SNES_DESC=	Super Nintendo Entertainment System/Super Famicom
SS_DESC=	Sega Saturn
VB_DESC=	Virtual Boy
WSWAN_DESC=	WonderSwan

ALSA_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=		alsa
ALSA_EXTRA_PATCHES=		${PATCHDIR}/extra-patch-src_drivers_main.cpp

APPLE2_CONFIGURE_ENABLE=	apple2

GPA_CONFIGURE_ENABLE=		gba

GP_CONFIGURE_ENABLE=		gb

JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=		jack

LYNX_CONFIGURE_ENABLE=		lynx

MD_CONFIGURE_ENABLE=		md

NES_CONFIGURE_ENABLE=		nes

NGP_CONFIGURE_ENABLE=		ngp

NLS_USES=			gettext-runtime
NLS_CONFIGURE_ENABLE=		nls

PCE_CONFIGURE_ENABLE=		pce pce-fast

PCFX_CONFIGURE_ENABLE=		pcfx

PSX_CONFIGURE_ENABLE=		psx

SMS_CONFIGURE_ENABLE=		sms

SNES_CONFIGURE_ENABLE=		snes snes-faust

SS_CONFIGURE_ENABLE=		ss

VB_CONFIGURE_ENABLE=		vb

WSWAN_CONFIGURE_ENABLE=		wswan

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README \
		${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} Documentation ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
