# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tbclock
PORTVERSION=	1.10
CATEGORIES=	games
MASTER_SITES=	http://tamentis.com/projects/tbclock/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Binary clock in curses

USES=		ncurses
HAS_CONFIGURE=	yes
MAKE_ARGS=	LIBFLAGS="${LDFLAGS} -lncurses"
PLIST_FILES=	bin/${PORTNAME} man/man1/tbclock.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d;/^CFLAGS/d' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/tbclock.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
