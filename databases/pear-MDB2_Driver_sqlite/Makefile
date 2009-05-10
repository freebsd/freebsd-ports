# New ports collection makefile for:	pear-MDB2_Driver_sqlite
# Date created:				07 Feb 2007
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MDB2_Driver_sqlite
PORTVERSION=	1.5.0b2
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR sqlite MDB2 driver

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	sqlite

FILES=		MDB2/Driver/Datatype/sqlite.php \
		MDB2/Driver/Function/sqlite.php \
		MDB2/Driver/Manager/sqlite.php \
		MDB2/Driver/Native/sqlite.php \
		MDB2/Driver/Reverse/sqlite.php \
		MDB2/Driver/sqlite.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
