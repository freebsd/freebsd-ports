# New ports collection makefile for:    p5-SQL-Statement
# Date created:				August 8th, 1999
# Whom:	      				wolman@cs.washington.edu
#
# $FreeBSD$
#

PORTNAME=	p5-SQL-Statement
PORTVERSION=	0.1016
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SQL
DISTNAME=	SQL-Statement-${PORTVERSION}

MAINTAINER=	wolman@cs.washington.edu

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		SQL::Eval.3 SQL::Statement.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
