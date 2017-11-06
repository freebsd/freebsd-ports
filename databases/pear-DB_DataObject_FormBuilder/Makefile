# Created by: Antonio Carlos Venancio Junior (<antonio@php.net>)
# $FreeBSD$

PORTNAME=	DB_DataObject_FormBuilder
PORTVERSION=	1.0.2
CATEGORIES=	databases www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Automatically build HTML_QuickForm objects using DB_DataObject

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:devel/pear-HTML_QuickForm \
		${PEARDIR}/DB/DataObject.php:databases/pear-DB_DataObject
RUN_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:devel/pear-HTML_QuickForm \
		${PEARDIR}/DB/DataObject.php:databases/pear-DB_DataObject

USES=		pear
OPTIONS_DEFINE=	PEAR_DATE PEAR_HTML_TABLE
PEAR_DATE_DESC=	PEAR::Date support
PEAR_HTML_TABLE_DESC=	PEAR::HTML_Table support

PEAR_DATE_RUN_DEPENDS=	${PEARDIR}/Date.php:devel/pear-Date
PEAR_HTML_TABLE_RUN_DEPENDS=	${PEARDIR}/HTML/Table.php:devel/pear-HTML_Table

.include <bsd.port.mk>
