# New ports collection makefile for:	liquidwar
# Date created:				9 October 2005
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	liquidwar
PORTVERSION=	5.6.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://liquidwar.sunsite.dk/archive/ \
		${MASTER_SITE_SAVANNAH} \
		http://ufoot.hd.free.fr/pub/archive/
MASTER_SITE_SUBDIR=	liquidwar

MAINTAINER=	edwin@mavetju.org
COMMENT=	You control an army of liquid and have to try and eat your opponents

LIB_DEPENDS=	alleg.42:${PORTSDIR}/devel/allegro

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-target-opt --disable-doc-ps --disable-doc-pdf
USE_PYTHON_BUILD=yes

INFO=		liquidwar

MANCOMPRESSED=	yes
MAN6=		liquidwar.6 \
		liquidwar-server.6 \
		liquidwar-mapgen.6

OPTIONS=	ASM "Disable assembly code (if it crashes)" OFF

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ASM)
CONFIGURE_ARGS+=	--disable-asm
.endif

.include <bsd.port.post.mk>
