# New ports collection makefile for:	p5-ePerl
# Version required:	2.2.1
# Date created:		Mon Aug  4 08:42:20 MET DST 1997
# Whom:	      		Ralf S. Engelschall <rse@engelschall.com>
#
# $Id$
#

DISTNAME=	eperl-2.2.1
PKGNAME=	p5-ePerl-2.2.1
CATEGORIES=	lang www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://www.engelschall.com/sw/eperl/distrib/ \
		ftp://ftp.engelschall.com/sw/
MASTER_SITE_SUBDIR=Parse

MAINTAINER=	rse@engelschall.com

USE_PERL5=	YES

MAN3=		Parse::ePerl.3 Apache::ePerl.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
