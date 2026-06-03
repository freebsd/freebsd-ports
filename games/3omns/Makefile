PORTNAME=	3omns
DISTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	https://lab.burn.capital/chaz/3omns/uploads/6ec547a14fec72a72f9fa53c374bfa7e/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Old-school bomb-dropping Deathmatch
WWW=		https://chaz.human.codes/3omns/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libargp.so:devel/argp-standalone

USES=		compiler:c++11-lang gmake localbase lua:52 pkgconfig sdl tar:xz
USE_SDL=	image2 sdl2 ttf2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
LIBS+=		-largp

.include <bsd.port.mk>
