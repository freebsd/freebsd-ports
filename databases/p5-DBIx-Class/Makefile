# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class
PORTVERSION=	0.082821
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extensible and flexible object <-> relational mapper

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor-Grouped>=0.10012:devel/p5-Class-Accessor-Grouped \
		p5-Class-C3-Componentised>=1.0009:devel/p5-Class-C3-Componentised \
		p5-Class-Inspector>=1.24:devel/p5-Class-Inspector \
		p5-Class-Method-Modifiers>=1.06:devel/p5-Class-Method-Modifiers \
		p5-Config-Any>=0.20:devel/p5-Config-Any \
		p5-Context-Preserve>=0.01:devel/p5-Context-Preserve \
		p5-DBI>=1.57:databases/p5-DBI \
		p5-Data-Compare>=1.2200:devel/p5-Data-Compare \
		p5-Data-Dumper-Concise>=2.020:devel/p5-Data-Dumper-Concise \
		p5-Data-Page>=2.00:databases/p5-Data-Page \
		p5-Devel-GlobalDestruction>=0.09:devel/p5-Devel-GlobalDestruction \
		p5-Hash-Merge>=0.12:textproc/p5-Hash-Merge \
		p5-MRO-Compat>=0.09:devel/p5-MRO-Compat \
		p5-Module-Find>=0.07:devel/p5-Module-Find \
		p5-Moo>=2:devel/p5-Moo \
		p5-Path-Class>=0.18:devel/p5-Path-Class \
		p5-SQL-Abstract>=1.81:databases/p5-SQL-Abstract \
		p5-Scope-Guard>=0.03:devel/p5-Scope-Guard \
		p5-Sub-Name>=0.04:devel/p5-Sub-Name \
		p5-Try-Tiny>=0.07:lang/p5-Try-Tiny \
		p5-namespace-clean>=0.20:devel/p5-namespace-clean \
		p5-strictures>=1.003001:devel/p5-strictures
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Class-DBI-Plugin-DeepAbstractSearch>=0:databases/p5-Class-DBI-Plugin-DeepAbstractSearch \
		p5-DBD-SQLite>=1.29:databases/p5-DBD-SQLite \
		p5-DateTime>=0.55:devel/p5-DateTime \
		p5-DateTime-Format-MySQL>=0:devel/p5-DateTime-Format-MySQL \
		p5-DateTime-Format-Pg>=0:devel/p5-DateTime-Format-Pg \
		p5-DateTime-Format-SQLite>=0:devel/p5-DateTime-Format-SQLite \
		p5-JSON-Any>=0:converters/p5-JSON-Any \
		p5-Math-Base36>=0.07:math/p5-Math-Base36 \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-MooseX-Types-JSON>=0:devel/p5-MooseX-Types-JSON \
		p5-MooseX-Types-LoadableClass>=0:devel/p5-MooseX-Types-LoadableClass \
		p5-MooseX-Types-Path-Class>=0.04:devel/p5-MooseX-Types-Path-Class \
		p5-SQL-Translator>=0.09.004:databases/p5-SQL-Translator \
		p5-Test-Exception>=0.31:devel/p5-Test-Exception \
		p5-Test-Warn>=0.21:devel/p5-Test-Warn \
		p5-Test-Deep>0.101:devel/p5-Test-Deep \
		p5-Text-CSV>=0:textproc/p5-Text-CSV \
		p5-Time-Piece>=0:devel/p5-Time-Piece \
		p5-Time-Piece-MySQL>=0:databases/p5-Time-Piece-MySQL \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

OPTIONS_DEFINE=	SQLT
SQLT_DESC=	SQL::Translator (generate DDL from schema)

PORTSCOUT=	limit:^[0-9\.]*$$

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	DBICTEST_NO_SQLITE_CHECK=1

SQLT_RUN_DEPENDS=	p5-SQL-Translator>=0.09.004:databases/p5-SQL-Translator

.include <bsd.port.mk>
