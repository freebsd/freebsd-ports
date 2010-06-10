# New ports collection makefile for:	databases/p5-DBIx-Class-Schema-Loader
# Date created:				4 Feb 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class-Schema-Loader
PORTVERSION=	0.07000
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dynamic definition of a DBIx::Class::Schema

RUN_DEPENDS=	p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-Class-C3>=0.18:${PORTSDIR}/devel/p5-Class-C3 \
		p5-Class-Accessor-Grouped>=0.09002:${PORTSDIR}/devel/p5-Class-Accessor-Grouped \
		p5-Class-Inspector>=0:${PORTSDIR}/devel/p5-Class-Inspector \
		p5-Class-Unload>=0:${PORTSDIR}/devel/p5-Class-Unload \
		p5-DBIx-Class>=0.08114:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Data-Dump>=1.06:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Data-Dumper-Concise>0:${PORTSDIR}/devel/p5-Data-Dumper-Concise \
		p5-File-Slurp>=9999.13:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Lingua-EN-Inflect-Number>=1.1:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
		p5-Lingua-EN-Inflect-Phrase>=0.02:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Phrase \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils

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
RUN_DEPENDS+=  p5-DBD-Oracle>=0.19:${PORTSDIR}/databases/p5-DBD-Oracle
.endif

PERL_CONFIGURE=	5.8.0+

MAN1=	dbicdump.1
MAN3=	DBIx::Class::Schema::Loader.3 \
	DBIx::Class::Schema::Loader::Base.3 \
	DBIx::Class::Schema::Loader::DBI.3 \
	DBIx::Class::Schema::Loader::DBI::Component::QuotedDefault.3 \
	DBIx::Class::Schema::Loader::DBI::DB2.3 \
	DBIx::Class::Schema::Loader::DBI::Informix.3 \
	DBIx::Class::Schema::Loader::DBI::InterBase.3 \
	DBIx::Class::Schema::Loader::DBI::MSSQL.3 \
	DBIx::Class::Schema::Loader::DBI::ODBC.3 \
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
	DBIx::Class::Schema::Loader::RelBuilder::Compat::v0_040.3 \
	DBIx::Class::Schema::Loader::RelBuilder::Compat::v0_05.3 \
	DBIx::Class::Schema::Loader::RelBuilder::Compat::v0_06.3

post-extract:
	@${PERL} -i.bak -ne 'print unless /^\s*(test_requires|auto_install|recommends|configure_requires)/ or /^my/ .. /^}\s*$$/' ${WRKSRC}/Makefile.PL

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -print0 | ${XARGS} -0 ${RM}

.include <bsd.port.mk>
