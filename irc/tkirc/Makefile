# New ports collection makefile for:    tkirc
# Date created:         Jan 15 1998
# Whom:                 brianfeldman@hotmail.com
#
# $FreeBSD$
#

PORTNAME=	tkirc
PORTVERSION=	2.46
PORTREVISION=	3
CATEGORIES=	irc tk
MASTER_SITES=	http://netsplit.de/tkirc2/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI for the ircII Internet Relay Chat client

RUN_DEPENDS=	irc:${PORTSDIR}/irc/ircII

USE_TK_RUN=	yes
WRKSRC=		${WRKDIR}/tkirc2
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} 's|wish8\.3|${WISH}|;' ${WRKSRC}/tkirc2

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkirc2 ${PREFIX}/bin
	${LN} -f ${PREFIX}/bin/tkirc2 ${PREFIX}/bin/tkirc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${MV} ${WRKSRC}/.tkirc2/.data ${WRKSRC}/.tkirc2/DOTdata
	${CP} -r ${WRKSRC}/.tkirc2 ${EXAMPLESDIR}/DOTtkirc2
.endif

.include <bsd.port.mk>
