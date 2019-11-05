# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	gngeo
PORTVERSION=	0.8
DISTVERSIONPREFIX=	${PORTNAME}_
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	LOCAL/acm/${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	NeoGeo emulator

LICENSE=	GPLv2

BROKEN_i386=	unknown argument: '-frerun-loop-opt'

USES=		autoreconf compiler:features gl gmake
USE_SDL=	image sdl
USE_GL=		yes
USE_GITHUB=	yes
GH_ACCOUNT=	pepone42

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
.if ${COMPILER_TYPE} == "clang"
	@${REINPLACE_CMD} -e 's|-frerun-loop-opt||; \
		s|-falign-jumps=2||; s|-falign-loops=2||; \
		s|-fschedule-insns2||; s|-malign-double||; \
		s|-frerun-loop-opt||; s|-O3||' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
		${WRKSRC}/src/generator68k/Makefile.in

pre-configure:
	@cd ${WRKSRC} && ${AUTORECONF} -i

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample_gngeorc ${STAGEDIR}${EXAMPLESDIR}/gngeorc
	${INSTALL_DATA} ${WRKSRC}/romrc ${STAGEDIR}${DATADIR}/romrc
	${INSTALL_DATA} ${WRKSRC}/gngeo.dat/gngeo_data.zip ${STAGEDIR}${DATADIR}/gngeo_data.zip

.include <bsd.port.post.mk>
