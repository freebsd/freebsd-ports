# Created by: Antonio Carlos Venancio Junior (<antonio@php.net>)
# $FreeBSD$

PORTNAME=	DB_DataObject_FormBuilder
PORTVERSION=	1.0.2
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Automatically build HTML_QuickForm objects using DB_DataObject

LICENSE=	LGPL3

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:devel/pear-HTML_QuickForm@${PHP_FLAVOR} \
		${PEARDIR}/DB/DataObject.php:databases/pear-DB_DataObject@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:devel/pear-HTML_QuickForm@${PHP_FLAVOR} \
		${PEARDIR}/DB/DataObject.php:databases/pear-DB_DataObject@${PHP_FLAVOR}

USES=		pear
OPTIONS_DEFINE=	PEAR_DATE PEAR_HTML_TABLE
PEAR_DATE_DESC=	PEAR::Date support
PEAR_HTML_TABLE_DESC=	PEAR::HTML_Table support

PEAR_DATE_RUN_DEPENDS=	${PEARDIR}/Date.php:devel/pear-Date@${PHP_FLAVOR}
PEAR_HTML_TABLE_RUN_DEPENDS=	${PEARDIR}/HTML/Table.php:devel/pear-HTML_Table@${PHP_FLAVOR}

.include <bsd.port.mk>
