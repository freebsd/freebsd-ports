# New ports collection makefile for:	PowerPak
# Version required:			990901
# Date created:				19 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	PowerPak
PKGNAME=	powerpak-990901
CATEGORIES= 	games
MASTER_SITES=	http://www.angelfire.com/va/powerpakgsdk/images/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	SDL.0:${PORTSDIR}/devel/sdl \
		ttf.3:${PORTSDIR}/print/freetype

MAKEFILE=	Makefile.FreeBSD

post-extract:
	@ /usr/bin/find ${WRKSRC} -type f | xargs ${PERL} -pi -e 's/\r//g'

pre-build:
	@ ${CP} ${FILESDIR}/Makefile.FreeBSD ${WRKSRC}

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/libPP.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/libPP.so ${PREFIX}/lib
	@ ${MKDIR} ${PREFIX}/include/PowerPak
.for file in IMG.h powerpak.h PowerDraw/gfx.h PowerDraw/powerdraw.h PowerDraw/primitives.h PowerDraw/sprites.h PowerDraw/truetype.h PowerInput/keyboard.h PowerInput/mouse.h PowerInput/powerinput.h
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/PowerPak
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/PowerPak/PowerDraw
	@ ${INSTALL_DATA} ${WRKSRC}/PowerDraw/examples/Makefile.UNIX ${PREFIX}/share/examples/PowerPak/PowerDraw/Makefile
.for file in crackman.ttf crackman.txt ex1.c ex2.c ex3.c ex4.c ex4.pcx ex5.c ex5-1.pcx ex5-2.pcx ex6.c ex7.c
	@ ${INSTALL_DATA} ${WRKSRC}/PowerDraw/examples/${file} ${PREFIX}/share/examples/PowerPak/PowerDraw
.endfor
	@ ${MKDIR} ${PREFIX}/share/examples/PowerPak/PowerInput
	@ ${INSTALL_DATA} ${WRKSRC}/PowerInput/examples/Makefile.UNIX ${PREFIX}/share/examples/PowerPak/PowerInput/Makefile
.for file in ex1.c ex2.c ex3.c ex4.c
	@ ${INSTALL_DATA} ${WRKSRC}/PowerInput/examples/${file} ${PREFIX}/share/examples/PowerPak/PowerInput
.endfor

post-install:
	@ ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
