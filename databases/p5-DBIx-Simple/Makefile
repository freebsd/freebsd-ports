# Created by: Parv <parv@pair.org>
# $FreeBSD$

PORTNAME=	DBIx-Simple
PORTVERSION=	1.35
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	parv@pair.com
COMMENT=	Simplified object oriented interface to Perl DBI

RUN_DEPENDS=	p5-DBI>=1.21:${PORTSDIR}/databases/p5-DBI

OPTIONS_DEFINE=	SQL_INTERP SQL_ABSTRACT DBIX_XHTML_TABLE TEXT_TABLE
SQL_INTERP_DESC=	Interpolate Perl variables into SQL
SQL_ABSTRACT_DESC=	Generate SQL from Perl data structures
DBIX_XHTML_TABLE_DESC=	Create XHTML tables from SQL queries
TEXT_TABLE_DESC=	Create plain text table from data

USES=		perl5
USE_PERL5=	configure

MAN3=	DBIx::Simple.3 \
	DBIx::Simple::Examples.3 \
	DBIx::Simple::Comparison.3 \
	DBIx::Simple::Result::RowObject.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQL_INTERP}
RUN_DEPENDS+=	p5-SQL-Interp>=0:${PORTSDIR}/databases/p5-SQL-Interp
.endif

.if ${PORT_OPTIONS:MSQL_ABSTRACT}
RUN_DEPENDS+=	p5-SQL-Abstract>=0:${PORTSDIR}/databases/p5-SQL-Abstract
.endif

.if ${PORT_OPTIONS:MDBIX_XHTML_TABLE}
RUN_DEPENDS+=	p5-DBIx-XHTML_Table>=0:${PORTSDIR}/databases/p5-DBIx-XHTML_Table
.endif

.if ${PORT_OPTIONS:MTEXT_TABLE}
RUN_DEPENDS+=	p5-Text-Table>=0:${PORTSDIR}/textproc/p5-Text-Table
.endif

.include <bsd.port.mk>
