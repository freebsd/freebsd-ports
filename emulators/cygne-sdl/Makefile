# Created by: Li-Lun Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	cygne-sdl
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://sdlemu.ngemu.com/OpenProjects/
DISTNAME=	Cygne-SDL-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The SDL port of Cygne, a free Bandai Wonderswan emulator

USE_SDL=	sdl
USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386
WRKSRC=	${WRKDIR}/Cygne-SDL-${PORTVERSION}/src

NO_STAGE=	yes
post-patch:
	${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cygne ${PREFIX}/bin

.include <bsd.port.mk>
