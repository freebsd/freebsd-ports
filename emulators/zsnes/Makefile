# New ports collection makefile for:	zsnes
# Date created:				Fri May  4 13:10:11 CEST 2001
# Whom:					Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	zsnes
PORTVERSION=	1.20
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	zsnesv${PORTVERSION}src

MAINTAINER=	stijn@win.tue.nl

# This must be >= 0.98!
BUILD_DEPENDS=	nasm-0.98:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12

USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAN1=		zsnes.1

# non-portable, for a portable version see emulators/snes9x
ONLY_FOR_ARCHS=	i386

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
MAKE_ENV+=	SDL_CONFIG=${SDL_CONFIG} PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	makefile.linux
ALL_TARGET=	ALL

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/zsnes ${PREFIX}/bin/zsnes
	${INSTALL_MAN}	${WRKSRC}/src/linux/zsnes.man ${PREFIX}/man/man1/zsnes.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
