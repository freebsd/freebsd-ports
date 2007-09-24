# New ports collection makefile for:	crafty-open-medium
# Date created:				1 June 1998
# Whom:					Stefan Eggers <seggers@semyam.dinoco.de>
#
# $FreeBSD$
#

PORTNAME=	crafty-open-medium
PORTVERSION=	20070909
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dd/crafty
DISTNAME=	medium

MAINTAINER=	shoemaker@bluebottle.com
COMMENT=	The medium opening book (about 1.9 MByte) for crafty

BUILD_DEPENDS=	crafty:${PORTSDIR}/games/crafty
RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty

DIST_SUBDIR=	crafty
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
CONFLICTS=	crafty-open-enormous-* crafty-open-large-*

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		dumps core during builds
.endif

do-build:
	@${ECHO_MSG} '================================================================'
	@${ECHO_MSG} 'Ignore warnings about illegal moves.  These warnings are normal.'
	@${ECHO_MSG} '================================================================'
	(${CHOWN} nobody ${WRKDIR}; cd ${WRKDIR}; crafty <${FILESDIR}/book-building)

do-install:
	${MKDIR} ${PREFIX}/lib/crafty
	${INSTALL_DATA} ${WRKDIR}/book.bin ${PREFIX}/lib/crafty/book.bin
	${CHOWN} nobody:nogroup ${PREFIX}/lib/crafty/book.bin
	${CHMOD} 664 ${PREFIX}/lib/crafty/book.bin

.include <bsd.port.post.mk>
