# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ninja
PORTVERSION=	1.5.8.1
CATEGORIES=	irc
PKGNAMEPREFIX=	irc-
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another ircII based irc client

USES=		ncurses
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	IRCLIB="${DATADIR}"
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%IRCLIB%%|${DATADIR}|g" \
		${WRKSRC}/include/config.h.dist

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ninja ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ninjawserv ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/translation
	${INSTALL_DATA} ${WRKSRC}/translation/* ${STAGEDIR}${DATADIR}/translation

.include <bsd.port.mk>
