# Created by: jdunn@aquezada.com
# $FreeBSD$

PORTNAME=	cd-console
PORTVERSION=	2.4
CATEGORIES=	audio
MASTER_SITES=	http://www.oskusoft.com/osku/cd-console/

MAINTAINER=	jdunn@aquezada.com
COMMENT=	Curses-based console CD player

USES=		ncurses
MAKE_ARGS=	BINPATH=${STAGEDIR}${PREFIX}/bin LIBS="${LDFLAGS} -lncurses"

PLIST_FILES=	bin/cd-console

.include <bsd.port.mk>
