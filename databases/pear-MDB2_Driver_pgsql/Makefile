# New ports collection makefile for:	pear-MDB2_Driver_pgsql
# Date created:				07 Feb 2007
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MDB2_Driver_pgsql
DISTVERSION=	1.5.0b2
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR pgsql MDB2 driver

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	pgsql

FILES=		MDB2/Driver/Datatype/pgsql.php \
		MDB2/Driver/Function/pgsql.php \
		MDB2/Driver/Manager/pgsql.php \
		MDB2/Driver/Native/pgsql.php \
		MDB2/Driver/Reverse/pgsql.php \
		MDB2/Driver/pgsql.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
