# New ports collection makefile for:	SQL-Translator
# Date created:				12 Apr 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	SQL-Translator
PORTVERSION=	0.09.004
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Manipulate structured data definitions (SQL and more)

BUILD_DEPENDS=	p5-Class-Base>=0:${PORTSDIR}/devel/p5-Class-Base \
		p5-Class-Data-Inheritable>=0.02:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-MakeMethods>=0:${PORTSDIR}/devel/p5-Class-MakeMethods \
		p5-Digest-SHA1>=2.0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-IO>=0:${PORTSDIR}/devel/p5-IO \
		p5-Parse-RecDescent>=1.94:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Template-Toolkit>=2.10:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz \
		p5-Graph>=0:${PORTSDIR}/math/p5-Graph \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Spreadsheet-ParseExcel>=0.2602:${PORTSDIR}/textproc/p5-Spreadsheet-ParseExcel \
		p5-Text-RecordParser>=0.02:${PORTSDIR}/textproc/p5-Text-RecordParser \
		p5-XML-Writer>=0.500:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-XML-XPath>=1.13:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-YAML>=0.39:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		sqlt-diagram.1 \
		sqlt-diff-old.1 \
		sqlt-diff.1 \
		sqlt-dumper.1 \
		sqlt-graph.1 \
		sqlt.1
MAN3=		SQL::Translator.3 \
		SQL::Translator::Diff.3 \
		SQL::Translator::Filter::DefaultExtra.3 \
		SQL::Translator::Filter::Globals.3 \
		SQL::Translator::Filter::Names.3 \
		SQL::Translator::Manual.3 \
		SQL::Translator::Parser.3 \
		SQL::Translator::Parser::Access.3 \
		SQL::Translator::Parser::DBI.3 \
		SQL::Translator::Parser::DBI::DB2.3 \
		SQL::Translator::Parser::DBI::MySQL.3 \
		SQL::Translator::Parser::DBI::Oracle.3 \
		SQL::Translator::Parser::DBI::PostgreSQL.3 \
		SQL::Translator::Parser::DBI::SQLServer.3 \
		SQL::Translator::Parser::DBI::SQLite.3 \
		SQL::Translator::Parser::DBI::Sybase.3 \
		SQL::Translator::Parser::Excel.3 \
		SQL::Translator::Parser::MySQL.3 \
		SQL::Translator::Parser::Oracle.3 \
		SQL::Translator::Parser::PostgreSQL.3 \
		SQL::Translator::Parser::SQLServer.3 \
		SQL::Translator::Parser::SQLite.3 \
		SQL::Translator::Parser::Storable.3 \
		SQL::Translator::Parser::Sybase.3 \
		SQL::Translator::Parser::XML.3 \
		SQL::Translator::Parser::XML::SQLFairy.3 \
		SQL::Translator::Parser::YAML.3 \
		SQL::Translator::Parser::xSV.3 \
		SQL::Translator::Producer.3 \
		SQL::Translator::Producer::ClassDBI.3 \
		SQL::Translator::Producer::DB2.3 \
		SQL::Translator::Producer::DiaUml.3 \
		SQL::Translator::Producer::Diagram.3 \
		SQL::Translator::Producer::Dumper.3 \
		SQL::Translator::Producer::GraphViz.3 \
		SQL::Translator::Producer::HTML.3 \
		SQL::Translator::Producer::Latex.3 \
		SQL::Translator::Producer::MySQL.3 \
		SQL::Translator::Producer::Oracle.3 \
		SQL::Translator::Producer::POD.3 \
		SQL::Translator::Producer::PostgreSQL.3 \
		SQL::Translator::Producer::SQLServer.3 \
		SQL::Translator::Producer::SQLite.3 \
		SQL::Translator::Producer::Storable.3 \
		SQL::Translator::Producer::Sybase.3 \
		SQL::Translator::Producer::TT::Base.3 \
		SQL::Translator::Producer::TT::Table.3 \
		SQL::Translator::Producer::TTSchema.3 \
		SQL::Translator::Producer::XML.3 \
		SQL::Translator::Producer::XML::SQLFairy.3 \
		SQL::Translator::Producer::YAML.3 \
		SQL::Translator::Schema.3 \
		SQL::Translator::Schema::Constants.3 \
		SQL::Translator::Schema::Constraint.3 \
		SQL::Translator::Schema::Field.3 \
		SQL::Translator::Schema::Index.3 \
		SQL::Translator::Schema::Object.3 \
		SQL::Translator::Schema::Procedure.3 \
		SQL::Translator::Schema::Table.3 \
		SQL::Translator::Schema::Trigger.3 \
		SQL::Translator::Schema::View.3 \
		SQL::Translator::Utils.3 \
		Test::SQL::Translator.3

.include <bsd.port.mk>
