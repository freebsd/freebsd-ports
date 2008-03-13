# New ports collection makefile for:	Cygne/SDL
# Date created:				4 May 2006
# Whom:					Li-Lun Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	cygne-sdl
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://sdlemu.ngemu.com/OpenProjects/
DISTNAME=	Cygne-SDL-${PORTVERSION}-src

MAINTAINER=	llwang@infor.org
COMMENT=	The SDL port of Cygne, a free Bandai Wonderswan emulator

USE_SDL=	sdl
USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386
WRKSRC=	${WRKDIR}/Cygne-SDL-${PORTVERSION}/src

post-patch:
	${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cygne ${PREFIX}/bin

.include <bsd.port.mk>
