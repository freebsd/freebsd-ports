# New ports collection makefile for:	raine
# Date created:				Jul 22 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	raine
PORTVERSION=	0.43.2
CATEGORIES=	emulators games
MASTER_SITES=	http://www.rainemu.com/html/archive/
DISTNAME=	${PORTNAME}s-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Arcade Emulator for M68000, M68020 and Z80 based hardware

BUILD_DEPENDS=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	alleg.42:${PORTSDIR}/devel/allegro \
		png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_SDL=	sdl
USE_GNOME=	gnomehier
MAKEFILE=	makefile
MAKE_ENV=	PREFIX=${PREFIX}

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s, [$$]_mcpu,,g" ${WRKSRC}/detect-cpu
	@${REINPLACE_CMD} -e "s,sdl-config,${SDL_CONFIG},g" -e "s,/usr/share/,/share/gnome/,g" \
		${WRKSRC}/makefile
	@${REINPLACE_CMD} -e "s,/usr/share/games/raine,${DATADIR},g" \
		${WRKSRC}/source/raine.c
	@${REINPLACE_CMD} -e "s,^#ifdef GFX_SVGA,#ifdef GFX_SVGALIB,g" \
		${WRKSRC}/source/gui/rgui.c \
		${WRKSRC}/source/alleg/display.c \
		${WRKSRC}/source/config.c

.include <bsd.port.post.mk>
