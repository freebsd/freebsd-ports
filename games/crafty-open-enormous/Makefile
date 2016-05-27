# Created by: Jonathan Shoemaker <shoemaker@bluebottle.com>
# $FreeBSD$

PORTNAME=	crafty-open-enormous
PORTVERSION=	20070924
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.cis.uab.edu/hyatt/crafty/pgn/
DISTFILES=	enormous.zip
DIST_SUBDIR=	crafty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enormous opening book (about 270 MByte) for crafty

BUILD_DEPENDS=	crafty:games/crafty
RUN_DEPENDS=	crafty:games/crafty

USES=		zip
NO_WRKSUBDIR=	yes
CONFLICTS=	crafty-open-large-* crafty-open-medium-* crafty-open-default-*

do-build:
	@${ECHO_MSG} '================================================================'
	@${ECHO_MSG} 'Ignore warnings about illegal moves.  These warnings are normal.'
	@${ECHO_MSG} '================================================================'
	(cd ${WRKSRC} && crafty bookpath=. <${FILESDIR}/book-building)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKSRC}/book.bin ${STAGEDIR}${PREFIX}/lib/crafty/book.bin

.include <bsd.port.mk>
