# New ports collection makefile for:	SDL
# Date created:				1 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	1.2.11
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/release/
DISTNAME=	SDL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform multi-media development API

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnometarget
USE_ICONV=	yes
CONFIGURE_ENV=	NASM="${LOCALBASE}/bin/nasm"		\
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"	\
		PTHREAD_LIBS="${PTHREAD_LIBS}"		\
		LDFLAGS="${LDFLAGS}"

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.else
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=--disable-video-x11
.endif

EXAMPLES=	test/*.c test/*.bmp test/*.dat test/*.xbm test/*.wav
DOCS=		BUGS COPYING CREDITS README README-SDL.txt WhatsNew docs.html

OPTIONS=	NAS	"Include support for the Network Audio System"	Off	\
		AALIB	"Include support for AA-lib"			On	\
		GL	"Include support for OpenGL"			On	\
		GGI	"Include support for GGI"			Off	\
		SVGALIB	"Include support for SVGALIB"			On

.include <bsd.port.pre.mk>

.if exists(/usr/lib/libvgl.so)
CONFIGURE_ARGS+=--enable-video-vgl
DISPLAY_MSG=	${CAT} ${PKGMESSAGE}
.else
CONFIGURE_ARGS+=--disable-video-vgl
PKGMESSAGE=	none
DISPLAY_MSG=	${DO_NADA}
.endif

.if ${OSVERSION} >= 500111
CONFIGURE_ENV+=	ac_cv_header_libusbhid_h=no
.endif

.if defined(WITH_NAS)
LIB_DEPENDS+=	audio.2:${PORTSDIR}/audio/nas
.else
CONFIGURE_ARGS+=--disable-nas
.endif

.if defined(WITH_GGI)
LIB_DEPENDS+=	ggi.2:${PORTSDIR}/graphics/libggi
CONFIGURE_ARGS+=--enable-video-ggi
.else
CONFIGURE_ARGS+=--disable-video-ggi
.endif

.if defined(WITHOUT_GL)
CONFIGURE_ARGS+=--disable-video-opengl
.else
USE_GL=		yes
CONFIGURE_ARGS+=--enable-video-opengl
.endif

.if defined(WITHOUT_AALIB)
CONFIGURE_ARGS+=--disable-video-aalib
.else
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
CONFIGURE_ARGS+=--enable-video-aalib
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

pre-configure:
	@${FIND} ${WRKSRC} -type f -name Makefile.in | ${XARGS} ${TOUCH}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${EXAMPLESDIR}/
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@(cd ${WRKSRC} && \
		${COPYTREE_SHARE} docs ${DOCSDIR}/ "! -regex .*/man3.*")
.endif
	@${DISPLAY_MSG}

.include <bsd.port.post.mk>
