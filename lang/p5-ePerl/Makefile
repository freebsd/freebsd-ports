# New ports collection makefile for:	p5-ePerl
# Version required:	2.2.4
# Date created:		Mon Sep  1 16:06:31 MET DST 1997
# Whom:	      		Ralf S. Engelschall <rse@engelschall.com>
#
# $Id: Makefile,v 1.3 1997/08/21 15:45:56 rse Exp $
#

DISTNAME=	eperl-2.2.4
PKGNAME=	p5-ePerl-2.2.4
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
