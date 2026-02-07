PORTNAME=	ladder
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.srv.net/~kth/ \
		ftp://ftp.42.org/pub/unix/games/ \
		https://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The old "ladder" game

# Converted from RESTRICTED
LICENSE=	ladder
LICENSE_NAME=	ladder
LICENSE_TEXT=	possible copyright problems ?
LICENSE_PERMS=	auto-accept

USES=		ncurses tar
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"
NO_WRKSUBDIR=	true

.include <bsd.port.mk>
