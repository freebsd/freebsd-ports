# New ports collection makefile for:	mupen64-base
# Date created:		10.Aug 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES+=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/${PORTVERSION}/
PKGNAMESUFFIX=	-base
DISTNAME=	${PORTNAME}_src-${PORTVERSION}

MAINTAINER?=	tlp@LiquidX.org
COMMENT=	Mupen64 is a Nintendo 64 emulator

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GNOME=	gtk12
WRKSRC=		${WRKDIR}/emu64
USE_GCC=	3.4
ONLY_FOR_ARCHS=	i386

DOCFILES=	readme.pdf readme.ps
FIXME1=		main/vcr.c memory/dma.c r4300/r4300.c r4300/recomp.c \
		r4300/x86/assemble.c
FIXME2=		r4300/interupt.c main/gui_gtk/main_gtk.c

pre-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/mupen64.in \
		> ${WRKDIR}/mupen64
.for i in ${FIXME1}
	${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/${i}
.endfor
.for i in ${FIXME2}
	${REINPLACE_CMD} -e 's|SDL/SDL.h|SDL.h|' ${WRKSRC}/${i}
.endfor
	${REINPLACE_CMD} \
		-e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/configure
	${REINPLACE_CMD} \
		-e 's|gtk-config|${GTK_CONFIG}|' \
		-e 's|-L/usr/X11R6/lib -lSDL -lGL -lpthread|`${SDL_CONFIG} --libs`|' \
		-e 's|-ldl|${LDFLAGS}|' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/whatsnew.txt ${DOCSDIR}/whatsnew.txt
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}/
.endfor
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/mupen64 ${PREFIX}/libexec/mupen64
	${INSTALL_SCRIPT} ${WRKDIR}/mupen64 ${PREFIX}/bin/mupen64
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

CFLAGS+=	`${SDL_CONFIG} --cflags`
CFLAGS+=	-O3 -fomit-frame-pointer -funroll-loops -ffast-math -Wall -pipe
CFLAGS+=	-DX86 -mcpu=athlon

MAKE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.if ${OSVERSION} < 500000
LDFLAGS+=	-L/usr/lib -lcipher
.endif

.include <bsd.port.post.mk>
