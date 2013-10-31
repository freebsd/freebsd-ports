# $FreeBSD$

PORTNAME=	Teng
PORTVERSION=	0.18
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NEKOKAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple DBI wrapper/ORMapper

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>=0.05:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-Class-Load>=0.06:${PORTSDIR}/devel/p5-Class-Load \
	p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
	p5-DBIx-Inspector>=0.06:${PORTSDIR}/databases/p5-DBIx-Inspector \
	p5-DBIx-TransactionManager>=1.06:${PORTSDIR}/databases/p5-DBIx-TransactionManager \
	p5-Data-Page>0:${PORTSDIR}/databases/p5-Data-Page \
	p5-Data-Page-NoTotalEntries>=0.02:${PORTSDIR}/devel/p5-Data-Page-NoTotalEntries \
	p5-SQL-Maker>=0.14:${PORTSDIR}/databases/p5-SQL-Maker
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-DBD-SQLite>=1.12:${PORTSDIR}/databases/p5-DBD-SQLite \
	p5-Test-Mock-Guard>0:${PORTSDIR}/devel/p5-Test-Mock-Guard \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-SharedFork>=0.06:${PORTSDIR}/devel/p5-Test-SharedFork \
	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple \
	p5-Class-Method-Modifiers>0:${PORTSDIR}/devel/p5-Class-Method-Modifiers

USES=		perl5
USE_PERL5=	configure

MAN3=	Teng.3 \
	Teng::Iterator.3 \
	Teng::Plugin::BulkInsert.3 \
	Teng::Plugin::Count.3 \
	Teng::Plugin::FindOrCreate.3 \
	Teng::Plugin::Lookup.3 \
	Teng::Plugin::Pager.3 \
	Teng::Plugin::Pager::MySQLFoundRows.3 \
	Teng::Plugin::Replace.3 \
	Teng::Plugin::SQLPager.3 \
	Teng::Plugin::SingleBySQL.3 \
	Teng::QueryBuilder.3 \
	Teng::Row.3 \
	Teng::Schema.3 \
	Teng::Schema::Declare.3 \
	Teng::Schema::Dumper.3 \
	Teng::Schema::Loader.3 \
	Teng::Schema::Table.3

NO_STAGE=	yes
.include <bsd.port.mk>
