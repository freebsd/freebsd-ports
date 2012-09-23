# Created by: Girish <girish.rao.dev@gmail.com>
# $FreeBSD$

PORTNAME=	spellathon
PORTVERSION=	5.79
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Word game to test your English vocabulary skills

USE_QT4=	gui moc_build qmake_build rcc_build uic_build

post-patch:
	@${REINPLACE_CMD} 's|qmake|qmake-qt4|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|dict/words.txt|${DATADIR}/words.txt|' \
		${WRKSRC}/src/logic/defines.h

do-install:
	${INSTALL} ${WRKSRC}/spellathon ${PREFIX}/bin
	${INSTALL} ${WRKSRC}/spellathon-cl ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dict/words.txt ${DATADIR}

.include <bsd.port.mk>
