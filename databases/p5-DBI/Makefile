# New ports collection makefile for:	p5-DBI
# Version required:			0.83
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.7 1997/06/18 19:28:15 jfitz Exp $
#

DISTNAME=	DBI-0.83
PKGNAME=	p5-DBI-0.83
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBI

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		DBI.3 DBI::W32ODBC.3 DBI::FAQ.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
