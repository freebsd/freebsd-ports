# Ports collection makefile for:  pear-Var_Dump
# Date created:			  24 November 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	Var_Dump
PORTVERSION=	1.0.2
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	Provides methods for dumping structured information about a variable

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Var_Dump.php Var_Dump/Renderer.php Var_Dump/Renderer/Common.php \
		Var_Dump/Renderer/Text.php Var_Dump/Renderer/Table.php \
		Var_Dump/Renderer/HTML4_Table.php Var_Dump/Renderer/HTML4_Text.php \
		Var_Dump/Renderer/XHTML_Table.php Var_Dump/Renderer/XHTML_Text.php \
		Var_Dump/Renderer/XML.php
EXAMPLES=	example-1.php example-2.php example-3.php example-4.php example-5.php \
		example-6.php
DATA=		renderer-xml.dtd memory-usage.txt
TESTS=		bug1321.phpt bug490.phpt bug3396.phpt bug3416.phpt ignore-list.phpt \
		renderer-html4_table.phpt renderer-html4_text.phpt renderer-table.phpt \
		renderer-text.phpt renderer-xhtml_table.phpt renderer-xhtml_text.phpt \
		renderer-xml.phpt text-compact_mode.phpt text-normal_mode.phpt \
		text-wide_mode.phpt toString-array.phpt toString-bool.phpt \
		toString-float.phpt toString-int.phpt toString-null.phpt \
		toString-object.phpt toString-resource.phpt
_EXAMPLESDIR=	docs

post-extract:
	${MV} ${WRKSRC}/php/* ${WRKSRC}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
