# New ports collection makefile for:	SDL
# Date created:				1 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		sdl-devel
PORTVERSION=		1.1.2
CATEGORIES=		devel
MASTER_SITES=		http://www.devolution.com/~slouken/SDL/release/
DISTNAME=		SDL-${PORTVERSION}

MAINTAINER=		sobomax@FreeBSD.org

LIB_DEPENDS=		esd.2:${PORTSDIR}/audio/esound \
			aa.1:${PORTSDIR}/graphics/aalib \
			${GL_DEPENDS}
BUILD_DEPENDS=		nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=		yes
USE_XLIB=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ENV=		NASM="${LOCALBASE}/bin/nasm" \
			LOCALBASE="${LOCALBASE}"
CONFIGURE_ARGS=		--enable-video-aalib

CFLAGS+=		-D_THREAD_SAFE

.if defined(WITHOUT_GL)
GL_DEPENDS=
CONFIGURE_ARGS+=	--disable-video-opengl
.else
GL_DEPENDS=		GL.14:${PORTSDIR}/graphics/Mesa3
CONFIGURE_ARGS+=	--enable-video-opengl
.endif

post-configure:
	@ cd ${WRKSRC} && \
		${CP} sdl-config sdl11-config && \
		${CP} sdl.m4 sdl11.m4

post-install:
	@ ${MKDIR} ${PREFIX}/share/examples/SDL11
	@ ${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/examples/SDL11
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/SDL11
.for file in BUGS COPYING CREDITS README WhatsNew docs.html
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/SDL11
.endfor
	@ cd ${WRKSRC}/docs; tar cf - `${ECHO} [^M]*` | \
		(cd ${PREFIX}/share/doc/SDL11; ${TAR} --unlink -xf - )
.endif

.include <bsd.port.mk>
