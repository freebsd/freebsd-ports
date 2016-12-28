# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	libtermkey
PORTVERSION=	0.19
CATEGORIES=	devel
MASTER_SITES=	http://www.leonerd.org.uk/code/libtermkey/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy processing of keyboard entry from terminal-based programs

LICENSE=	MIT

USES=		gmake libtool:build ncurses pathfix pkgconfig
PATHFIX_MAKEFILEIN=	Makefile
LIB_DEPENDS=	libunibilium.so:devel/unibilium
USE_LDCONFIG=	yes
MAKE_ARGS=	MANDIR=${MANPREFIX}/man

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtermkey.so.1.13.0

.include <bsd.port.mk>
