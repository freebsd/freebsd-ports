# New ports collection makefile for:	crafty-open-small
# Version required:			1 March 1997
# Date created:				1 June 1998
# Whom:					Stefan Eggers <seggers@semyam.dinoco.de>
#
# $FreeBSD$
#

DISTNAME=	small
PKGNAME=	crafty-open-small-19970301
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cis.uab.edu/pub/hyatt/common/

MAINTAINER=	seggers@semyam.dinoco.de

BUILD_DEPENDS=	crafty:${PORTSDIR}/games/crafty
RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty

DIST_SUBDIR=		crafty
USE_ZIP=		yes
NO_WRKSUBDIR=		yes

do-build:
	@${ECHO_MSG} '================================================================'
	@${ECHO_MSG} 'Ignore warnings about illegal moves.  These warnings are normal.'
	@${ECHO_MSG} '================================================================'
	(cd ${WRKDIR}; crafty <${FILESDIR}/book-building)

do-install:
	${MKDIR} ${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKDIR}/book.bin ${PREFIX}/lib/crafty/small-book.bin

.include <bsd.port.mk>
