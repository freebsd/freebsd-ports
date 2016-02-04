# Created by: Stefan Zehl <sec@42.org>
# $FreeBSD$

PORTNAME=	ladder
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.srv.net/~kth/ \
		ftp://ftp.42.org/pub/unix/games/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The old "ladder" game

RESTRICTED=	possible copyright problems ?

USES=		ncurses tar
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"
NO_WRKSUBDIR=	true

.include <bsd.port.mk>
