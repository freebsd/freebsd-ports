# New ports collection makefile for:	databases/p5-DBIx-Class-Schema-Loader
# Date created:				2006-02-04
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-Schema-Loader
PORTVERSION=	0.07010
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RKITOVER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dynamic definition of a DBIx::Class::Schema

RUN_DEPENDS=	\
	p5-Data-Dump>1.06:${PORTSDIR}/devel/p5-Data-Dump \
	p5-Lingua-EN-Inflect-Number>=1.1:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
	p5-Lingua-EN-Inflect-Phrase>=0.02:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Phrase \
	p5-Class-Accessor-Grouped>=0.10002:${PORTSDIR}/devel/p5-Class-Accessor-Grouped \
	p5-MRO-Compat>=0.09:${PORTSDIR}/devel/p5-MRO-Compat \
	p5-Class-C3-Componentised>=1.0008:${PORTSDIR}/devel/p5-Class-C3-Componentised \
	p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
	p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
	p5-DBIx-Class>=0.08127:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-Class-Unload>=0:${PORTSDIR}/devel/p5-Class-Unload \
	p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load \
	p5-File-Slurp>=9999.13:${PORTSDIR}/devel/p5-File-Slurp \
	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-namespace-clean>=0.20:${PORTSDIR}/devel/p5-namespace-clean \
	p5-Scope-Guard>=0:${PORTSDIR}/devel/p5-Scope-Guard \
	p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny

TEST_DEPENDS=	\
	p5-Test-Exception=>0;${PORTSDIR}/devel/p5-Test-Exception	\
	p5-Test-Simple=>0.94;${PORTSDIR}/devel/p5-Test-Simple	\
	p5-Test-Warn=>0.21;${PORTSDIR}/devel/p5-Test-Warn	\
	p5-DBI=>1.56;${PORTSDIR}/databases/p5-DBI	\
	p5-DBD-SQLite=>1.29;${PORTSDIR}/databases/p5-DBD-SQLite	\
	p5-File-Temp=>0.16;${PORTSDIR}/devel/p5-File-Temp	\
	p5-File-Path=>2.07;${PORTSDIR}/devel/p5-File-Path

OPTIONS=	SQLITE "SQLite Support" Off \
		MYSQL "MySQL Support" Off \
		PGSQL "PostgreSQL Support" Off \
		ORACLE "Oracle Support (experimental)" Off

.include <bsd.port.options.mk>

.if defined(WITH_SQLITE)
USE_SQLITE=	yes
.endif
.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.endif
.if defined(WITH_PGSQL)
USE_PGSQL=	yes
.endif
.if defined(WITH_ORACLE)
RUN_DEPENDS+=	p5-DBD-Oracle>=0.19:${PORTSDIR}/databases/p5-DBD-Oracle
.endif

PERL_CONFIGURE=	5.8.0+

MAN1=	dbicdump.1
MAN3=	DBIx::Class::Schema::Loader.3 \
	DBIx::Class::Schema::Loader::Base.3 \
	DBIx::Class::Schema::Loader::DBI.3 \
	DBIx::Class::Schema::Loader::DBI::ADO.3 \
	DBIx::Class::Schema::Loader::DBI::ADO::Microsoft_SQL_Server.3 \
	DBIx::Class::Schema::Loader::DBI::ADO::MS_Jet.3 \
	DBIx::Class::Schema::Loader::DBI::Component::QuotedDefault.3 \
	DBIx::Class::Schema::Loader::DBI::DB2.3 \
	DBIx::Class::Schema::Loader::DBI::Informix.3 \
	DBIx::Class::Schema::Loader::DBI::InterBase.3 \
	DBIx::Class::Schema::Loader::DBI::MSSQL.3 \
	DBIx::Class::Schema::Loader::DBI::ODBC.3 \
	DBIx::Class::Schema::Loader::DBI::ODBC::ACCESS.3 \
	DBIx::Class::Schema::Loader::DBI::ODBC::Firebird.3 \
	DBIx::Class::Schema::Loader::DBI::ODBC::Microsoft_SQL_Server.3 \
	DBIx::Class::Schema::Loader::DBI::ODBC::SQL_Anywhere.3 \
	DBIx::Class::Schema::Loader::DBI::Oracle.3 \
	DBIx::Class::Schema::Loader::DBI::Pg.3 \
	DBIx::Class::Schema::Loader::DBI::SQLAnywhere.3 \
	DBIx::Class::Schema::Loader::DBI::SQLite.3 \
	DBIx::Class::Schema::Loader::DBI::Sybase.3 \
	DBIx::Class::Schema::Loader::DBI::Sybase::Common.3 \
	DBIx::Class::Schema::Loader::DBI::Sybase::Microsoft_SQL_Server.3 \
	DBIx::Class::Schema::Loader::DBI::Writing.3 \
	DBIx::Class::Schema::Loader::DBI::mysql.3 \
	DBIx::Class::Schema::Loader::Manual::UpgradingFromV4.3 \
	DBIx::Class::Schema::Loader::RelBuilder.3 \
	DBIx::Class::Schema::Loader::Optional::Dependencies.3 \
	DBIx::Class::Schema::Loader::RelBuilder::Compat::v0_040.3 \
	DBIx::Class::Schema::Loader::RelBuilder::Compat::v0_05.3 \
	DBIx::Class::Schema::Loader::RelBuilder::Compat::v0_06.3

.include <bsd.port.mk>
