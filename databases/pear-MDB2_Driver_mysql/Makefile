# New ports collection makefile for:	pear-MDB2_Driver_mysql
# Date created:				07 Feb 2007
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MDB2_Driver_mysql
DISTVERSION=	1.5.0b2
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR mysql MDB2 driver

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	mysql

FILES=		MDB2/Driver/mysql.php \
		MDB2/Driver/Datatype/mysql.php \
		MDB2/Driver/Function/mysql.php \
		MDB2/Driver/Manager/mysql.php \
		MDB2/Driver/Native/mysql.php \
		MDB2/Driver/Reverse/mysql.php \

TESTS=		MDB2_nonstandard_mysql.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
