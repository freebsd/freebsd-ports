# New ports collection makefile for:	SDL
# Date created:				1 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl-devel
PORTVERSION=	1.1.5
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/ \
		http://www.devolution.com/~slouken/SDL/release/
DISTNAME=	SDL-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	aa.1:${PORTSDIR}/graphics/aalib \
		vga.1:${PORTSDIR}/graphics/svgalib
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=	yes
USE_XLIB=	yes
USE_ESOUND=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	NASM="${LOCALBASE}/bin/nasm"
CONFIGURE_ARGS=	--enable-video-aalib \
		--enable-video-svga

CFLAGS+=	-D_THREAD_SAFE

.if defined(WITHOUT_GL)
CONFIGURE_ARGS+=--disable-video-opengl
.else
USE_MESA=	yes
CONFIGURE_ARGS+=--enable-video-opengl
.endif

.include <bsd.port.pre.mk>

MAN3!=		/bin/cat ${FILESDIR}/man3

post-configure:
	@cd ${WRKSRC} && \
		${CP} sdl-config sdl11-config && \
		${CP} sdl.m4 sdl11.m4
	@${PERL} -pi -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

post-install:
	@${MKDIR} ${PREFIX}/share/examples/SDL11
	${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/examples/SDL11
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/SDL11/docs
.for file in BUGS COPYING CREDITS README WhatsNew docs.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/SDL11
.endfor
	@cd ${WRKSRC}/docs; tar cf - `${ECHO} [^Mm]*` | \
		(cd ${PREFIX}/share/doc/SDL11/docs; ${TAR} --unlink -xf - )
.endif

.include <bsd.port.post.mk>
