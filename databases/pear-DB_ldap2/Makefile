# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	DB_ldap2
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	databases net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR DB compliant interface to LDAP v2 and v3 database

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB

USE_PHP=	ldap
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
