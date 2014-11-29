# Created by: Parv <parv@pair.org>
# $FreeBSD$

PORTNAME=	DBIx-Simple
PORTVERSION=	1.35
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simplified object oriented interface to Perl DBI

BUILD_DEPENDS=	p5-DBI>=1.21:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	SQL_INTERP SQL_ABSTRACT DBIX_XHTML_TABLE TEXT_TABLE
SQL_INTERP_DESC=	Interpolate Perl variables into SQL
SQL_ABSTRACT_DESC=	Generate SQL from Perl data structures
DBIX_XHTML_TABLE_DESC=	Create XHTML tables from SQL queries
TEXT_TABLE_DESC=	Create plain text table from data

USES=		perl5
USE_PERL5=	configure

DBIX_XHTML_TABLE_RUN_DEPENDS=	p5-DBIx-XHTML_Table>=0:${PORTSDIR}/databases/p5-DBIx-XHTML_Table
SQL_ABSTRACT_RUN_DEPENDS=	p5-SQL-Abstract>=0:${PORTSDIR}/databases/p5-SQL-Abstract
SQL_INTERP_RUN_DEPENDS=	p5-SQL-Interp>=0:${PORTSDIR}/databases/p5-SQL-Interp
TEXT_TABLE_RUN_DEPENDS=	p5-Text-Table>=0:${PORTSDIR}/textproc/p5-Text-Table

.include <bsd.port.mk>
