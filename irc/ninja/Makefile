PORTNAME=	ninja
PORTVERSION=	1.5.8.1
CATEGORIES=	irc
PKGNAMEPREFIX=	irc-
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another ircII based irc client

USES=		ncurses

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	IRCLIB="${DATADIR}"
MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ninja ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ninjawserv ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/translation
	${INSTALL_DATA} ${WRKSRC}/translation/* ${STAGEDIR}${DATADIR}/translation

.include <bsd.port.mk>
