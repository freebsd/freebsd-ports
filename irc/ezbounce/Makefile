# New ports collection makefile for:	ezbounce
# Date created:	 	19 February 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ezbounce
PORTVERSION=	0.99.11
CATEGORIES=	irc
MASTER_SITES=  	http://druglord.freelsd.org/ezbounce/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE= 	yes

post-patch:
	@${SED} -e "s:/path/to:${PREFIX}/sbin:" ${WRKSRC}/sample.conf > \
		${WRKSRC}/ezbounce.conf.default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ezbounce ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/mdidentd/mdidentd ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/ezbounce.conf.default ${PREFIX}/etc
.if !exists(${PREFIX}/etc/ezbounce.conf)
	${INSTALL_SCRIPT} ${WRKSRC}/ezbounce.conf.default \
		${PREFIX}/etc/ezbounce.conf
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ezbounce
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/ezbounce
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ezbounce
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/ezbounce
	${INSTALL_DATA} ${WRKSRC}/mdidentd/README \
		${PREFIX}/share/doc/ezbounce/mdidentd.README
.endif
	@${SED} -e "s:/usr/local:${PREFIX}:g" ${PKGMESSAGE}

.include <bsd.port.mk>
