# Created by: Jacob Myers
# $FreeBSD$

PORTNAME=	bsdrain
PORTVERSION=	5.0
CATEGORIES=	games
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://whotookspaz.org/misc/freebsd/rain/
DISTNAME=	rain-${PORTVERSION}

MAINTAINER=	jacob@whotookspaz.org
COMMENT=	The original BSD rain program, ported from NetBSD

PLIST_FILES=	bin/rain \
		man/man6/rain.6.gz

USES=		ncurses tar:bzip2 uidfix
MAKE_ARGS=	LDADD="-lncurses"

.include <bsd.port.mk>
