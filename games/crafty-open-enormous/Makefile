# New ports collection makefile for:	crafty-open-enormous
# Date created:			9 Sep 2007
# Whom:				Jonathan Shoemaker <shoemaker@bluebottle.com>
#
# $FreeBSD$
#

PORTNAME=	crafty-open-enormous
PORTVERSION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cis.uab.edu/pub/hyatt/pgn/ \
		${MASTER_SITE_LOCAL}
DISTFILES=	enormous.zip
EXTRACT_ONLY=	${DISTFILES}

MAINTAINER=	shoemaker@bluebottle.com
COMMENT=	The enormous opening book (about 85-90 MByte) for crafty

BUILD_DEPENDS=	crafty:${PORTSDIR}/games/crafty
RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty

DIST_SUBDIR=		crafty
USE_ZIP=		yes
NO_WRKSUBDIR=		yes
NO_PACKAGE=		Package is way too big

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		dumps core during build
.endif

do-build:
	@${ECHO_MSG} '================================================================'
	@${ECHO_MSG} 'Ignore warnings about illegal moves.  These warnings are normal.'
	@${ECHO_MSG} '================================================================'
	(cd ${WRKDIR}; ${CHOWN} nobody ${WRKDIR}; crafty bookpath=. <${FILESDIR}/book-building)

do-install:
	${MKDIR} ${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKDIR}/book.bin ${PREFIX}/lib/crafty/book.bin
	${CHOWN} nobody:nogroup ${PREFIX}/lib/crafty/book.bin
	${CHMOD} 664 ${PREFIX}/lib/crafty/book.bin

.include <bsd.port.post.mk>
