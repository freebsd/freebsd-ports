# New ports collection makefile for:   cim
# Version required:		1.84
# Date created:			21 Sept 1996
# Whom:				Pedro
#
# $Id: Makefile,v 1.1.1.1 1996/12/04 08:01:30 obrien Exp $
#

DISTNAME=	cim-1.84
CATEGORIES=	lang
MASTER_SITES=	ftp://ifi.uio.no/pub/cim/  \
		ftp://ftp.fenk.wau.nl/pub/lang/simula/compilers/cim/

MAINTAINER=	pgiffuni@FPS.biblos.unal.edu.co

STRIP=
GNU_CONFIGURE= 	yes 
ALL_TARGET=		all check
MAN1=			cim.1

post-install:
	@strip ${PREFIX}/bin/cim
	@strip $(PREFIX/bin/cimetags
.if defined(NOPORTDOCS)
	@${RM} ${PREFIX}/doc/cim.ps
	@${RM} ${PREFIX}/doc/cim.info
.endif

.include <bsd.port.mk>
