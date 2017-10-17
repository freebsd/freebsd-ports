# Created by: jdunn@aquezada.com
# $FreeBSD$

PORTNAME=	cd-console
PORTVERSION=	2.4
CATEGORIES=	audio
MASTER_SITES=	http://www.oskusoft.com/osku/cd-console/

MAINTAINER=	jdunn@aquezada.com
COMMENT=	Curses-based console CD player

DEPRECATED=	No public distfiles
EXPIRATION_DATE=	2017-12-12

USES=		ncurses
MAKE_ARGS=	BINPATH=${STAGEDIR}${PREFIX}/bin LIBS="${LDFLAGS} -lncurses"

PLIST_FILES=	bin/cd-console

.include <bsd.port.mk>
