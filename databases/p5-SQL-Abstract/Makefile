# New ports collection makefile for:	SQL-Abstract
# Date created:	   18 Feb 2003
# Whom:		   Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	SQL-Abstract
PORTVERSION=	1.57
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to generate SQL from Perl data structures

RUN_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils

PERL_CONFIGURE=	yes

MAN3=		SQL::Abstract.3 \
		SQL::Abstract::Test.3

post-extract:
	@${PERL} -i -ne 'print unless m,^test,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
