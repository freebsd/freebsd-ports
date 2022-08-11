PORTNAME=	tircproxy
PORTVERSION=	0.4.5
PORTREVISION=	4
CATEGORIES=	irc
MASTER_SITES=	http://bre.klaki.net/programs/tircproxy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC proxy server

WRKSRC=		${WRKDIR}/tircproxy-0.4
GNU_CONFIGURE=	YES

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tircproxy ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
