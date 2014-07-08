# Created by: Ozkan KIRIK <ozkan@enderunix.org>
# $FreeBSD$

PORTNAME=	checkdns
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.enderunix.org/checkdns/ \
		http://www.trunix.org/projeler/checkdns/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Domain name server analysis and reporting tool

SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL README THANKS TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/main.c \
		${WRKSRC}/INSTALL ${WRKSRC}/README ${WRKSRC}/checkdns.conf-dist
	@${REINPLACE_CMD} -e 's|CC = gcc|CC = ${CC} -include string.h|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checkdns ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/checkdns.conf-dist ${STAGEDIR}${PREFIX}/etc/
	${MKDIR} ${STAGEDIR}${DATADIR}/lang
	${INSTALL_DATA} ${WRKSRC}/checkdns.css ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lang/* ${STAGEDIR}${DATADIR}/lang
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
