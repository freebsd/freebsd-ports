# New ports collection makefile for:    p5-SQL-Statement
# Date created:				August 8th, 1999
# Whom:	      				wolman@cs.washington.edu
#
# $FreeBSD$
#

PORTNAME=	SQL-Statement
PORTVERSION=	1.20
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A perl5 module for SQL parsing and processing

RUN_DEPENDS=	p5-Clone>=0.30:${PORTSDIR}/devel/p5-Clone \
		p5-Params-Util>=0.35:${PORTSDIR}/devel/p5-Params-Util
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SQL::Eval.3 \
		SQL::Parser.3 \
		SQL::Statement.3 \
		SQL::Statement::Embed.3 \
		SQL::Statement::Functions.3 \
		SQL::Statement::Structure.3 \
		SQL::Statement::Syntax.3

.include <bsd.port.mk>
