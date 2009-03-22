# New ports collection makefile for:	SQL-Abstract
# Date created:	   18 Feb 2003
# Whom:		   Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	SQL-Abstract
PORTVERSION=	1.50
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Perl extension to generate SQL from Perl data structures

RUN_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

PERL_CONFIGURE=	yes

MAN3=		SQL::Abstract.3 \
		SQL::Abstract::Test.3

post-extract:
	@${PERL} -i -ne 'print unless m,Test::,' ${WRKSRC}/Makefile.PL
	@${RM} -f ${WRKSRC}/lib/SQL/.Abstract.pm.swp
	@${PERL} -i -ne 'print unless m,Abstract.pm.swp,' ${WRKSRC}/MANIFEST

.include <bsd.port.mk>
