# Created by: Cyrille Lefevre <clefevre@citeweb.net>
# $FreeBSD$

PORTNAME=	dico
PORTVERSION=	1.1
PORTREVISION=	8
CATEGORIES=	french
MASTER_SITES=	ftp://ftp.supelec.fr/lsi/pub/security/
DISTNAME=	le_dico

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive dictionary in french

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

BROKEN_WWW=	http://www.montefiore.ulg.ac.be/cgi-bin-ulg/DICO.html

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC}/sources && ${CC} ${CFLAGS} ${LDFLAGS} -o dico dico.c)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sources/dico ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lexique/*.dic ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuel/copying.doc ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/manuel/dico.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-patch:
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},' \
		${WRKSRC}/README.TXT ${WRKSRC}/manuel/dico.1 \
		${WRKSRC}/sources/dico.c

.include <bsd.port.mk>
