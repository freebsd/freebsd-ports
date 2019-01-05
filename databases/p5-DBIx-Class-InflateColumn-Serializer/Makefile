# $FreeBSD$

PORTNAME=	DBIx-Class-InflateColumn-Serializer
PORTVERSION=	0.09
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Inflators to serialize data structures for DBIx::Class

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-JSON-MaybeXS>=1.002005:converters/p5-JSON-MaybeXS \
		p5-DBIx-Class>=0:databases/p5-DBIx-Class \
		p5-namespace-clean>=0:devel/p5-namespace-clean \
		p5-YAML>=0:textproc/p5-YAML
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5

NO_ARCH=	yes
USE_PERL5=	configure

.include <bsd.port.mk>
