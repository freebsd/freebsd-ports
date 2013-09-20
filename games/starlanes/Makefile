# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	starlanes
PORTVERSION=	1.2.2
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classic space-age stock trading game

MAN6=		starlanes.6
PLIST_FILES=	bin/starlanes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's| restrict| m_restrict| ; \
		 s|(restrict|(m_restrict|' ${WRKSRC}/starlanes.c

do-build:
	(cd ${WRKSRC} \
		&& ${CC} ${CFLAGS} -o starlanes starlanes.c -lcurses)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} starlanes ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} starlanes.6 ${MAN6PREFIX}/man/man6)

.include <bsd.port.mk>
