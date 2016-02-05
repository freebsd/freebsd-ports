# Created by: jkh
# $FreeBSD$

PORTNAME=	jove
PORTVERSION=	4.16
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/moraes/jove/ \
		LOCAL/simon

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Jonathan's Own Version of Emacs

USES=		ncurses
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
