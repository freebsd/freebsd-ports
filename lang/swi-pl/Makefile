# New ports collection makefile for: SWI-Prolog
# Version required:		2.7.18
# Date created:			10 August 1996
# Whom:				Michael Butschky <butsch@computi.erols.com>
#
# $Id: Makefile,v 1.7 1996/11/16 16:25:10 max Exp $              
#

DISTNAME=	pl-2.7.18
PKGNAME=	swi-pl-2.7.18
CATEGORIES=     lang
MASTER_SITES=	ftp://swi.psy.uva.nl/pub/SWI-Prolog/

MAINTAINER=	max@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	i386-freebsd
STRIP=
MAKE_FLAGS+=	CIFLAGS=-DRTLD_LAZY -f
MAN1=		pl.1 chpl.1 plld.1

post-install:
.for f in pl pl-bite chpl
	@strip ${PREFIX}/lib/${DISTNAME}/bin/i386-freebsd/$f
.endfor

.include <bsd.port.mk>
