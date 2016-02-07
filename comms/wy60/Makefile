# $FreeBSD$

PORTNAME=	wy60
PORTVERSION=	2.0.9
CATEGORIES=	comms
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Curses-based emulator for the Wyse 60 terminal

USES=		ncurses
GNU_CONFIGURE=	yes
MAKE_ARGS=	etc_DATA=wy60.rc.sample

pre-build:
	@${CP} ${WRKSRC}/wy60.rc ${WRKSRC}/wy60.rc.sample

.include <bsd.port.mk>
