# New ports collection makefile for:	zsnes
# Date created:				Fri May  4 13:10:11 CEST 2001
# Whom:					Stijn Hoop <stijn@win.tue.nl>
#
# $FreeBSD$
#

PORTNAME=	zsnes
PORTVERSION=	1.36
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	zsnes${PORTVERSION:S/.//}src

MAINTAINER=	stijn@win.tue.nl
COMMENT=	Intel x86 only Super Nintendo Entertainment System (SNES) Emulator

# This must be >= 0.98!
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_SDL=	sdl
USE_X_PREFIX=	yes
USE_GMAKE=	yes

MAN1=		zsnes.1
PLIST_FILES=	bin/zsnes

# non-portable, for a portable version see emulators/snes9x
ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

GNU_CONFIGURE=	yes
ALL_TARGET=	ALL

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
