# New ports collection makefile for:	frotz
# Version required:			2.32
# Date created:				16 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		UnixFrotz232R2Std10
PKGNAME=		frotz-2.32
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.gmd.de/if-archive/infocom/interpreters/frotz/

MAINTAINER=		andy@icc.surw.chel.su

ALL_TARGET=
WRKSRC=			${WRKDIR}/frotz-2.32

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/frotz ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/frotz
.for file in Readme.unix Todo
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/frotz
.endfor
.endif

.include <bsd.port.mk>
