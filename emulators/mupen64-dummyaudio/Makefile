# New ports collection makefile for:	mupen64-dummyaudio
# Date created:		12.Aug 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION=	0.4
CATEGORIES+=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/${PORTVERSION}/
PKGNAMESUFFIX=	-dummyaudio
DISTNAME=	dummyaudio

MAINTAINER?=	tlp@LiquidX.org
COMMENT=	Dummy audio plugin for Mupen64

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/dummy

PLUGIN_NAME=	dummyaudio
PLIST_FILES=	share/mupen64/plugins/${PLUGIN_NAME}.so
PLIST_DIRS=	share/mupen64/plugins
PLIST_DIRS+=	share/mupen64

do-install:
	@${MKDIR} ${PREFIX}/share/mupen64/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN_NAME}.so \
		${PREFIX}/share/mupen64/plugins/

.include <bsd.port.pre.mk>

CFLAGS+=	-fPIC
CFLAGS+=	-O3 -fomit-frame-pointer -funroll-loops -ffast-math -Wall -pipe
CFLAGS+=	-DX86 -mcpu=athlon
LDFLAGS+=	-shared -Wl,-Bsymbolic -lc

MAKE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" LD="${CC}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
