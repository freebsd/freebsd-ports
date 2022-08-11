PORTNAME=	ctris
PORTVERSION=	0.42.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Colorized, small, and flexible Tetris(TM)-clone for the console

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses
MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"

USE_GITHUB=	yes
GH_ACCOUNT=	dominikhackl

PLIST_FILES=	bin/ctris man/man6/ctris.6.gz

post-patch:
	@${REINPLACE_CMD} -e "s|v0\.42|v${PORTVERSION}|" ${WRKSRC}/ctris.h
	@${REINPLACE_CMD} -e "s|gcc|${CC}|" -e "s|CFLAGS=.*|CFLAGS+=-Wall|" \
		 ${WRKSRC}/Makefile

do-install:
	${INSTALL_MAN} ${WRKSRC}/ctris.6.gz \
		${STAGEDIR}${PREFIX}/man/man6/ctris.6.gz
	${INSTALL_PROGRAM} ${WRKSRC}/ctris ${STAGEDIR}${PREFIX}/bin/ctris

.include <bsd.port.mk>
