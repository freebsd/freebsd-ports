# New ports collection makefile for:	frotz
# Version required:			2.32
# Date created:				16 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		UnixFrotz232R2Std10
PKGNAME=		frotz-2.32
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.gmd.de/if-archive/infocom/interpreters/frotz/

MAINTAINER=		ports@FreeBSD.org

ALL_TARGET=
WRKSRC=			${WRKDIR}/frotz-2.32

MAN6=			frotz.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/frotz ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/frotz.6 ${PREFIX}/man/man6

.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/frotz
.for file in Readme.unix Todo
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/frotz
.endfor
.endif

.include <bsd.port.mk>
