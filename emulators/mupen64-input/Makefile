# New ports collection makefile for:	mupen64-input
# Date created:		11.Aug 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION=	0.4
CATEGORIES+=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/${PORTVERSION}/
PKGNAMESUFFIX=	-input
DISTNAME=	mupen64_input

MAINTAINER?=	tlp@LiquidX.org
COMMENT=	Input plugin for Mupen64

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GNOME=	gtk12
USE_GCC=	3.4
ONLY_FOR_ARCHS=	i386

PLUGIN_NAME=	mupen64_input
PLIST_FILES=	share/mupen64/plugins/${PLUGIN_NAME}.so
PLIST_DIRS=	share/mupen64/plugins
PLIST_DIRS+=	share/mupen64

FIXME2=		main.c

do-configure:
.for i in ${FIXME2}
	${REINPLACE_CMD} -e 's|SDL/SDL.h|SDL.h|' ${WRKSRC}/${i}
.endfor
	${REINPLACE_CMD} -e 's|-lSDL|`${SDL_CONFIG} --libs`|' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${PREFIX}/share/mupen64/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN_NAME}.so \
		${PREFIX}/share/mupen64/plugins/

.include <bsd.port.pre.mk>

CFLAGS+=	`${SDL_CONFIG} --cflags`
CFLAGS+=	-DUSE_GTK `${GTK_CONFIG} --cflags` -fPIC
CFLAGS+=	-O3 -fomit-frame-pointer -funroll-loops -ffast-math -Wall -pipe
CFLAGS+=	-DX86 -mcpu=athlon

MAKE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
