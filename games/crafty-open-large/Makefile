# Created by: Stefan Eggers <seggers@semyam.dinoco.de>
# $FreeBSD$

PORTNAME=	crafty-open-large
PORTVERSION=	20070909
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dd/crafty
DISTFILES=	large1.zip large2.zip large3.zip large4.zip

MAINTAINER=	flo@FreeBSD.org
COMMENT=	The large opening book for crafty

BUILD_DEPENDS=	crafty:${PORTSDIR}/games/crafty
RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty

DIST_SUBDIR=	crafty
USES=		zip
NO_WRKSUBDIR=	yes
CONFLICTS=	crafty-open-enormous-* crafty-open-medium-* crafty-open-default-*

NO_STAGE=	yes
post-extract:
	@${ECHO_MSG} '================================================================'
	@${ECHO_MSG} 'Ignore warnings about illegal moves.  These warnings are normal.'
	@${ECHO_MSG} '================================================================'
	${CAT} ${WRKDIR}/Book1.pgn ${WRKDIR}/Book2.pgn ${WRKDIR}/Book3.pgn ${WRKDIR}/Book4.pgn >${WRKDIR}/Book.pgn
	${RM} ${WRKDIR}/Book1.pgn ${WRKDIR}/Book2.pgn ${WRKDIR}/Book3.pgn ${WRKDIR}/Book4.pgn

do-build:
	(${CHOWN} nobody ${WRKDIR}; cd ${WRKDIR}; crafty <${FILESDIR}/book-building)

do-install:
	${MKDIR} ${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKDIR}/book.bin ${PREFIX}/lib/crafty/book.bin
	${CHOWN} nobody:nogroup ${PREFIX}/lib/crafty/book.bin
	${CHMOD} 664 ${PREFIX}/lib/crafty/book.bin

.include <bsd.port.mk>
