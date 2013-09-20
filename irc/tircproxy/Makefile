# Created by: Eugeny Kuzakov <CoreDumped@CoreDumped.null.ru>
# $FreeBSD$

PORTNAME=	tircproxy
PORTVERSION=	0.4.5
PORTREVISION=	4
CATEGORIES=	irc
MASTER_SITES=	http://bre.klaki.net/programs/tircproxy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC proxy server

WRKSRC=		${WRKDIR}/tircproxy-0.4
GNU_CONFIGURE=	YES

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tircproxy ${PREFIX}/sbin

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing tircproxy docs in ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
