# Ports collection makefile for:	pear-Structures_DataGrid
# Date created:				12 January 2005
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	Structures_DataGrid
PORTVERSION=	0.6.0
CATEGORIES=	devel www pear

MAINTAINER=	nick@foobar.org
COMMENT=	Simple HTML data structure package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${PEARDIR}/HTML/Table.php:${PORTSDIR}/devel/pear-HTML_Table \
		${PEARDIR}/Pager/Pager.php:${PORTSDIR}/devel/pear-Pager \
		${PEARDIR}/Spreadsheet/Excel/Writer.php:${PORTSDIR}/textproc/pear-Spreadsheet_Excel_Writer \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util \
		${PEARDIR}/XML/RSS.php:${PORTSDIR}/devel/pear-XML_RSS \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer \
		${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table

CATEGORY=	Structures
FILES=		DataGrid.php DataGrid/Core.php DataGrid/Column.php \
		DataGrid/Record.php DataGrid/Renderer.php \
		DataGrid/DataSource.php DataGrid/Renderer/Console.php \
		DataGrid/Renderer/CSV.php DataGrid/Renderer/HTMLTable.php \
		DataGrid/Renderer/Smarty.php DataGrid/Renderer/XML.php \
		DataGrid/Renderer/XLS.php DataGrid/Renderer/XUL.php \
		DataGrid/DataSource/Array.php DataGrid/DataSource/CSV.php \
		DataGrid/DataSource/DataObject.php \
		DataGrid/DataSource/DB.php DataGrid/DataSource/RSS.php \
		DataGrid/DataSource/XML.php DataGrid/Record/DB.php \
		DataGrid/Record/DataObject.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
