# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	SQL-Translator
PORTVERSION=	0.11016
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Manipulate structured data definitions (SQL and more)

BUILD_DEPENDS=	p5-Class-Base>=0:${PORTSDIR}/devel/p5-Class-Base \
		p5-Class-Data-Inheritable>=0.02:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Class-MakeMethods>=0:${PORTSDIR}/devel/p5-Class-MakeMethods \
		p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-File-ShareDir>=1:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-Digest-SHA1>=2.0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Parse-RecDescent>=1.962.2:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Template-Toolkit>=2.20:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Moo>=0.009007:${PORTSDIR}/devel/p5-Moo \
		p5-Package-Variant>=0:${PORTSDIR}/devel/p5-Package-Variant \
		p5-Spreadsheet-ParseExcel>=0.41:${PORTSDIR}/textproc/p5-Spreadsheet-ParseExcel \
		p5-Text-ParseWords>0:${PORTSDIR}/textproc/p5-Text-ParseWords \
		p5-Text-RecordParser>=0.02:${PORTSDIR}/textproc/p5-Text-RecordParser \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-XML-LibXML>=1.69:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-Writer>=0.5:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-YAML>0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Differences>=0.61:${PORTSDIR}/devel/p5-Test-Differences \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

OPTIONS_DEFINE=	DIAGRAM
DIAGRAM_DESC=	Diagram generation support

USES=		perl5
USE_PERL5=	configure

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
		SQL::Translator::Generator::DDL::PostgreSQL.3 \
		SQL::Translator::Generator::DDL::SQLServer.3 \
		SQL::Translator::Generator::DDL::SQLite.3 \
		SQL::Translator::Generator::Role::DDL.3 \
		SQL::Translator::Generator::Role::Quote.3 \
		SQL::Translator::Manual.3 \
		SQL::Translator::Parser.3 \
		SQL::Translator::Parser::Access.3 \
		SQL::Translator::Parser::DB2.3 \
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
		SQL::Translator::Role::BuildArgs.3 \
		SQL::Translator::Role::Error.3 \
		SQL::Translator::Role::ListAttr.3 \
		SQL::Translator::Schema.3 \
		SQL::Translator::Schema::Constants.3 \
		SQL::Translator::Schema::Constraint.3 \
		SQL::Translator::Schema::Field.3 \
		SQL::Translator::Schema::Index.3 \
		SQL::Translator::Schema::Object.3 \
		SQL::Translator::Schema::Procedure.3 \
		SQL::Translator::Schema::Role::Compare.3 \
		SQL::Translator::Schema::Role::Extra.3 \
		SQL::Translator::Schema::Table.3 \
		SQL::Translator::Schema::Trigger.3 \
		SQL::Translator::Schema::View.3 \
		SQL::Translator::Types.3 \
		SQL::Translator::Utils.3 \
		Test::SQL::Translator.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDIAGRAM}
BUILD_DEPENDS+= p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-Graph>=0:${PORTSDIR}/math/p5-Graph \
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz
.endif

.include <bsd.port.mk>
