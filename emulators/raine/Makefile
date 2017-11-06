# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	raine
PORTVERSION=	0.51.9
PORTREVISION=	6
CATEGORIES=	emulators games
MASTER_SITES=	GENTOO
DISTNAME=	${PORTNAME}s-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Arcade Emulator for M68000, M68020 and Z80 based hardware

LICENSE=	ART10

BROKEN=		fails to link

BUILD_DEPENDS=	nasm>0:devel/nasm
LIB_DEPENDS=	libpng.so:graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake perl5 shebangfix tar:bzip2
SHEBANG_FILES=	makedep
USE_PERL5=	build
USE_SDL=	image ttf sdl
USE_GCC=	any
USE_CSTD=	gnu89
MAKEFILE=	makefile
MAKE_ARGS=	NEO="" VERBOSE=1 HAS_CONSOLE=""

ONLY_FOR_ARCHS=	i386

post-patch:
	@${REINPLACE_CMD} -e \
		's| [$$]_mcpu||g' ${WRKSRC}/detect-cpu
	@${REINPLACE_CMD} -e \
		's|CC=|CC?=| ; \
		 s|CXX=|CXX?=| ; \
		 /LD/s|gcc|$$(CXX)| ; \
		 s|$$(DESTDIR)/usr|$$(DESTDIR)$$(PREFIX)| ; \
		 s|$$(prefix)/games|$$(prefix)/bin| ; \
		 s|$$(prefix)/share/games|$$(prefix)/share| ; \
		 s|-I.*/muParser|-I$${LOCALBASE}/include| ; \
		 s|^CFLAGS =|CFLAGS ?=| ; \
		 s|sdl-config|$${SDL_CONFIG}|g ; \
		 /LFLAGS/s|-g || ; \
		 /LFLAGS/s|-lstdc++|$$(LDFLAGS)|' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		'/^Icon/s|=.*|=${PREFIX}/share/pixmaps/raine.png|' \
		${WRKSRC}/raine.desktop
	@${REINPLACE_CMD} -e \
		's|/usr/share/games/raine|${DATADIR}|' ${WRKSRC}/source/raine.c

post-install:
.for i in artwork emudx roms scripts/raine
	@${ECHO_CMD} -n > ${STAGEDIR}${DATADIR}/${i}/.keep_me
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/raine

.include <bsd.port.mk>
