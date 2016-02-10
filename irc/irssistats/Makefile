# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	irssistats
PORTVERSION=	0.75
CATEGORIES=	irc
MASTER_SITES=	http://royale.zerezo.com/irssistats/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate IRC statistics based on irssi logs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

ALL_TARGET=	irssistats

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/irssistats.conf|${PREFIX}/etc/irssistats.conf|g' ${WRKSRC}/irssistats.c
	@${REINPLACE_CMD} -e 's|gcc|$$(CC)|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${DATADIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.* ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
