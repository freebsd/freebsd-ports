# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	starlanes
PORTVERSION=	1.2.2
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classic space-age stock trading game

USES=		ncurses
PLIST_FILES=	bin/starlanes man/man6/starlanes.6.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's| restrict| m_restrict| ; \
		 s|(restrict|(m_restrict|' ${WRKSRC}/starlanes.c

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${CC} ${CFLAGS} -o starlanes starlanes.c ${LDFLAGS} -lncurses)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} starlanes ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} starlanes.6 ${STAGEDIR}${MAN6PREFIX}/man/man6)

.include <bsd.port.mk>
