# Created by: wenheping<wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	XML_Query2XML
PORTVERSION=	1.7.2
CATEGORIES=	databases pear

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PEAR class transform SQL queries into XML data

BUILD_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB
RUN_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB

OPTIONS_DEFINE=	PEAR_MDB2 PEAR_NET_LDAP2
PEAR_MDB2_DESC=	Add support for pear-MDB2
PEAR_NET_LDAP2_DESC=	Add support for pear-Net_LDAP2

USES=	pear

PEAR_MDB2_BUILD_DEPENDS=	${PEARDIR}/MDB2.php:databases/pear-MDB2
PEAR_NET_LDAP2_BUILD_DEPENDS=	${PEARDIR}/Net/LDAP2.php:net/pear-Net_LDAP2

.include <bsd.port.mk>
