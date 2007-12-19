# Ports collection makefile for:	pear-Structures_DataGrid
# Date created:				12 January 2005
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	Structures_DataGrid
PORTVERSION=	0.9.0
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A full-featured tabular structured data management package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table

CATEGORY=	Structures

FILES=		DataGrid/Column.php DataGrid/DataSource.php \
		DataGrid/Renderer.php DataGrid.php

TESTS=		AllDataSourceTests.php DataSourceCSVTest.php DataSourceSQLTestCore.php \
		README AllTests.php DataSourceDBQueryTest.php DataSourceTestCore.php \
		RendererSmartyTest.php DataGridTest.php DataSourceMDB2Test.php \
		DataSourceXMLTest.php URLMappingTest.php DataSourceArrayTest.php \
		DataSourcePDOTest.php ObjectRecordTest.php

EXAMPLES=	addColumn.php bind-xml1.php fill-sortform.php smarty-simple.php \
		ajax-simple.php bind-xml2.php format.php smarty-simple.tpl \
		bind-dataobject.php checkablehtmltable.php htmleditform-basic.php \
		xul.php bind-dbtable.php constructor.php htmleditform-tableless.php \
		bind-sql.php fill-pager.php removeColumn.php

_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
