# New ports collection makefile for:	DBIx-Class
# Date created:		14 Aug 2005
# Whom:			Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	DBIx-Class
PORTVERSION=	0.02
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/A/AG/AGRUNDMA
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	SQL to OOP mapper, replacement for Class::DBI

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/NEXT.pm:${PORTSDIR}/devel/p5-NEXT \
		${SITE_PERL}/SQL/Abstract/Limit.pm:${PORTSDIR}/databases/p5-SQL-Abstract-Limit \
		${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash \
		${SITE_PERL}/UNIVERSAL/require.pm:${PORTSDIR}/devel/p5-UNIVERSAL-exports
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		DBIx::Class::Storage::DBI.3 \
		DBIx::Class::PK::Auto::MySQL.3 \
		DBIx::Class::PK.3 \
		DBIx::Class.3 \
		DBIx::Class::PK::Auto::Oracle.3 \
		DBIx::Class::Exception.3 \
		DBIx::Class::Relationship::Base.3 \
		DBIx::Class::PK::Auto::Pg.3 \
		DBIx::Class::PK::Auto::MSSQL.3 \
		DBIx::Class::CDBICompat.3 \
		DBIx::Class::Relationship.3 \
		DBIx::Class::Core.3 \
		DBIx::Class::PK::Auto.3 \
		DBIx::Class::DB.3 \
		DBIx::Class::Table.3 \
		DBIx::Class::AccessorGroup.3 \
		DBIx::Class::Schema.3 \
		DBIx::Class::PK::Auto::SQLite.3 \
		DBIx::Class::Test::SQLite.3 \
		DBIx::Class::Row.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500801
IGNORE=	requires at least Perl 5.8.1. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
