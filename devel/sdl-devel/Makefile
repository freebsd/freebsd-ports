# New ports collection makefile for:	SDL
# Version required:			1.0.8
# Date created:				8 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		SDL-1.0.8
PKGNAME=		sdl-1.0.8
CATEGORIES=		devel
MASTER_SITES=		http://www.devolution.com/~slouken/SDL/release/

MAINTAINER=		ports@FreeBSD.org

#This port doesn't love FreeBSD pthread :(
LIB_DEPENDS=		lthread.2:${PORTSDIR}/devel/linuxthreads \
			esd.2:${PORTSDIR}/audio/esound
BUILD_DEPENDS=		nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=		yes
USE_XLIB=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV=		NASM="${LOCALBASE}/bin/nasm" \
			LOCALBASE="${LOCALBASE}"

CFLAGS+=		-I${LOCALBASE}/include/pthread/linuxthreads \
			-D_THREAD_SAFE

post-install:
	@ ${MKDIR} ${PREFIX}/share/examples/SDL
	@ ${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/examples/SDL 
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/SDL
.for file in BUGS COPYING CREDITS README WhatsNew docs.html
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/SDL
.endfor
	@ cd ${WRKSRC}/docs; tar cf - `${ECHO} [^M]*` | \
		(cd ${PREFIX}/share/doc/SDL; ${TAR} --unlink -xf - )
.endif

.include <bsd.port.mk>
