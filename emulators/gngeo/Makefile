# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	gngeo
PORTVERSION=	0.7
PORTREVISION=	9
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	NeoGeo emulator

USE_GMAKE=	yes
USE_SDL=	image sdl
USE_GL=		yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name="" --disable-gp2x
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	${CFLAGS} `${SDL_CONFIG} --cflags` -I${LOCALBASE}/include
LDFLAGS+=	`${SDL_CONFIG} --libs` -L${LOCALBASE}/lib
USE_CSTD=	gnu89
MAKE_ARGS+=	CC_FOR_BUILD=${CC}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	GUI
OPTIONS_DEFINE_i386=	ASM RAZE STAR
OPTIONS_DEFAULT_i386=	ASM RAZE STAR
GUI_DESC=	Enable GUI support (experimental)
RAZE_DESC=	Use Raze as z80 emulator
STAR_DESC=	Use Starscream as 68k emulator

MAN1=		gngeo.1

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MI386ASM} || ${PORT_OPTIONS:MRAZE} || \
    ${PORT_OPTIONS:MSTAR}
BUILD_DEPENDS+=		nasm:${PORTSDIR}/devel/nasm
.endif

.if ${PORT_OPTIONS:MGUI}
CONFIGURE_ARGS+=	--enable-gui
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.if ${PORT_OPTIONS:MI386ASM}
CONFIGURE_ARGS+=	--enable-i386asm
.else
CONFIGURE_ARGS+=	--disable-i386asm
.endif

.if ${PORT_OPTIONS:MRAZE}
CONFIGURE_ARGS+=	--enable-raze
.else
CONFIGURE_ARGS+=	--enable-mamez80
.endif

.if ${PORT_OPTIONS:MSTAR}
CONFIGURE_ARGS+=	--enable-starscream
.else
CONFIGURE_ARGS+=	--enable-gen68k
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
		${WRKSRC}/src/generator68k/Makefile.in

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample_gngeorc ${EXAMPLESDIR}/gngeorc
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
