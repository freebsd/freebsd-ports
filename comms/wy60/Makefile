# $FreeBSD$

PORTNAME=	wy60
PORTVERSION=	2.0.9
CATEGORIES=	comms

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Curses-based emulator for the Wyse 60 terminal

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	mieko
GH_TAGNAME=	8e082bf

USES=		ncurses
GNU_CONFIGURE=	yes
MAKE_ARGS=	etc_DATA=wy60.rc.sample

pre-build:
	@${CP} ${WRKSRC}/wy60.rc ${WRKSRC}/wy60.rc.sample

.include <bsd.port.mk>
