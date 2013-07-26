# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	liquidwar
PORTVERSION=	5.6.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://liquidwar.sunsite.dk/archive/ \
		${MASTER_SITE_SAVANNAH} \
		http://ufoot.hd.free.fr/pub/archive/
MASTER_SITE_SUBDIR=	liquidwar

MAINTAINER=	edwin@mavetju.org
COMMENT=	You control an army of liquid and have to try and eat your opponents

LIB_DEPENDS=	alleg.4:${PORTSDIR}/devel/allegro

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-target-opt --disable-doc-ps --disable-doc-pdf
USE_PYTHON_BUILD=yes

INFO=		liquidwar

MANCOMPRESSED=	yes
MAN6=		liquidwar.6 \
		liquidwar-server.6 \
		liquidwar-mapgen.6

OPTIONS_DEFINE=		ASM

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MASM}
CONFIGURE_ARGS+=	--disable-asm
.endif

.include <bsd.port.mk>
