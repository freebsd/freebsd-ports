# New ports collection makefile for:	SDL
# Date created:				1 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	1.2.9
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/
DISTNAME=	SDL-${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Cross-platform multi-media development API

LIB_DEPENDS=	aa.1:${PORTSDIR}/graphics/aalib
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
CONFIGURE_ENV=	NASM="${LOCALBASE}/bin/nasm"		\
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
		PTHREAD_LIBS="${PTHREAD_LIBS}"		\
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-video-aalib
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_XLIB=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

OPTIONS=	NAS	"Include support for the Network Audio System" Off \
		GL	"Include support for OpenGL" On

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000 && exists(/usr/lib/libvgl.so)
CONFIGURE_ARGS+=--enable-video-vgl
DISPLAY_MSG=	${CAT} ${PKGMESSAGE}
.else
CONFIGURE_ARGS+=--disable-video-vgl
PKGMESSAGE=	none
DISPLAY_MSG=	${DO_NADA}
.endif

.if defined(WITH_NAS)
LIB_DEPENDS+=	audio.2:${PORTSDIR}/audio/nas
.else
CONFIGURE_ARGS+=--disable-nas
.endif

.if defined(WITHOUT_GL)
CONFIGURE_ARGS+=--disable-video-opengl
.else
USE_GL=		yes
CONFIGURE_ARGS+=--enable-video-opengl
.endif
.if exists(/usr/include/libusbhid.h)
CONFIGURE_ENV+=	USB_LIBS=-lusbhid
CFLAGS+=	-DHAVE_LIBUSBHID_H
.else
CONFIGURE_ENV+=	USB_LIBS=-lusb
.endif

MAN3!=		${CAT} ${FILESDIR}/man3

.if (${ARCH} != "i386")
WITHOUT_SVGALIB=	yes
.endif

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=	esound
.else
CONFIGURE_ARGS+=--disable-esd --disable-esdtest
.endif

.if !defined(WITHOUT_SVGALIB)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--enable-video-svga
.endif

.if (exists(${LOCALBASE}/bin/artsc-config) || defined(WITH_ARTS)) && !defined(WITHOUT_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=--enable-arts
.else
CONFIGURE_ARGS+=--disable-arts
.endif

post-patch:
	@${REINPLACE_CMD} 's|sdl-config|sdl11-config|g'	\
		${WRKSRC}/test/configure
	@${RM} ${WRKSRC}/test/configure.bak

pre-configure:
	@${FIND} ${WRKSRC} -type f -name Makefile.in | ${XARGS} ${TOUCH}

post-configure:
	@cd ${WRKSRC} && \
		${CP} sdl-config sdl11-config && \
		${CP} sdl.m4 sdl11.m4
	@${REINPLACE_CMD} 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/test/configure ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/docs
.for f in BUGS COPYING CREDITS README README-SDL.txt WhatsNew docs.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@cd ${WRKSRC}/docs; ${TAR} cf - `${ECHO_CMD} [^Mm]*` | \
		(cd ${DOCSDIR}/docs; ${TAR} --unlink -xf - )
.endif
	@${DISPLAY_MSG}

.include <bsd.port.post.mk>
