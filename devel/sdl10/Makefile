# New ports collection makefile for:	SDL
# Version required:			0.10.0
# Date created:				8 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		SDL-0.10.0
PKGNAME=		sdl-0.10.0
CATEGORIES=		devel
MASTER_SITES=		http://www.devolution.com/~slouken/SDL/SDL-0.10/src/

MAINTAINER=		andy@icc.surw.chel.su

BUILD_DEPENDS=		nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=		yes
USE_XLIB=		yes

do-build:
	@ cd ${WRKSRC}; ${GMAKE}
	@ cd ${WRKSRC}; ${GMAKE}

post-install:
	@ cd ${PREFIX}/lib; ${LN} -sf libSDLx11.so.0.10.0 libSDL.so.0
	@ cd ${PREFIX}/lib; ${LN} -sf libSDLx11.so.0.10.0 libSDLx11.so.0
	@ ${MKDIR} ${PREFIX}/share/examples/SDL
	@ ${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/examples/SDL
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/SDL
.for file in BUGS COPYING CREDITS README TODO WhatsNew docs.html
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/SDL
.endfor
	@ cd ${WRKSRC}/docs; tar cf - * | \
		(cd ${PREFIX}/share/doc/SDL; tar --unlink -xf - )
.endif
	@ ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
