# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-Helpers
PORTVERSION=	2.032000
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Simplify the common case stuff for DBIx::Class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Carp-Clan>=0:devel/p5-Carp-Clan \
		p5-DBIx-Class>=0.08123:databases/p5-DBIx-Class \
		p5-DBIx-Class-Candy>=0:databases/p5-DBIx-Class-Candy \
		p5-DBIx-Introspector>=0:databases/p5-DBIx-Introspector \
		p5-Lingua-EN-Inflect>=0:textproc/p5-Lingua-EN-Inflect \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-String-CamelCase>=0:textproc/p5-String-CamelCase \
		p5-Sub-Exporter-Progressive>=0:devel/p5-Sub-Exporter-Progressive \
		p5-Text-Brew>=0:textproc/p5-Text-Brew \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-namespace-clean>=0:devel/p5-namespace-clean
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception \
		p5-Test-Simple>=0:devel/p5-Test-Simple \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DateTime-Format-SQLite>=0:devel/p5-DateTime-Format-SQLite

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
