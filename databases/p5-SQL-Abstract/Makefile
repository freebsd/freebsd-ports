# Created by: Dominic Mitchell
# $FreeBSD$

PORTNAME=	SQL-Abstract
PORTVERSION=	1.87
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to generate SQL from Perl data structures

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Hash-Merge>=0.12:textproc/p5-Hash-Merge \
		p5-MRO-Compat>=0.12:devel/p5-MRO-Compat \
		p5-Moo>=2.000001:devel/p5-Moo \
		p5-Sub-Quote>=2.000001:devel/p5-Sub-Quote \
		p5-Test-Deep>=0.101:devel/p5-Test-Deep
TEST_DEPENDS=	p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-Test-Exception>=0.31:devel/p5-Test-Exception \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
