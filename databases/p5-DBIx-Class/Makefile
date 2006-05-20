# New ports collection makefile for:	DBIx-Class
# Date created:		14 Aug 2005
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class
PORTVERSION=	0.06003
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Extensible and flexible object <-> relational mapper

BUILD_DEPENDS=	p5-Data-Page>=2.00:${PORTSDIR}/databases/p5-Data-Page \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-SQL-Abstract>=1.20:${PORTSDIR}/databases/p5-SQL-Abstract \
		p5-SQL-Abstract-Limit>=0.101:${PORTSDIR}/databases/p5-SQL-Abstract-Limit \
		p5-Class-C3>=0.11:${PORTSDIR}/devel/p5-Class-C3 \
		p5-Storable>=0:${PORTSDIR}/devel/p5-Storable \
		p5-Class-Data-Accessor>=0.01:${PORTSDIR}/devel/p5-Class-Data-Accessor \
		p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-DBI>=1.40:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-SQLite>=1.11:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Data-UUID>=0:${PORTSDIR}/devel/p5-Data-UUID \
		p5-Module-Find>=0:${PORTSDIR}/devel/p5-Module-Find \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	DBIx::Class.3 \
	DBIx::Class::AccessorGroup.3 \
	DBIx::Class::CDBICompat.3 \
	DBIx::Class::Core.3 \
	DBIx::Class::Cursor.3 \
	DBIx::Class::DB.3 \
	DBIx::Class::InflateColumn.3 \
	DBIx::Class::Manual.3 \
	DBIx::Class::Manual::Component.3 \
	DBIx::Class::Manual::Cookbook.3 \
	DBIx::Class::Manual::DocMap.3 \
	DBIx::Class::Manual::Example.3 \
	DBIx::Class::Manual::Glossary.3 \
	DBIx::Class::Manual::Intro.3 \
	DBIx::Class::Manual::Troubleshooting.3 \
	DBIx::Class::PK.3 \
	DBIx::Class::PK::Auto.3 \
	DBIx::Class::PK::Auto::DB2.3 \
	DBIx::Class::PK::Auto::MSSQL.3 \
	DBIx::Class::PK::Auto::MySQL.3 \
	DBIx::Class::PK::Auto::Oracle.3 \
	DBIx::Class::PK::Auto::Pg.3 \
	DBIx::Class::PK::Auto::SQLite.3 \
	DBIx::Class::Relationship.3 \
	DBIx::Class::Relationship::Base.3 \
	DBIx::Class::Relationship::BelongsTo.3 \
	DBIx::Class::ResultSet.3 \
	DBIx::Class::ResultSetManager.3 \
	DBIx::Class::ResultSource.3 \
	DBIx::Class::ResultSource::Table.3 \
	DBIx::Class::ResultSourceProxy::Table.3 \
	DBIx::Class::Row.3 \
	DBIx::Class::Schema.3 \
	DBIx::Class::Serialize::Storable.3 \
	DBIx::Class::Storage::DBI.3 \
	DBIx::Class::Storage::DBI::Cursor.3 \
	DBIx::Class::Storage::DBI::DB2.3 \
	DBIx::Class::Storage::DBI::MSSQL.3 \
	DBIx::Class::Storage::DBI::MultiDistinctEmulation.3 \
	DBIx::Class::Storage::DBI::Oracle.3 \
	DBIx::Class::Storage::DBI::Pg.3 \
	DBIx::Class::Storage::DBI::SQLite.3 \
	DBIx::Class::Storage::DBI::mysql.3 \
	DBIx::Class::Test::SQLite.3 \
	DBIx::Class::UTF8Columns.3 \
	DBIx::Class::UUIDColumns.3 \
	DBIx::Class::UUIDMaker.3 \
	DBIx::Class::UUIDMaker::APR::UUID.3 \
	DBIx::Class::UUIDMaker::Data::UUID.3 \
	DBIx::Class::UUIDMaker::Data::Uniqid.3 \
	DBIx::Class::UUIDMaker::UUID.3 \
	DBIx::Class::UUIDMaker::Win32::Guidgen.3 \
	DBIx::Class::UUIDMaker::Win32API::GUID.3 \
	DBIx::Class::Validation.3 \
	SQL::Translator::Producer::DBIx::Class::File.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
