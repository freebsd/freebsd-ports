# New ports collection makefile for:	cs
# Version required:			0.5
# Date created:				22 May 1997
# Whom:					Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1997/06/05 07:36:51 tg Exp $
#

DISTNAME=	cs-0.5
CATEGORIES=	devel
MASTER_SITES=	ftp://cantor.informatik.rwth-aachen.de/pub/unix/

MAINTAINER=	andy@icc.surw.chel.su

NO_CDROM=	this port requires a written license
ALL_TARGET=	cs
MAN1=		cs.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/cs ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/cs.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/cs
	@ ${INSTALL_DATA} ${WRKSRC}/ANNOUNCE ${PREFIX}/share/doc/cs
	@ ${INSTALL_DATA} ${WRKSRC}/cs.html ${PREFIX}/share/doc/cs
.endif

.include <bsd.port.mk>
