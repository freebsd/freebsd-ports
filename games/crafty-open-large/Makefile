# Created by: Stefan Eggers <seggers@semyam.dinoco.de>
# $FreeBSD$

PORTNAME=	crafty-open-large
PORTVERSION=	20070909
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	LOCAL/dd/crafty
DISTFILES=	large1.zip large2.zip large3.zip large4.zip
DIST_SUBDIR=	crafty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Large opening book for crafty

BUILD_DEPENDS=	crafty:games/crafty
RUN_DEPENDS=	crafty:games/crafty

USES=		zip
NO_WRKSUBDIR=	yes
CONFLICTS=	crafty-open-enormous-* crafty-open-medium-* crafty-open-default-*

post-extract:
	${CAT} ${WRKSRC}/Book1.pgn ${WRKSRC}/Book2.pgn ${WRKSRC}/Book3.pgn ${WRKSRC}/Book4.pgn >${WRKSRC}/Book.pgn
	${RM} ${WRKSRC}/Book1.pgn ${WRKSRC}/Book2.pgn ${WRKSRC}/Book3.pgn ${WRKSRC}/Book4.pgn

do-build:
	@${ECHO_MSG} '================================================================'
	@${ECHO_MSG} 'Ignore warnings about illegal moves.  These warnings are normal.'
	@${ECHO_MSG} '================================================================'
	(cd ${WRKSRC} && crafty <${FILESDIR}/book-building)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKSRC}/book.bin ${STAGEDIR}${PREFIX}/lib/crafty/book.bin

.include <bsd.port.mk>
