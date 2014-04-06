# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	gngeo
PORTVERSION=	0.8
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	NeoGeo emulator

USES=		gmake
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

OPTIONS_DEFINE_i386=	ASM RAZE STAR
OPTIONS_DEFAULT_i386=	ASM RAZE STAR
RAZE_DESC=	Use Raze as z80 emulator
STAR_DESC=	Use Starscream as 68k emulator

MAN1=		gngeo.1
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MI386ASM} || ${PORT_OPTIONS:MRAZE} || \
    ${PORT_OPTIONS:MSTAR}
BUILD_DEPENDS+=		nasm:${PORTSDIR}/devel/nasm
.endif

.if ${PORT_OPTIONS:MI386ASM}
CONFIGURE_ARGS+=	--enable-i386asm
.else
CONFIGURE_ARGS+=	--disable-i386asm
.endif

.if ${PORT_OPTIONS:MRAZE}
CONFIGURE_ARGS+=	--with-z80core=raze
.else
CONFIGURE_ARGS+=	--with-z80core=mamez80
.endif

.if ${PORT_OPTIONS:MSTAR}
CONFIGURE_ARGS+=	--with-m68kcore=starscream
.else
CONFIGURE_ARGS+=	--with-m68kcore=gen68k
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
		${WRKSRC}/src/generator68k/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample_gngeorc ${STAGEDIR}${EXAMPLESDIR}/gngeorc
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>
