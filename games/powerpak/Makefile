# New ports collection makefile for:	PowerPak
# Version required:			990905
# Date created:				19 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	PowerPak
PKGNAME=	powerpak-990905
CATEGORIES= 	games
MASTER_SITES=	http://www.angelfire.com/va/powerpakgsdk/images/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	SDL.0:${PORTSDIR}/devel/sdl \
		ttf.4:${PORTSDIR}/print/freetype

MAKEFILE=	Makefile.FreeBSD

post-extract:
	@ /usr/bin/find ${WRKSRC} -type f | xargs ${PERL} -pi -e 's/\r//g'

pre-build:
	@ ${CP} ${FILESDIR}/Makefile.FreeBSD ${WRKSRC}

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/libPP.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/libPP.so ${PREFIX}/lib
	@ ${MKDIR} ${PREFIX}/include/PowerPak
	@ ${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/PowerPak
	@ ${INSTALL_DATA} ${WRKSRC}/PowerDraw/*.h ${PREFIX}/include/PowerPak
	@ ${INSTALL_DATA} ${WRKSRC}/PowerInput/*.h ${PREFIX}/include/PowerPak
	@ ${MKDIR} ${PREFIX}/share/examples/PowerPak/PowerDraw
	@ ${INSTALL_DATA} ${WRKSRC}/PowerDraw/examples/Makefile.UNIX ${PREFIX}/share/examples/PowerPak/PowerDraw/Makefile
	@ ${INSTALL_DATA} ${WRKSRC}/PowerDraw/examples/*.c ${PREFIX}/share/examples/PowerPak/PowerDraw
	@ ${INSTALL_DATA} ${WRKSRC}/PowerDraw/examples/*.ttf ${PREFIX}/share/examples/PowerPak/PowerDraw
	@ ${INSTALL_DATA} ${WRKSRC}/PowerDraw/examples/*.pcx ${PREFIX}/share/examples/PowerPak/PowerDraw 
	@ ${MKDIR} ${PREFIX}/share/examples/PowerPak/PowerInput
	@ ${INSTALL_DATA} ${WRKSRC}/PowerInput/examples/Makefile.UNIX ${PREFIX}/share/examples/PowerPak/PowerInput/Makefile
.for file in ex1.c ex2.c ex3.c ex4.c ex5.c sprite.pcx
	@ ${INSTALL_DATA} ${WRKSRC}/PowerInput/examples/${file} ${PREFIX}/share/examples/PowerPak/PowerInput
.endfor

post-install:
	@ ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
