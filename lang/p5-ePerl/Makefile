# New ports collection makefile for:	p5-ePerl
# Date created:		03-Sep-1997
# Whom:	      		Ralf S. Engelschall <rse@engelschall.com>
#
# $FreeBSD$
#

PORTNAME=	p5-ePerl
PORTVERSION=	2.2.14
CATEGORIES=	lang www perl5
MASTER_SITES=	http://www.engelschall.com/sw/eperl/distrib/ \
		ftp://ftp.engelschall.com/sw/eperl/ \
		ftp://ftp.hyperreal.org/software/engelschall/eperl/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Parse
DISTNAME=	eperl-2.2.14

MAINTAINER=	rse@engelschall.com

USE_PERL5=	YES

MAN3=		Parse::ePerl.3 Apache::ePerl.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
