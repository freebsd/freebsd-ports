# New ports collection makefile for:   cim
# Version required:		1.92
# Date created:			21 Sept 1996
# Whom:				Pedro
#
# $Id: Makefile,v 1.4 1997/07/21 03:14:35 obrien Exp $
#

DISTNAME=	cim-1.92
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/cim/  \
		${MASTER_SITE_SUNSITE}  \
		ftp://ftp.fenk.wau.nl/pub/lang/simula/compilers/cim/
MASTER_SITE_SUBDIR=	devel/lang/simula

MAINTAINER=	giffunip@asme.org

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
