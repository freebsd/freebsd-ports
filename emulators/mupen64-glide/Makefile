# New ports collection makefile for:	mupen64-glide
# Date created:		11.Aug 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES+=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/0.4/
PKGNAMESUFFIX=	-glide
DISTNAME=	glide64_0_7_ME

MAINTAINER?=	tlp@LiquidX.org
COMMENT=	Glide64 graphics plugin for Mupen64

BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GNOME=	gtk12
USE_XLIB=	yes
USE_GCC=	3.4
ONLY_FOR_ARCHS=	i386

PLUGIN_NAME=	Glide64
PLIST_FILES=	share/mupen64/plugins/${PLUGIN_NAME}.so
PLIST_FILES+=	share/mupen64/plugins/${PLUGIN_NAME}.ini
PLIST_DIRS=	share/mupen64/plugins
PLIST_DIRS+=	share/mupen64

FIXME2=		wrapper/main.cpp

do-configure:
.for i in ${FIXME2}
	${REINPLACE_CMD} -e 's|SDL/SDL.h|SDL.h|' ${WRKSRC}/${i}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/share/mupen64/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN_NAME}.so \
		${PREFIX}/share/mupen64/plugins/
	${INSTALL_DATA} ${WRKSRC}/${PLUGIN_NAME}.ini \
		${PREFIX}/share/mupen64/plugins/

.include <bsd.port.pre.mk>

CFLAGS+=	-Iwrapper/ `${SDL_CONFIG} --cflags`
CFLAGS+=	-DUSE_GTK `${GTK_CONFIG} --cflags` -fPIC
CFLAGS+=	-O3 -fomit-frame-pointer -funroll-loops -ffast-math -Wall -pipe
CFLAGS+=	-DX86 -mcpu=athlon
LDFLAGS+=	-lGL -lGLU -L${X11BASE}/lib `${SDL_CONFIG} --libs` -lc

MAKE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" LD="${CXX}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
