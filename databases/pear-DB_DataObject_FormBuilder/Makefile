# Created by: Antonio Carlos Venancio Junior (<antonio@php.net>)
# $FreeBSD$

PORTNAME=	DB_DataObject_FormBuilder
PORTVERSION=	1.0.2
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Automatically build HTML_QuickForm objects using DB_DataObject

BUILD_DEPENDS=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm \
		${PEARDIR}/DB/DataObject.php:${PORTSDIR}/databases/pear-DB_DataObject
RUN_DEPENDS:=	${PEARDIR}/HTML/QuickForm.php:${PORTSDIR}/devel/pear-HTML_QuickForm \
		${PEARDIR}/DB/DataObject.php:${PORTSDIR}/databases/pear-DB_DataObject

LATEST_LINK=	pear-DB_DataObject_FormBuilder
OPTIONS_DEFINE=	PEAR_DATE PEAR_HTML_TABLE
PEAR_DATE_DESC=	PEAR::Date support
PEAR_HTML_TABLE_DESC=	PEAR::HTML_Table support

PEAR_AUTOINSTALL=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_DATE}
RUN_DEPENDS+=	${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date
.endif

.if ${PORT_OPTIONS:MPEAR_HTML_TABLE}
RUN_DEPENDS+=	${PEARDIR}/HTML/Table.php:${PORTSDIR}/devel/pear-HTML_Table
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
