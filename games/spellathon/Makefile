# New ports collection makefile for: spellathon
# Date created:                7 May 2009
# Whom:                        girish
#
# $FreeBSD$
#

PORTNAME=	spellathon
PORTVERSION=	5.21
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	girish.rao.dev@gmail.com
COMMENT=	Word game to test your English vocabulary skills

USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build rcc_build uic_build

post-patch:
	@${REINPLACE_CMD} 's|qmake|qmake-qt4|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|dict/words.txt|${DATADIR}/words.txt|' \
		${WRKSRC}/src/logic/defines.h

do-install:
	${INSTALL} ${WRKSRC}/spellathon ${PREFIX}/bin
	${INSTALL} ${WRKSRC}/spellathon-cl ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dict/words.txt ${DATADIR}

.include <bsd.port.mk>
