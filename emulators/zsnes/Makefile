# New ports collection makefile for:	zsnes
# Date created:				Fri May  4 13:10:11 CEST 2001
# Whom:					Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	zsnes
PORTVERSION=	1.31b
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	zsnes${PORTVERSION:S/.//}src

MAINTAINER=	stijn@win.tue.nl

# This must be >= 0.98!
BUILD_DEPENDS=	nasm-0.98:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12 \
		png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-q -a

MAN1=		zsnes.1

# non-portable, for a portable version see emulators/snes9x
ONLY_FOR_ARCHS=	i386

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
MAKE_ENV+=	SDL_CONFIG=${SDL_CONFIG} PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/zsnes
BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	makefile.linux
ALL_TARGET=	ALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/zsnes ${PREFIX}/bin/zsnes
	${INSTALL_MAN}	${WRKSRC}/src/linux/zsnes.man ${PREFIX}/man/man1/zsnes.1

.include <bsd.port.mk>
