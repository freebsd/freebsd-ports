# New ports collection makefile for: DBIx::SQLEngine
# Date created:   31.7.2003
# Whom:           Hansjoerg Pehofer <hansjoerg.pehofer@uibk.ac.at>
#
# $FreeBSD$
#

PORTNAME=	DBIx-SQLEngine
PORTVERSION=	0.016
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

MAN3=	DBIx::SQLEngine::Driver::CSV.3\
		DBIx::SQLEngine::Driver::MSSQL.3\
		DBIx::SQLEngine::Criteria::HashGroup.3\
		DBIx::SQLEngine::Criteria.3\
		DBIx::SQLEngine::Criteria::NumericLesser.3\
		DBIx::SQLEngine::Driver::SQLite.3\
		DBIx::SQLEngine::Driver::AnyData.3\
		DBIx::SQLEngine::Criteria::Greater.3\
		DBIx::SQLEngine::Driver::Pg.3\
		DBIx::SQLEngine::Docs::Related.3\
		DBIx::SQLEngine::Criteria::StringEquality.3\
		DBIx::SQLEngine::Criteria::Comparison.3\
		DBIx::SQLEngine::Driver::Mysql.3\
		DBIx::SQLEngine::Criteria::LiteralSQL.3\
		DBIx::SQLEngine::Mixin::SeqTable.3\
		DBIx::SQLEngine::Criteria::And.3\
		DBIx::SQLEngine::Criteria::Not.3\
		DBIx::SQLEngine::Criteria::StringComparison.3\
		DBIx::SQLEngine::Driver::Oracle.3\
		DBIx::SQLEngine::Criteria::Equality.3\
		DBIx::SQLEngine::Criteria::Like.3\
		DBIx::SQLEngine.3\
		DBIx::SQLEngine::Schema::Table.3\
		DBIx::SQLEngine::Criteria::Lesser.3\
		DBIx::SQLEngine::Docs::ToDo.3\
		DBIx::SQLEngine::Schema::ColumnSet.3\
		DBIx::SQLEngine::Criteria::Compound.3\
		DBIx::SQLEngine::Schema::TableSet.3\
		DBIx::SQLEngine::Criteria::Or.3\
		DBIx::SQLEngine::Docs::ReadMe.3\
		DBIx::SQLEngine::Docs::Changes.3\
		DBIx::SQLEngine::Driver::File.3\
		DBIx::SQLEngine::Schema::Column.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
