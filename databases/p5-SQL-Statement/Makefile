# New ports collection makefile for:    p5-SQL-Statement
# Date created:				August 8th, 1999
# Whom:	      				wolman@cs.washington.edu
#
# $FreeBSD$
#

PORTNAME=	SQL-Statement
PORTVERSION=	1.004
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SQL
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A perl5 module for SQL parsing and processing

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		SQL::Dialects::ANSI.3 SQL::Dialects::AnyData.3 \
		SQL::Dialects::CSV.3 SQL::Eval.3 SQL::Parser.3 SQL::Statement.3

.include <bsd.port.mk>
