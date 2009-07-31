# New ports collection makefile for:	gngeo
# Date created:				17 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	gngeo
PORTVERSION=	0.7
PORTREVISION=	4
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
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	${CFLAGS} `${SDL_CONFIG} --cflags` -I${LOCALBASE}/include
LDFLAGS=	`${SDL_CONFIG} --libs` -L${LOCALBASE}/lib

SUB_FILES=	pkg-message

OPTIONS=	GUI "Enable GUI support (experimental)" off \
		I386ASM "Use i386 optimization" on \
		RAZE "Use Raze as z80 emulator (only for i386)" on \
		STAR "Use Starscream as 68k emulator (only for i386)" on

MAN1=		gngeo.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_I386ASM) || !defined(WITHOUT_RAZE) || \
    !defined(WITHOUT_STAR)
BUILD_DEPENDS+=		nasm:${PORTSDIR}/devel/nasm
.endif

.if defined(WITH_GUI)
CONFIGURE_ARGS+=	--enable-gui
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.if !defined(WITHOUT_I386ASM) && ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386asm
.else
CONFIGURE_ARGS+=	--disable-i386asm
.endif

.if !defined(WITHOUT_RAZE) && ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-raze
.else
CONFIGURE_ARGS+=	--enable-mamez80
.endif

.if !defined(WITHOUT_STAR) && ${ARCH} == "i386"
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
