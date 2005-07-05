# New ports collection makefile for:	SQL-Translator
# Date created:				12 Apr 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	SQL-Translator
PORTVERSION=	0.07
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SQL
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Manipulate structured data definitions (SQL and more)

BUILD_DEPENDS=	${SITE_PERL}/Class/Base.pm:${PORTSDIR}/devel/p5-Class-Base \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz \
		${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-Pod-Parser \
		${SITE_PERL}/Spreadsheet/ParseExcel.pm:${PORTSDIR}/textproc/p5-Spreadsheet-ParseExcel \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Text/RecordParser.pm:${PORTSDIR}/textproc/p5-Text-RecordParser \
		${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
		${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Class/MakeMethods.pm:${PORTSDIR}/devel/p5-Class-MakeMethods \
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		sqlt-diagram.1 \
		sqlt-diff.1 \
		sqlt-dumper.1 \
		sqlt-graph.1 \
		sqlt.1
MAN3=		SQL::Translator.3 \
		SQL::Translator::Manual.3 \
		SQL::Translator::Parser.3 \
		SQL::Translator::Parser::Access.3 \
		SQL::Translator::Parser::DBI.3 \
		SQL::Translator::Parser::DBI::DB2.3 \
		SQL::Translator::Parser::DBI::MySQL.3 \
		SQL::Translator::Parser::DBI::PostgreSQL.3 \
		SQL::Translator::Parser::DBI::SQLite.3 \
		SQL::Translator::Parser::DBI::Sybase.3 \
		SQL::Translator::Parser::Excel.3 \
		SQL::Translator::Parser::MySQL.3 \
		SQL::Translator::Parser::Oracle.3 \
		SQL::Translator::Parser::PostgreSQL.3 \
		SQL::Translator::Parser::SQLite.3 \
		SQL::Translator::Parser::Storable.3 \
		SQL::Translator::Parser::Sybase.3 \
		SQL::Translator::Parser::XML.3 \
		SQL::Translator::Parser::XML::SQLFairy.3 \
		SQL::Translator::Parser::YAML.3 \
		SQL::Translator::Parser::xSV.3 \
		SQL::Translator::Producer.3 \
		SQL::Translator::Producer::ClassDBI.3 \
		SQL::Translator::Producer::Diagram.3 \
		SQL::Translator::Producer::Dumper.3 \
		SQL::Translator::Producer::GraphViz.3 \
		SQL::Translator::Producer::HTML.3 \
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

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=	requires Perl 5.6. Install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
