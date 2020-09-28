# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	3omns
DISTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://github.com/chazomaticus/3omns/releases/download/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Old-school bomb-dropping Deathmatch

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libargp.so:devel/argp-standalone

USES=		compiler:c++11-lang gmake localbase lua:52 pkgconfig sdl tar:xz
USE_SDL=	image2 sdl2 ttf2

GNU_CONFIGURE=	yes
LIBS+=		-largp

.include <bsd.port.mk>
