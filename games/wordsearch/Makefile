PORTNAME=	wordsearch
DISTVERSION=	2.1
CATEGORIES=	games
MASTER_SITES=	https://github.com/jensenpat/wordsearch/releases/download/${DISTVERSION}/

MAINTAINER=	patj@passpackets.com
COMMENT=	Classic word search game that you can play in your terminal

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.8+ shebangfix
SHEBANG_FILES=	wordsearch
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${REINPLACE_CMD} -e 's|/usr/games|${PREFIX}/bin|' ${WRKSRC}/man/wordsearch.6
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/wordsearch ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man6/
	${INSTALL_MAN} ${WRKSRC}/man/wordsearch.6 ${STAGEDIR}${PREFIX}/share/man/man6/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/wordsearch/
	${INSTALL_DATA} ${WRKSRC}/puzzles/*.txt ${STAGEDIR}${PREFIX}/share/wordsearch/

.include <bsd.port.mk>
