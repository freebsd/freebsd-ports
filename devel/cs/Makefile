# New ports collection makefile for:	cs
# Version required:	0.3
# Date created:		22 May 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1997/05/23 07:58:58 tg Exp $
#

DISTNAME=	cs-0.3
CATEGORIES=	devel
MASTER_SITES=	ftp://cantor.informatik.rwth-aachen.de/pub/unix/

MAINTAINER=	andy@icc.surw.chel.su

NO_CDROM=	this port requires a written license
ALL_TARGET=	cs
MAN1=		cs.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cs.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
