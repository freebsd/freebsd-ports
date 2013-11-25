# Created by: wenheping<wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	XML_Query2XML
PORTVERSION=	1.7.2
CATEGORIES=	databases pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class transform SQL queries into XML data

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB

LATEST_LINK=	pear-XML_Query2xml
OPTIONS_DEFINE=	PEAR_MDB2 PEAR_NET_LDAP2
PEAR_MDB2_DESC=	Add support for pear-MDB2
PEAR_NET_LDAP2_DESC=	Add support for pear-Net_LDAP2

PEAR_AUTOINSTALL=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_MDB2}
BUILD_DEPENDS+=	${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
.endif

.if ${PORT_OPTIONS:MPEAR_NET_LDAP2}
BUILD_DEPENDS+=	${PEARDIR}/Net/LDAP2.php:${PORTSDIR}/net/pear-Net_LDAP2
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
