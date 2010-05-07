# New ports collection makefile for:    p5-SQL-Statement
# Date created:				August 8th, 1999
# Whom:	      				wolman@cs.washington.edu
#
# $FreeBSD$
#

PORTNAME=	SQL-Statement
PORTVERSION=	1.27
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A perl5 module for SQL parsing and processing

RUN_DEPENDS=	p5-Clone>=0.30:${PORTSDIR}/devel/p5-Clone \
		p5-Params-Util>=1.00:${PORTSDIR}/devel/p5-Params-Util
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SQL::Dialects::ANSI.3 \
		SQL::Dialects::AnyData.3 \
		SQL::Dialects::CSV.3 \
		SQL::Dialects::Role.3 \
		SQL::Eval.3 \
		SQL::Parser.3 \
		SQL::Statement.3 \
		SQL::Statement::Embed.3 \
		SQL::Statement::Function.3 \
		SQL::Statement::Functions.3 \
		SQL::Statement::GetInfo.3 \
		SQL::Statement::Operation.3 \
		SQL::Statement::Placeholder.3 \
		SQL::Statement::RAM.3 \
		SQL::Statement::Structure.3 \
		SQL::Statement::Syntax.3 \
		SQL::Statement::Term.3 \
		SQL::Statement::TermFactory.3 \
		SQL::Statement::Util.3

.include <bsd.port.mk>
