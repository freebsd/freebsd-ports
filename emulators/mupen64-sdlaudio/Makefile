# New ports collection makefile for:	mupen64-sdlaudio
# Date created:		12.Aug 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION=	1.2
CATEGORIES+=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/0.4/
PKGNAMESUFFIX=	-sdlaudio
DISTNAME=	jttl_sound-${PORTVERSION}

MAINTAINER?=	tlp@LiquidX.org
COMMENT=	JttL's SDL audio plugin for Mupen64

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GNOME=	gtk12
USE_GCC=	3.4
ONLY_FOR_ARCHS=	i386

PLUGIN_NAME=	jttl_audio
PLIST_FILES=	share/mupen64/plugins/${PLUGIN_NAME}.so
PLIST_FILES+=	share/mupen64/jttl_audio.conf
PLIST_DIRS=	share/mupen64/plugins
PLIST_DIRS+=	share/mupen64

do-install:
	@${MKDIR} ${PREFIX}/share/mupen64/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN_NAME}.so \
		${PREFIX}/share/mupen64/plugins/
	${INSTALL_DATA} ${WRKSRC}/${PLUGIN_NAME}.conf \
		${PREFIX}/share/mupen64/${PLUGIN_NAME}.conf

.include <bsd.port.pre.mk>

CFLAGS+=	`${SDL_CONFIG} --cflags`
CFLAGS+=	-DUSE_GTK `${GTK_CONFIG} --cflags` -fPIC
CFLAGS+=	-O3 -fomit-frame-pointer -funroll-loops -ffast-math -Wall -pipe
CFLAGS+=	-DX86 -mcpu=athlon
LDFLAGS+=	-shared -Wl,-Bsymbolic `${GTK_CONFIG} --libs` -lm
LDFLAGS+=	`${SDL_CONFIG} --libs` -lc

MAKE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" LD="${CC}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
