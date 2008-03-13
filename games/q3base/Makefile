# New ports collection makefile for:	q3base
# Date created:				17 Nov 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=		q3base
PORTVERSION=		0.1
PORTREVISION=	3
CATEGORIES=		games
MASTER_SITES=		http://quake3.quakesrc.org/files/quake3/q3base/

MAINTAINER=		ed@fxq.nl
COMMENT=		Quake III Arena fork using SDL

USE_BZIP2=		yes
USE_SDL=		sdl net

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=

OPTIONS=		X11 "Build OpenGL client" on

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=		nasm:${PORTSDIR}/devel/nasm
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS=		--disable-client
.else
USE_GL=			yes
USE_SDL+=		image
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|' \
		-e 's/echo aout/echo elf/' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\($${exec_prefix}/lib\)/quake3|\1/q3base|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|botlib\.log|/dev/null|' \
		${WRKSRC}/src/botlib/be_interface.c

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.post.mk>
