# New ports collection makefile for:	mupen64-gln64
# Date created:		11.Aug 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION=	0.4.1
CATEGORIES+=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/0.4/
PKGNAMESUFFIX=	-gln64
DISTNAME=	glN64-${PORTVERSION}-rc2

MAINTAINER?=	tlp@LiquidX.org
COMMENT=	GlN64 graphics plugin for Mupen64

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GNOME=	gtk12
USE_GCC=	3.4
ONLY_FOR_ARCHS=	i386

PLUGIN_NAME=	glN64-${PORTVERSION}
PLIST_FILES=	share/mupen64/plugins/${PLUGIN_NAME}.so
PLIST_DIRS=	share/mupen64/plugins
PLIST_DIRS+=	share/mupen64

ALL_TARGET=	${PLUGIN_NAME}.so

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/DepthBuffer.cpp

do-install:
	@${MKDIR} ${PREFIX}/share/mupen64/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN_NAME}.so \
		${PREFIX}/share/mupen64/plugins/

.include <bsd.port.pre.mk>

CFLAGS+=	-I. -D__LINUX__ -D__USE_GNU `${SDL_CONFIG} --cflags`
CFLAGS+=	-DUSE_GTK `${GTK_CONFIG} --cflags gtk gthread` `${GLIB_CONFIG} --cflags` -fPIC
CFLAGS+=	-O3 -fomit-frame-pointer -funroll-loops -ffast-math -finline-functions -Wall -pipe
CFLAGS+=	-DX86_ASM -mcpu=athlon
LDFLAGS+=	-shared -Wl,-Bsymbolic
LDFLAGS+=	`${SDL_CONFIG} --libs` `${GTK_CONFIG} --libs gtk gthread` `${GLIB_CONFIG} --libs` -lGL -lGLU

MAKE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" LD="${CXX}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
