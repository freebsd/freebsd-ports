# New ports collection makefile for:	mupen64-sound
# Date created:		12.Aug 2004
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mupen64
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES+=	emulators
MASTER_SITES=	http://mupen64.emulation64.com/files/${PORTVERSION}/
PKGNAMESUFFIX=	-sound
DISTNAME=	mupen64_sound

MAINTAINER?=	tlp@LiquidX.org
COMMENT=	Sound plugin for Mupen64

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_GCC=	3.4
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

PLUGIN_NAME=	mupen64_audio
PLIST_FILES=	share/mupen64/plugins/${PLUGIN_NAME}.so
PLIST_DIRS=	share/mupen64/plugins share/mupen64

post-patch:
	@${REINPLACE_CMD} -e 's|linux/soundcard.h|sys/soundcard.h|' ${WRKSRC}/main.c

do-install:
	@${MKDIR} ${PREFIX}/share/mupen64/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/${PLUGIN_NAME}.so \
		${PREFIX}/share/mupen64/plugins/

.include <bsd.port.pre.mk>

CFLAGS+=	-DUSE_GTK `${GTK_CONFIG} --cflags` -fPIC
CFLAGS+=	-O3 -fomit-frame-pointer -funroll-loops -ffast-math -Wall -pipe
CFLAGS+=	-DX86 -mcpu=athlon
LDFLAGS+=	-shared -Wl,-Bsymbolic

MAKE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" LD="${CC}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
