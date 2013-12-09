# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	irssistats
PORTVERSION=	0.75
CATEGORIES=	irc
MASTER_SITES=	http://royale.zerezo.com/irssistats/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate IRC statistics based on irssi logs

LICENSE=	GPLv2

ALL_TARGET=	irssistats

post-patch:
	${REINPLACE_CMD} -e 's|/etc/irssistats.conf|${PREFIX}/etc/irssistats.conf|g' ${WRKSRC}/irssistats.c
	${REINPLACE_CMD} -e 's/gcc/$$(CC)/g' ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample.* ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
