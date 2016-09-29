# $FreeBSD$

PORTNAME=	wy60
PORTVERSION=	2.0.9
CATEGORIES=	comms
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/${PORTNAME}/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Curses-based emulator for the Wyse 60 terminal

USES=		ncurses
GNU_CONFIGURE=	yes
MAKE_ARGS=	etc_DATA=wy60.rc.sample

pre-build:
	@${CP} ${WRKSRC}/wy60.rc ${WRKSRC}/wy60.rc.sample

.include <bsd.port.mk>
