# New ports collection makefile for:	games/wmquake
# Date created:				17.01.2005
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	wmquake
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/

MAINTAINER=	q@galgenberg.net
COMMENT=	Id Software\'s Quake I in a 64x64 WM dockapp window

LIB_DEPENDS+=	gdk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/wmquake

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -fomit-frame-pointer -funroll-loops -fno-strength-reduce
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Define WITH_OPTIMIZED_CFLAGS to enable aggressive optimizations"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmquake ${PREFIX}/bin

post-install:
	${CAT} pkg-message

.include <bsd.port.mk>
