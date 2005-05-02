# New ports collection makefile for:    p5-SQL-Statement
# Date created:				August 8th, 1999
# Whom:	      				wolman@cs.washington.edu
#
# $FreeBSD$
#

PORTNAME=	SQL-Statement
PORTVERSION=	1.14
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SQL
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A perl5 module for SQL parsing and processing

PERL_CONFIGURE=	yes

MAN3=		SQL::Eval.3 \
		SQL::Parser.3 \
		SQL::Statement.3 \
		SQL::Statement::Embed.3 \
		SQL::Statement::Functions.3 \
		SQL::Statement::Structure.3 \
		SQL::Statement::Syntax.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
IGNORE=	requires Perl 5.6. Intall lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
