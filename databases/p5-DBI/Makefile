# New ports collection makefile for:	p5-DBI
# Version required:			0.91
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.10 1997/09/13 17:53:19 jfitz Exp $
#

DISTNAME=	DBI-0.91
PKGNAME=	p5-DBI-0.91
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBI

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

MAN3=		DBI.3 DBI::W32ODBC.3 DBI::FAQ.3 DBI::DBD.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
