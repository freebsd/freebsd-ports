# New ports collection makefile for:	mupen64-sdlinput
# Date created:		12.Aug 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION=	0.0.8
CATEGORIES+=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/0.4/
PKGNAMESUFFIX=	-sdlinput
DISTNAME=	blight_input-${PORTVERSION}-b

MAINTAINER?=	tlp@LiquidX.org
COMMENT=	Blight's SDL input plugin for Mupen64

LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GCC=	3.4
USE_AUTOHEADER_VER=	259
ONLY_FOR_ARCHS=	i386

PLUGIN_NAME=	blight_input
PLIST_FILES=	share/mupen64/plugins/${PLUGIN_NAME}.so
PLIST_DIRS=	share/mupen64/plugins
PLIST_DIRS+=	share/mupen64

do-install:
	@${MKDIR} ${PREFIX}/share/mupen64/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/src/.libs/${PLUGIN_NAME}.so \
		${PREFIX}/share/mupen64/plugins/

.include <bsd.port.pre.mk>

CFLAGS+=	-fPIC
CFLAGS+=	-O3 -fomit-frame-pointer -funroll-loops -ffast-math -Wall -pipe
CFLAGS+=	-DX86 -mcpu=athlon

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
