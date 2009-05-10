# New ports collection makefile for:	pear-MDB2_Driver_mysqli
# Date created:				07 Feb 2007
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MDB2_Driver_mysqli
DISTVERSION=	1.5.0b2
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR mysql MDB2 driver

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	mysqli

FILES=		MDB2/Driver/Datatype/mysqli.php \
		MDB2/Driver/Function/mysqli.php \
		MDB2/Driver/Manager/mysqli.php \
		MDB2/Driver/Native/mysqli.php \
		MDB2/Driver/Reverse/mysqli.php \
		MDB2/Driver/mysqli.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
