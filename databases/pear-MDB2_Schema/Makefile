# New ports collection makefile for:	pear-MDB2_Schema
# Date created:				08 Feb 2007
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MDB2_Schema
PORTVERSION=	0.8.5
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR XML based database schema manager

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2 \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser \
		${PEARDIR}/XML/DTD.php:${PORTSDIR}/textproc/pear-XML_DTD \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		MDB2/Schema/Reserved/ibase.php \
		MDB2/Schema/Reserved/mssql.php \
		MDB2/Schema/Reserved/mysql.php \
		MDB2/Schema/Reserved/oci8.php \
		MDB2/Schema/Reserved/pgsql.php \
		MDB2/Schema/Parser.php \
		MDB2/Schema/Parser2.php \
		MDB2/Schema/Tool.php \
		MDB2/Schema/Validate.php \
		MDB2/Schema/Writer.php \
		MDB2/Schema/Tool/ParameterException.php \
		MDB2/Schema.php scripts/mdb2_schematool

TESTS=		Console_TestListener.php HTML_TestListener.php \
		MDB2_Schema_testcase.php README clitest.php driver_test.schema \
		lob_test.schema test.php testUtils.php test_setup.php.dist \
		testchoose.php tests.css

DOCS=		description.schema.xml MDB.dtd MDB.xsd MDB.xsl schema2html.css \
		README schema2html.xsl xml_schema_documentation.html

EXAMPLES=	parse.php schema.xml
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
