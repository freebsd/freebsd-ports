# Created by: Hideyuki KURASHINA <rushani@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yasou-fpw
PORTVERSION=	1.0.b0
CATEGORIES=	japanese
MASTER_SITES=	ftp://relay1.tomsk.gov.ru/pub/FreeBSD/ports/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.b0/beta0/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yasou picture book (EPWING V1 format) by SAS

NO_CDROM=	No commercial use, and no redistribution allowed with fee except media and/or shipping cost
DEPRECATED=		the only remaining mastersite times out
EXPIRATION_DATE=	2019-10-22

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/yasou
EXTRACT_BEFORE_ARGS=	-qL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/yasou-fpw/yasou/data
	${INSTALL_DATA} ${WRKSRC}/yasou/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/yasou-fpw/yasou/data
	${INSTALL_DATA} ${WRKSRC}/catalogs \
		${STAGEDIR}${PREFIX}/share/dict/yasou-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} readme.fpw yasoufpw.txt \
	       ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
