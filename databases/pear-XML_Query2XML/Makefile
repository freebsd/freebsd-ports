# Ports collection makefile for:  pear-XML_Query2xml
# Date created:			  23 March 2008
# Whom:				  wenheping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	XML_Query2XML
PORTVERSION=	1.6.0
CATEGORIES=	databases pear

MAINTAINER=	wenheping@gmail.com
COMMENT=	PEAR class transform SQL queries into XML data

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		XML/Query2XML.php XML/Query2XML/ISO9075Mapper.php \
		XML/Query2XML/Callback.php \
		XML/Query2XML/Command/Base64.php \
		XML/Query2XML/Command/CDATA.php \
		XML/Query2XML/Command/Chain.php \
		XML/Query2XML/Command/ColumnValue.php \
		XML/Query2XML/Command/NonEmpty.php \
		XML/Query2XML/Command/PHPCallback.php \
		XML/Query2XML/Command/Static.php \
		XML/Query2XML/Command/Unserialize.php \
		XML/Query2XML/Driver/ADOdb.php \
		XML/Query2XML/Driver/DB.php \
		XML/Query2XML/Driver/LDAP.php \
		XML/Query2XML/Driver/MDB2.php \
		XML/Query2XML/Driver/PDO.php

DOCS=	case01/case01.php case01/case01.xml case02/case02.log \
	case02/case02.php case02/case02.profile \
	case02/case02.xml case02/case02_debug.php \
	case03/case03.log case03/case03.php case03/case03.profile \
	case03/case03.xml case03/case03_debug.php \
	case04/case04.log case04/case04.php case04/case04.profile \
	case04/case04.xml case04/case04_debug.php case05/case05.log \
	case05/case05.php case05/case05.profile case05/case05.xml \
	case05/case05_debug.php case06/case06.log case06/case06.php \
	case06/case06.profile case06/case06.xml case06/case06_debug.php \
	case07/case07.log case07/case07.php case07/case07.profile \
	case07/case07.xml case07/case07_debug.php case08/case08.log \
	case08/case08.php case08/case08.profile case08/case08.xml \
	case08/case08_debug.php
_DOCSDIR=	cases

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
