# New ports collection makefile for:	PowerPak
# Date created:				19 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	powerpak
PORTVERSION=	20000511
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.angelfire.com/va/powerpakgsdk/images/
DISTNAME=	PowerPak

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL-based Game Software Development Kit

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		smpeg.1:${PORTSDIR}/multimedia/smpeg \

USE_SDL=	mixer sdl
USE_FREETYPE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
MAKEFILE=	Makefile.UNIX

post-extract:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e "s/`/usr/bin/printf '\r'`//g ; \
		s|\"SDL/|\"|g ; s|<SDL/|<|g"

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/libPP.a ${PREFIX}/lib
	@ ${INSTALL_PROGRAM} ${WRKSRC}/libPP.so.1 ${PREFIX}/lib
	@ ${LN} -sf ${PREFIX}/lib/libPP.so.1 ${PREFIX}/lib/libPP.so
	@ ${MKDIR} ${PREFIX}/include/PowerPak
.for dir in . Power3D PowerDraw PowerInput PowerMedia PowerSound
	@ ${INSTALL_DATA} ${WRKSRC}/${dir}/*.h ${PREFIX}/include/PowerPak
	@ if [ -d ${WRKSRC}/${dir}/examples ]; then \
		${MKDIR} ${PREFIX}/share/examples/PowerPak/${dir}; \
		${INSTALL_DATA} ${WRKSRC}/${dir}/examples/* ${PREFIX}/share/examples/PowerPak/${dir}; \
	  fi
.endfor

.include <bsd.port.mk>
