# New ports collection makefile for: 	Ninja-irc
# Date created:	 	10 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ninja
PORTVERSION=	1.5.8
CATEGORIES=	irc
MASTER_SITES=	ftp://ninja.qoop.org/ninja/sources/

MAINTAINER=	anders@hack.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	IRCLIB="${IRCLIB}"

IRCLIB=		${PREFIX}/share/ninja

post-patch:
	@${PERL} -e "s|%%IRCLIB%%|${IRCLIB}|g" ${WRKSRC}/include/config.h.dist

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ninja ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ninjawserv ${PREFIX}/bin
	@${MKDIR} ${IRCLIB}/translation
	${INSTALL_DATA} ${WRKSRC}/translation/* ${IRCLIB}/translation

.include <bsd.port.mk>
