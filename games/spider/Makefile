# Created by: se
# $FreeBSD$

PORTNAME=	spider
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/solitaires
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Challenging double decked solitaire game

USES=		imake tar:Z
USE_XORG=	x11 xext xaw xmu xt sm ice xpm
INSTALL_TARGET=	install install.doc
CFLAGS+=	-Wno-error=return-type

.include <bsd.port.mk>
