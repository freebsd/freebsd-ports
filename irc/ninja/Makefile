# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ninja
PORTVERSION=	1.5.8.1
CATEGORIES=	irc
PKGNAMEPREFIX=	irc-
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another ircII based irc client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	IRCLIB="${DATADIR}"
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|%%IRCLIB%%|${DATADIR}|g" \
		${WRKSRC}/include/config.h.dist

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ninja ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ninjawserv ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/translation
	${INSTALL_DATA} ${WRKSRC}/translation/* ${DATADIR}/translation

.include <bsd.port.mk>
