# New ports collection makefile for:	sokoban
# Date created:				2 July 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		sokoban
PORTVERSION=		1.0
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
DISTFILES=		${PORTNAME}-src${EXTRACT_SUFX}

MAINTAINER=		ports@FreeBSD.org
COMMENT=	Logical game: problems with packets in cave

WRKSRC=			${WRKDIR}/sokoban
ALL_TARGET=

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/sokoban ${PREFIX}/bin/sokoban
	@ ${CHOWN} root:games ${PREFIX}/bin/sokoban
	@ ${CHMOD} 2555 ${PREFIX}/bin/sokoban
	@ ${MKDIR} ${PREFIX}/share/sokoban
	@ ${CHOWN} root:games ${PREFIX}/share/sokoban
	@ ${MKDIR} ${PREFIX}/share/sokoban/screens
	@ ${CHOWN} root:games ${PREFIX}/share/sokoban/screens
	@ ${INSTALL_DATA} ${WRKSRC}/screens/* ${PREFIX}/share/sokoban/screens
	@ ${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
