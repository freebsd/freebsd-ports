# New ports collection makefile for:	PowerPak
# Date created:				19 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	powerpak
PORTVERSION=	991203
CATEGORIES=	games
MASTER_SITES=	http://www.imperialpenguin.com/software/powerpak/
DISTNAME=	PowerPak

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.0.2:${PORTSDIR}/devel/sdl10

USE_FREETYPE=	yes
MAKEFILE=	Makefile.FreeBSD
INSTALLS_SHLIB=	yes

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

.include <bsd.port.mk>
