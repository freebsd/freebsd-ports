# New ports collection makefile for:	SDL
# Date created:				8 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		sdl
PORTVERSION=		1.0.8
CATEGORIES=		devel
MASTER_SITES=		http://www.libsdl.org/release/ \
			http://www.devolution.com/~slouken/SDL/release/
DISTNAME=		SDL-${PORTVERSION}

MAINTAINER=		sobomax@FreeBSD.org

LIB_DEPENDS=		esd.2:${PORTSDIR}/audio/esound
BUILD_DEPENDS=		nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=		yes
USE_XLIB=		yes
INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		NASM="${LOCALBASE}/bin/nasm" \
			LOCALBASE="${LOCALBASE}"
CFLAGS+=		-D_THREAD_SAFE

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
