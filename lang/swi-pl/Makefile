# New ports collection makefile for: SWI-Prolog
# Version required:		2.7.15
# Date created:			10 August 1996
# Whom:				Michael Butschky <butsch@computi.erols.com>
#
# $Id: Makefile,v 1.5 1996/11/12 02:19:12 obrien Exp $              
#

DISTNAME=	pl-2.7.15
PKGNAME=	swi-pl-2.7.15
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
