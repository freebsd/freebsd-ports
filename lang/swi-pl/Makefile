# New ports collection makefile for: SWI-Prolog
# Version required:		2.7.15
# Date created:			10 August 1996
# Whom:				Michael Butschky <butsch@computi.erols.com>
#
# $Id: Makefile,v 1.2 1996/10/29 06:33:58 max Exp $              
#

DISTNAME=	pl-2.7.15
PKGNAME=	swi-pl-2.7.15
CATEGORIES+=    lang
MASTER_SITES=	ftp://swi.psy.uva.nl/pub/SWI-Prolog/

MAINTAINER=	max@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	i386-freebsd
STRIP=
MAKE_FLAGS+=	CIFLAGS=-DRTLD_LAZY -f

post-install:
.for f in pl pl-bite chpl
	@strip ${PREFIX}/lib/${DISTNAME}/bin/i386-freebsd/$f
.endfor
.if !defined(NOMANCOMPRESS)
.for f in pl.1 chpl.1 plld.1
	gzip -9nf ${PREFIX}/man/man1/$f
.endfor
.endif

.include <bsd.port.mk>
