# New ports collection makefile for:	p5-Tcl
# Version required:			b1
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.3 1997/06/24 18:43:32 jfitz Exp $
#

DISTNAME=	Tcl-b1
PKGNAME=	p5-Tcl-b1
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tcl

MAINTAINER=	jfitz@FreeBSD.ORG

BROKEN=		tcl.h

USE_PERL5=	YES

WRKSRC=		${WRKDIR}/Tcl

MANPREFIX=	${PREFIX}/lib/perl5
MAN3=		Tcl.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
