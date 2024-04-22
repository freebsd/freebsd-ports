PORTNAME=	moon-buggy
PORTVERSION=	1.0.51
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://seehuhn.de/media/programs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drive a buggy across the moons surface
WWW=		https://www.seehuhn.de/comp/moon-buggy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--sharedstatedir=/var/games

INFO=		moon-buggy

post-install:
	${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/moon-buggy

.include <bsd.port.mk>
