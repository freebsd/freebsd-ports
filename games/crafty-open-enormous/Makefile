# Created by: Jonathan Shoemaker <shoemaker@bluebottle.com>
# $FreeBSD$

PORTNAME=	crafty-open-enormous
PORTVERSION=	20070924
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.cis.uab.edu/hyatt/crafty/pgn/ \
		${MASTER_SITE_LOCAL}
DISTFILES=	enormous.zip
EXTRACT_ONLY=	${DISTFILES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enormous opening book (about 270 MByte) for crafty

BUILD_DEPENDS=	crafty:${PORTSDIR}/games/crafty
RUN_DEPENDS=	${BUILD_DEPENDS}

DIST_SUBDIR=	crafty
USES=		zip
NO_WRKSUBDIR=	yes
NO_PACKAGE=	Package is way too big
CONFLICTS=	crafty-open-large-* crafty-open-medium-* crafty-open-default-*

do-build:
	@${ECHO_MSG} '================================================================'
	@${ECHO_MSG} 'Ignore warnings about illegal moves.  These warnings are normal.'
	@${ECHO_MSG} '================================================================'
	(cd ${WRKDIR}; ${CHOWN} nobody ${WRKDIR}; crafty bookpath=. <${FILESDIR}/book-building)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKDIR}/book.bin ${STAGEDIR}${PREFIX}/lib/crafty/book.bin
	${CHOWN} nobody:nogroup ${STAGEDIR}${PREFIX}/lib/crafty/book.bin
	${CHMOD} 664 ${STAGEDIR}${PREFIX}/lib/crafty/book.bin

.include <bsd.port.mk>
