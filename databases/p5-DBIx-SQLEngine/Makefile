# New ports collection makefile for: DBIx::SQLEngine
# Date created:   31.7.2003
# Whom:           Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
#
# $FreeBSD$
#

PORTNAME=	DBIx-SQLEngine
PORTVERSION=	0.028
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	hansjoerg.pehofer@uibk.ac.at
COMMENT=	Extends DBI with high-level operations

BUILD_DEPENDS=	${SITE_PERL}/DBIx/AnyDBD.pm:${PORTSDIR}/databases/p5-DBIx-AnyDBD \
		${SITE_PERL}/Class/MakeMethods/Template.pm:${PORTSDIR}/devel/p5-Class-MakeMethods
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::SQLEngine.3\
		DBIx::SQLEngine::Cache::BasicCache.3\
		DBIx::SQLEngine::Cache::TrivialCache.3\
		DBIx::SQLEngine::Criteria.3\
		DBIx::SQLEngine::Criteria::And.3\
		DBIx::SQLEngine::Criteria::Comparison.3\
		DBIx::SQLEngine::Criteria::Compound.3\
		DBIx::SQLEngine::Criteria::Equality.3\
		DBIx::SQLEngine::Criteria::Greater.3\
		DBIx::SQLEngine::Criteria::HashGroup.3\
		DBIx::SQLEngine::Criteria::Lesser.3\
		DBIx::SQLEngine::Criteria::Like.3\
		DBIx::SQLEngine::Criteria::LiteralSQL.3\
		DBIx::SQLEngine::Criteria::Not.3\
		DBIx::SQLEngine::Criteria::Or.3\
		DBIx::SQLEngine::Criteria::StringComparison.3\
		DBIx::SQLEngine::Docs::Changes.3\
		DBIx::SQLEngine::Docs::Comparison.3\
		DBIx::SQLEngine::Docs::ReadMe.3\
		DBIx::SQLEngine::Docs::Related.3\
		DBIx::SQLEngine::Docs::ToDo.3\
		DBIx::SQLEngine::Driver.3\
		DBIx::SQLEngine::Driver::AnyData.3\
		DBIx::SQLEngine::Driver::CSV.3\
		DBIx::SQLEngine::Driver::Informix.3\
		DBIx::SQLEngine::Driver::MSSQL.3\
		DBIx::SQLEngine::Driver::Mysql.3\
		DBIx::SQLEngine::Driver::NullP.3\
		DBIx::SQLEngine::Driver::Oracle.3\
		DBIx::SQLEngine::Driver::Pg.3\
		DBIx::SQLEngine::Driver::SQLite.3\
		DBIx::SQLEngine::Driver::Sybase.3\
		DBIx::SQLEngine::Driver::Sybase::MSSQL.3\
		DBIx::SQLEngine::Driver::Trait::DatabaseFlavors.3\
		DBIx::SQLEngine::Driver::Trait::NoAdvancedFeatures.3\
		DBIx::SQLEngine::Driver::Trait::NoColumnTypes.3\
		DBIx::SQLEngine::Driver::Trait::NoComplexJoins.3\
		DBIx::SQLEngine::Driver::Trait::NoPlaceholders.3\
		DBIx::SQLEngine::Driver::Trait::NoSequences.3\
		DBIx::SQLEngine::Driver::Trait::NoUnions.3\
		DBIx::SQLEngine::Record::Base.3\
		DBIx::SQLEngine::Record::Class.3\
		DBIx::SQLEngine::Record::Set.3\
		DBIx::SQLEngine::Record::Trait::Accessors.3\
		DBIx::SQLEngine::Record::Trait::Cache.3\
		DBIx::SQLEngine::Record::Trait::Extras.3\
		DBIx::SQLEngine::Record::Trait::Hooks.3\
		DBIx::SQLEngine::Schema::Column.3\
		DBIx::SQLEngine::Schema::ColumnSet.3\
		DBIx::SQLEngine::Schema::Table.3\
		DBIx::SQLEngine::Schema::TableSet.3\
		DBIx::SQLEngine::Utility::CloneWithParams.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
