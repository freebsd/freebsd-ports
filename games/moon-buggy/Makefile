# Created by: Ralf Becker <ralf@akk.org>
# $FreeBSD$

PORTNAME=	moon-buggy
PORTVERSION=	1.0.51
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://seehuhn.de/media/programs/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Drive a buggy across the moons surface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--sharedstatedir=/var/games

INFO=		moon-buggy

post-install:
	${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/moon-buggy

.include <bsd.port.mk>
