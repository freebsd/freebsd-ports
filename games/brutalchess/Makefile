# New ports collection makefile for:   Brutalchess
# Date created:         2005-02-07
# Whom:                 Gustavo Perez Querol <gustau.perez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		brutalchess
PORTVERSION=		0.5.2
PORTREVISION=	5
CATEGORIES=		games
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}-alpha/${PORTNAME}-alpha-${PORTVERSION}
DISTNAME=		${PORTNAME}-alpha-${PORTVERSION}-src

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

MAINTAINER=		gustau.perez@gmail.com
COMMENT=		Nice looking OpenGL chess game

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_XORG=		x11 xext xt xmu xi

USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:22

USE_GL=			yes
USE_SDL=		sdl image

pre-build:
	${CHMOD} 0755 ${WRKSRC}/install-sh

MANCOMPRESSED=		yes

.include <bsd.port.mk>
