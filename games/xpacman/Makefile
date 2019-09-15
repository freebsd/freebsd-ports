# Created by: joerg
# $FreeBSD$

PORTNAME=	xpacman
PORTVERSION=	1.002
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.nvg.unit.no/pub/pacman/
DISTNAME=	pacman-1_002

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Old action game

LICENSE=	GPLv2

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

RUN_DEPENDS+=	${LOCALBASE}/share/fonts/misc/9x18.pcf.gz:x11-fonts/font-misc-misc

USES=	compiler

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-doublesize
# Build ignores CFLAGS, CXXFLAGS
CPPFLAGS+=	-I${LOCALBASE}/include ${CPPFLAGS_${CHOSEN_COMPILER_TYPE}}
CPPFLAGS_clang=	-Wno-c++11-narrowing
LDFLAGS+=	-L${LOCALBASE}/lib
USE_XORG=	x11 xext
PLIST_FILES=	bin/pacman

.include <bsd.port.mk>
