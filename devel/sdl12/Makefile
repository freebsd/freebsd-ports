# New ports collection makefile for:	SDL
# Date created:				1 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	1.2.5
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/ \
		http://www.devolution.com/~slouken/SDL/release/
DISTNAME=	SDL-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	aa.1:${PORTSDIR}/graphics/aalib
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	NASM="${LOCALBASE}/bin/nasm" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-video-aalib \
		--disable-nas

CFLAGS+=	${PTHREAD_CFLAGS}

.if exists(/usr/lib/libvgl.so.3)
CONFIGURE_ARGS+=--enable-video-vgl
DISPLAY_MSG=	${CAT} ${PKGMESSAGE}
.else
CONFIGURE_ARGS+=--disable-video-vgl
PKGMESSAGE=	/I/hate/ports/Mk/bsd.port.mk
DISPLAY_MSG=	${DO_NADA}
.endif

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.endif
.if !defined(WITHOUT_ESOUND)
USE_GNOMENG=	yes
USE_GNOME=	esound
.else
CONFIGURE_ARGS+=--disable-esd --disable-esdtest
.endif
.if defined(WITHOUT_GL)
CONFIGURE_ARGS+=--disable-video-opengl
.else
USE_MESA=	yes
CONFIGURE_ARGS+=--enable-video-opengl
.endif
.if exists(/usr/include/libusbhid.h)
CONFIGURE_ENV+=	USB_LIBS=-lusbhid
CFLAGS+=	-DHAVE_LIBUSBHID_H
.else
CONFIGURE_ENV+=	USB_LIBS=-lusb
.endif

.include <bsd.port.pre.mk>

MAN3!=		${CAT} ${FILESDIR}/man3

.if (${ARCH} != "i386")
WITHOUT_SVGALIB=	yes
.endif

.if !defined(WITHOUT_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--enable-video-svga
.endif

.if exists(${LOCALBASE}/bin/artsc-config) || defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=--enable-arts
.else
CONFIGURE_ARGS+=--disable-arts
.endif

pre-configure:
	@${FIND} ${WRKSRC} -type f -name Makefile.in | ${XARGS} ${TOUCH}

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
	@cd ${WRKSRC}/docs; ${TAR} cf - `${ECHO_CMD} [^Mm]*` | \
		(cd ${PREFIX}/share/doc/SDL11/docs; ${TAR} --unlink -xf - )
.endif
	@${DISPLAY_MSG}

.include <bsd.port.post.mk>
