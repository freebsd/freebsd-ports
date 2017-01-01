# $FreeBSD$

PORTNAME=	mednafen
PORTVERSION=	0.9.38.7
PORTEPOCH=	1
CATEGORIES=	emulators games
MASTER_SITES=	http://mednafen.fobby.net/releases/files/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Portable multi-system emulator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcdio.so:sysutils/libcdio \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis

BROKEN_sparc64=	does not compile due to internal compiler error

GNU_CONFIGURE=	yes
USE_SDL=	sdl net
USE_GL=		gl glu
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=	${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message

CONFIGURE_ARGS+=--disable-alsa --disable-alsatest \
		--with-sdl-prefix=${LOCALBASE}

USES=		compiler:c++11-lib cpe iconv pkgconfig:build tar:bzip2
CPE_VENDOR=	david_shadoff

OPTIONS_DEFINE=	NLS DOCS JACK
OPTIONS_MULTI=	EMU
OPTIONS_MULTI_EMU=	GB GBA LINX MD NES NGP PCE PCFX PSX SMS SWAN VB
OPTIONS_DEFAULT=	GB GBA LINX MD NES NGP PCE PCFX PSX SMS SWAN VB

GB_DESC=	build with GameBoy emulation
GBA_DESC=	build with GameBoy Advance emulation
LINX_DESC=	build with Atari Lynx emulation
MD_DESC=	build with Sega Genesis/MegaDrive emulation
NES_DESC=	build with Nintendo Entertainment System emulation
NGP_DESC=	build with Neo Geo Pocket emulation
PCE_DESC=	build with PC Engine (TurboGrafx 16) emulation
PCFX_DESC=	build with PC-FX emulation
PSX_DESC=	build with Playstation emulation
SMS_DESC=	build with SMS+GG emulation
SWAN_DESC=	build with WonderSWan emulation
VB_DESC=	build with Virtual Boy emulation
JACK_DESC=	support the JACK audio API

OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=nls

JACK_LIB_DEPENDS=libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=jack

GB_CONFIGURE_ENABLE=gb
GBA_CONFIGURE_ENABLE=gba
LINX_CONFIGURE_ENABLE=lynx
MD_CONFIGURE_ENABLE=md
NES_CONFIGURE_ENABLE=nes
NGP_CONFIGURE_ENABLE=ngp
PCE_CONFIGURE_ENABLE=pce
PCFX_CONFIGURE_ENABLE=pcfx
PSX_CONFIGURE_ENABLE=psx
SMS_CONFIGURE_ENABLE=sms
SWAN_CONFIGURE_ENABLE=wswan
VB_CONFIGURE_ENABLE=vb

pre-configure:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|NetBSD|FreeBSD|' \
		${WRKSRC}/include/trio/triodef.h

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Documentation/mednafen.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
