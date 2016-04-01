# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	gngeo
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	GOOGLE_CODE/${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	NeoGeo emulator

USES=		compiler:features gmake
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
OPTIONS_DEFAULT_i386=	ASM
RAZE_DESC=	Use Raze as z80 emulator (broken)
STAR_DESC=	Use Starscream as 68k emulator (broken)

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MI386ASM} || ${PORT_OPTIONS:MRAZE} || \
    ${PORT_OPTIONS:MSTAR}
BUILD_DEPENDS+=		nasm:devel/nasm
.endif

.if ${PORT_OPTIONS:MI386ASM}
CONFIGURE_ARGS+=	--enable-i386asm
.else
CONFIGURE_ARGS+=	--disable-i386asm
.endif

.if ${PORT_OPTIONS:MRAZE}
CONFIGURE_ARGS+=	--with-z80core=raze
BROKEN=			fails to link
.else
CONFIGURE_ARGS+=	--with-z80core=mamez80
.endif

.if ${PORT_OPTIONS:MSTAR}
CONFIGURE_ARGS+=	--with-m68kcore=starscream
BROKEN=			fails to link
.else
CONFIGURE_ARGS+=	--with-m68kcore=gen68k
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|x86_64|amd64|' ${WRKSRC}/configure
.if ${ARCH} == "amd64"
	@${REINPLACE_CMD} -e 's|-malign-double||' ${WRKSRC}/configure
.endif
.if ${COMPILER_TYPE} == "clang"
	@${REINPLACE_CMD} -e 's|-frerun-loop-opt||; \
		s|-falign-jumps=2||; s|-falign-loops=2||; \
		s|-fschedule-insns2||; s|-malign-double||' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
		${WRKSRC}/src/generator68k/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample_gngeorc ${STAGEDIR}${EXAMPLESDIR}/gngeorc

.include <bsd.port.post.mk>
