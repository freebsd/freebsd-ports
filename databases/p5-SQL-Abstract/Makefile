# New ports collection makefile for:	SQL-Abstract
# Date created:	   18 Feb 2003
# Whom:		   Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	SQL-Abstract
PORTVERSION=	1.68
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to generate SQL from Perl data structures

BUILD_DEPENDS=	p5-Class-Accessor-Grouped>=0.09005:${PORTSDIR}/devel/p5-Class-Accessor-Grouped \
		p5-Hash-Merge>=0.12:${PORTSDIR}/textproc/p5-Hash-Merge
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		SQL::Abstract.3 \
		SQL::Abstract::Test.3 \
		SQL::Abstract::Tree.3 \
		DBIx::Class::Storage::Debug::PrettyPrint.3

post-extract:
	@${PERL} -i -ne 'print unless m,^test,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
