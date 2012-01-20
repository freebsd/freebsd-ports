# New ports collection makefile for:	p5-Test-DBIx-Class
# Date created:		2012-01-18
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-DBIx-Class
PORTVERSION=	0.28
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easier test cases for your DBIx::Class applications

SHARED_DEPENDS=	p5-Config-Any>=0.19:${PORTSDIR}/devel/p5-Config-Any \
		p5-DBIx-Class>=0.08123:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-DBIx-Class-TimeStamp>=0.13:${PORTSDIR}/databases/p5-DBIx-Class-TimeStamp \
		p5-DBIx-Class-UUIDColumns>=0.02005:${PORTSDIR}/databases/p5-DBIx-Class-UUIDColumns \
		p5-Data-UUID>=1.215:${PORTSDIR}/devel/p5-Data-UUID \
		p5-Data-Visitor>=0.27:${PORTSDIR}/devel/p5-Data-Visitor \
		p5-Hash-Merge>=0.11:${PORTSDIR}/textproc/p5-Hash-Merge \
		p5-List-MoreUtils>=0.22:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=1.10:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Attribute-ENV>=0.01:${PORTSDIR}/devel/p5-MooseX-Attribute-ENV \
		p5-MooseX-Types>=0.23:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Path-Class>=0.21:${PORTSDIR}/devel/p5-Path-Class \
		p5-SQL-Translator>=0.11006:${PORTSDIR}/databases/p5-SQL-Translator \
		p5-Scalar-List-Utils>=1.23:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-DBIx-Class-Schema-PopulateMore>=0.16:${PORTSDIR}/databases/p5-DBIx-Class-Schema-PopulateMore

BUILD_DEPENDS:=	${SHARED_DEPENDS}
RUN_DEPENDS:=	${SHARED_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0.106:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple \
		p5-Test-Differences>=0.61:${PORTSDIR}/devel/p5-Test-Differences

PERL_CONFIGURE=	yes

MAN3=	Test::DBIx::Class.3 \
	Test::DBIx::Class::Example::Schema.3 \
	Test::DBIx::Class::Example::Schema::DefaultRS.3 \
	Test::DBIx::Class::Example::Schema::Result.3 \
	Test::DBIx::Class::Example::Schema::Result::CD.3 \
	Test::DBIx::Class::Example::Schema::Result::CD::Artist.3 \
	Test::DBIx::Class::Example::Schema::Result::CD::Track.3 \
	Test::DBIx::Class::Example::Schema::Result::Company.3 \
	Test::DBIx::Class::Example::Schema::Result::Company::Employee.3 \
	Test::DBIx::Class::Example::Schema::Result::Job.3 \
	Test::DBIx::Class::Example::Schema::Result::Person.3 \
	Test::DBIx::Class::Example::Schema::Result::Person::Artist.3 \
	Test::DBIx::Class::Example::Schema::Result::Person::Employee.3 \
	Test::DBIx::Class::Example::Schema::Result::Phone.3 \
	Test::DBIx::Class::Example::Schema::ResultSet.3 \
	Test::DBIx::Class::FixtureCommand::Populate.3 \
	Test::DBIx::Class::FixtureCommand::PopulateMore.3 \
	Test::DBIx::Class::Role::FixtureCommand.3 \
	Test::DBIx::Class::SchemaManager.3 \
	Test::DBIx::Class::SchemaManager::Trait::SQLite.3 \
	Test::DBIx::Class::SchemaManager::Trait::Testmysqld.3 \
	Test::DBIx::Class::SchemaManager::Trait::Testpostgresql.3 \
	Test::DBIx::Class::Types.3

.include <bsd.port.mk>
