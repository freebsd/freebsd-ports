# New ports collection makefile for:	mp3info
# Version required:			0.2.15
# Date created:				19 June 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		mp3info-0.2.15
CATEGORIES=		audio
MASTER_SITES=		ftp://bimbo.hive.no/pub/mp3info/

MAINTAINER=		andy@icc.surw.chel.su

MAN1=			mp3info.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/mp3info ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/mp3info.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/mp3info
.for file in COPYRIGHT ChangeLog README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/mp3info
.endfor
.endif

.include <bsd.port.mk>
