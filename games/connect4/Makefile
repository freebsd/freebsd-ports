# New ports collection makefile for:  connect4
# Date created:		Thu May  8 16:41:01 EST 1997
# Whom:			Joel Sutton <jsutton@bbcon.com.au>
#
# $FreeBSD$
#

PORTNAME=	connect4
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_COMP_SOURCES}
MASTER_SITE_SUBDIR=	games/volume6
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A curses version of the classic game

EXTRACT_DEPENDS=gunshar:${PORTSDIR}/archivers/sharutils

EXTRACT_CMD=		${GZCAT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	| gunshar

NO_WRKSUBDIR=	yes
MAN6=		connect4.6

do-install:
	${INSTALL_PROGRAM} -m 2755 -o root -g games ${WRKSRC}/c4 ${PREFIX}/bin/connect4
	@${MKDIR} ${PREFIX}/share/connect4
	${INSTALL_DATA} -m 664 -o root -g games /dev/null ${PREFIX}/share/connect4/scores
	${INSTALL_MAN} ${FILESDIR}/connect4.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
