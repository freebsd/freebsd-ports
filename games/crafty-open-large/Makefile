# New ports collection makefile for:	crafty-open-large
# Date created:				1 June 1998
# Whom:					Stefan Eggers <seggers@semyam.dinoco.de>
#
# $FreeBSD$
#

PORTNAME=	crafty-open-large
PORTVERSION=	19960910
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dd/crafty
DISTFILES=	large1.zip large2.zip large3.zip large4.zip

MAINTAINER=	seggers@semyam.dinoco.de
COMMENT=	The large opening book for crafty

BUILD_DEPENDS=	crafty:${PORTSDIR}/games/crafty
RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty

DIST_SUBDIR=		crafty
USE_ZIP=		yes
NO_WRKSUBDIR=		yes

post-extract:
	@${ECHO_MSG} '================================================================'
	@${ECHO_MSG} 'Ignore warnings about illegal moves.  These warnings are normal.'
	@${ECHO_MSG} '================================================================'
	${CAT} ${WRKDIR}/Book1.pgn ${WRKDIR}/Book2.pgn ${WRKDIR}/Book3.pgn ${WRKDIR}/Book4.pgn >${WRKDIR}/Book.pgn
	${RM} ${WRKDIR}/Book1.pgn ${WRKDIR}/Book2.pgn ${WRKDIR}/Book3.pgn ${WRKDIR}/Book4.pgn

do-build:
	(cd ${WRKDIR}; crafty <${FILESDIR}/book-building)

do-install:
	${MKDIR} ${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKDIR}/book.bin ${PREFIX}/lib/crafty/large-book.bin

.include <bsd.port.mk>
