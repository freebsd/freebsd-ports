# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-Helpers
PORTVERSION=	2.035000
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplify the common case stuff for DBIx::Class

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Carp-Clan>=6.04:devel/p5-Carp-Clan \
		p5-DBIx-Class>=0.082600:databases/p5-DBIx-Class \
		p5-DBIx-Class-Candy>=0.003001:databases/p5-DBIx-Class-Candy \
		p5-DBIx-Introspector>=0.001002:databases/p5-DBIx-Introspector \
		p5-Lingua-EN-Inflect>=0:textproc/p5-Lingua-EN-Inflect \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=2:devel/p5-Moo \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Sub-Exporter-Progressive>=0.001006:devel/p5-Sub-Exporter-Progressive \
		p5-Text-Brew>=0:textproc/p5-Text-Brew \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-namespace-clean>=0.23:devel/p5-namespace-clean
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DateTime-Format-SQLite>=0:devel/p5-DateTime-Format-SQLite \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Fatal>=0.006:devel/p5-Test-Fatal \
		p5-Test-Roo>=1.003:devel/p5-Test-Roo \
		p5-aliased>=0.34:devel/p5-aliased

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
