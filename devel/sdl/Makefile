# New ports collection makefile for:	SDL
# Date created:				8 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/ \
		http://www.devolution.com/~slouken/SDL/release/
DISTNAME=	SDL-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=	yes
USE_XLIB=	yes
USE_ESOUND=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	NASM="${LOCALBASE}/bin/nasm" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-video-svga

CFLAGS+=	${PTHREAD_CFLAGS}

post-configure:
	@${PERL} -pi -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

post-install:
	@${MKDIR} ${PREFIX}/share/examples/SDL
	${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/examples/SDL
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SDL
.for file in BUGS COPYING CREDITS README WhatsNew docs.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/SDL
.endfor
	cd ${WRKSRC}/docs; tar cf - `${ECHO} [^M]*` | \
		(cd ${PREFIX}/share/doc/SDL; ${TAR} --unlink -xf - )
.endif

.include <bsd.port.mk>
