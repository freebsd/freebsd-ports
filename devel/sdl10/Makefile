# New ports collection makefile for:	SDL
# Version required:			1.0.1
# Date created:				8 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		SDL-1.0.1
PKGNAME=		sdl-1.0.1
CATEGORIES=		devel audio
MASTER_SITES=		http://www.devolution.com/~slouken/SDL/release/

MAINTAINER=		andy@icc.surw.chel.su

#This port doesn't love FreeBSD pthread :(
LIB_DEPENDS=		lthread.2:${PORTSDIR}/devel/linuxthreads \
			esd.2:${PORTSDIR}/audio/esound
BUILD_DEPENDS=		nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=		yes
USE_XLIB=		yes
GNU_CONFIGURE=		yes

#DGA seems hosed, at least on my two 4.0 boxes (XFree86 3.3.5)
CONFIGURE_ARGS=		--disable-video-x11-dga

CONFIGURE_ENV=		NASM="${LOCALBASE}/bin/nasm" \
			LOCALBASE="${LOCALBASE}"

CFLAGS+=		-I${LOCALBASE}/include/pthread/linuxthreads

post-install:
	@ ${MKDIR} ${PREFIX}/share/examples/SDL
	@ ${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/examples/SDL
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/SDL
.for file in BUGS COPYING CREDITS README TODO WhatsNew docs.html
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/SDL
.endfor
	@ cd ${WRKSRC}/docs; tar cf - audio cdrom events images index.html threads video | \
		(cd ${PREFIX}/share/doc/SDL; tar --unlink -xf - )
.endif

.include <bsd.port.mk>
