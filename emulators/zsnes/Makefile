# New ports collection makefile for:	zsnes
# Date created:				Fri May  4 13:10:11 CEST 2001
# Whom:					Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	zsnes
PORTVERSION=	1.36
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	zsnes${PORTVERSION:S/.//}src

MAINTAINER=	stijn@win.tue.nl
COMMENT=	Intel x86 only Super Nintendo Entertainment System (SNES) Emulator

# This must be >= 0.98!
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAN1=		zsnes.1

# non-portable, for a portable version see emulators/snes9x
ONLY_FOR_ARCHS=	i386

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV+=	SDL_CONFIG=${SDL_CONFIG}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

GNU_CONFIGURE=	yes
ALL_TARGET=	ALL

.include <bsd.port.mk>
