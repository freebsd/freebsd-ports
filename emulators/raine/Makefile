# New ports collection makefile for:	raine
# Date created:				Jul 22 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	raine
PORTVERSION=	0.42.3
CATEGORIES=	emulators games
MASTER_SITES=	http://www.rainemu.com/html/archive/
DISTNAME=	${PORTNAME}s-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Arcade Emulator for M68000, M68020 and Z80 based hardware

BUILD_DEPENDS=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	alleg.41:${PORTSDIR}/devel/allegro

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_SDL=	sdl
MAKEFILE=	makefile
MAKE_ENV=	PREFIX=${PREFIX}

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s, [$$]_mcpu,,g" ${WRKSRC}/detect-cpu
	${REINPLACE_CMD} -e "s,sdl-config,${SDL_CONFIG},g" ${WRKSRC}/makefile
	${REINPLACE_CMD} -e "s,/usr/share/games/raine,${DATADIR},g" ${WRKSRC}/source/raine.c

.include <bsd.port.post.mk>
