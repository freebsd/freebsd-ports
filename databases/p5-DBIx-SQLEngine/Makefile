# New ports collection makefile for: DBIx::SQLEngine
# Date created:   31.7.2003
# Whom:           Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
#
# $FreeBSD$
#

PORTNAME=	DBIx-SQLEngine
PORTVERSION=	0.93
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extends DBI with high-level operations

BUILD_DEPENDS=	p5-DBIx-AnyDBD>=0:${PORTSDIR}/databases/p5-DBIx-AnyDBD \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Class-MakeMethods>=0:${PORTSDIR}/devel/p5-Class-MakeMethods \
		p5-Class-MixinFactory>=0:${PORTSDIR}/devel/p5-Class-MixinFactory
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	DBIx::SQLEngine.3 \
	DBIx::SQLEngine::Cache::BasicCache.3 \
	DBIx::SQLEngine::Cache::TrivialCache.3 \
	DBIx::SQLEngine::Criteria.3 \
	DBIx::SQLEngine::Criteria::And.3 \
	DBIx::SQLEngine::Criteria::Comparison.3 \
	DBIx::SQLEngine::Criteria::Compound.3 \
	DBIx::SQLEngine::Criteria::Equality.3 \
	DBIx::SQLEngine::Criteria::Greater.3 \
	DBIx::SQLEngine::Criteria::HashGroup.3 \
	DBIx::SQLEngine::Criteria::Lesser.3 \
	DBIx::SQLEngine::Criteria::Like.3 \
	DBIx::SQLEngine::Criteria::LiteralSQL.3 \
	DBIx::SQLEngine::Criteria::Not.3 \
	DBIx::SQLEngine::Criteria::Or.3 \
	DBIx::SQLEngine::Criteria::StringComparison.3 \
	DBIx::SQLEngine::Docs::Changes.3 \
	DBIx::SQLEngine::Docs::Comparison.3 \
	DBIx::SQLEngine::Docs::ReadMe.3 \
	DBIx::SQLEngine::Docs::Related.3 \
	DBIx::SQLEngine::Docs::ToDo.3 \
	DBIx::SQLEngine::Driver.3 \
	DBIx::SQLEngine::Driver::AnyData.3 \
	DBIx::SQLEngine::Driver::CSV.3 \
	DBIx::SQLEngine::Driver::Informix.3 \
	DBIx::SQLEngine::Driver::MSSQL.3 \
	DBIx::SQLEngine::Driver::Mysql.3 \
	DBIx::SQLEngine::Driver::NullP.3 \
	DBIx::SQLEngine::Driver::Oracle.3 \
	DBIx::SQLEngine::Driver::Pg.3 \
	DBIx::SQLEngine::Driver::SQLite.3 \
	DBIx::SQLEngine::Driver::Sybase.3 \
	DBIx::SQLEngine::Driver::Sybase::MSSQL.3 \
	DBIx::SQLEngine::Driver::Trait::DatabaseFlavors.3 \
	DBIx::SQLEngine::Driver::Trait::NoAdvancedFeatures.3 \
	DBIx::SQLEngine::Driver::Trait::NoColumnTypes.3 \
	DBIx::SQLEngine::Driver::Trait::NoComplexJoins.3 \
	DBIx::SQLEngine::Driver::Trait::NoJoins.3 \
	DBIx::SQLEngine::Driver::Trait::NoLimit.3 \
	DBIx::SQLEngine::Driver::Trait::NoPlaceholders.3 \
	DBIx::SQLEngine::Driver::Trait::NoSequences.3 \
	DBIx::SQLEngine::Driver::Trait::NoUnions.3 \
	DBIx::SQLEngine::Driver::Trait::PerlDBLib.3 \
	DBIx::SQLEngine::Driver::XBase.3 \
	DBIx::SQLEngine::Record::Accessors.3 \
	DBIx::SQLEngine::Record::Base.3 \
	DBIx::SQLEngine::Record::Cache.3 \
	DBIx::SQLEngine::Record::Class.3 \
	DBIx::SQLEngine::Record::Extras.3 \
	DBIx::SQLEngine::Record::Hooks.3 \
	DBIx::SQLEngine::Record::PKey.3 \
	DBIx::SQLEngine::Record::Table.3 \
	DBIx::SQLEngine::RecordSet::NextPrev.3 \
	DBIx::SQLEngine::RecordSet::PKeySet.3 \
	DBIx::SQLEngine::RecordSet::Set.3 \
	DBIx::SQLEngine::Schema::Column.3 \
	DBIx::SQLEngine::Schema::ColumnSet.3 \
	DBIx::SQLEngine::Schema::Table.3 \
	DBIx::SQLEngine::Schema::TableSet.3 \
	DBIx::SQLEngine::Utility::CloneWithParams.3

.include <bsd.port.mk>
