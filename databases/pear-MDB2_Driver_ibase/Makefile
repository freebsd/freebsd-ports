# New ports collection makefile for:   pear-MDB2_Driver_ibase
# Date created:        29 April 2007
# Whom:                Martin Wilke <miwi@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	MDB2_Driver_ibase
DISTVERSION=	1.5.0b3
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR ibase MDB2 driver

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	interbase

BROKEN=		fails to build

FILES=		MDB2/Driver/ibase.php \
		MDB2/Driver/Datatype/ibase.php \
		MDB2/Driver/Function/ibase.php \
		MDB2/Driver/Manager/ibase.php \
		MDB2/Driver/Native/ibase.php \
		MDB2/Driver/Reverse/ibase.php

TESTS=		MDB2_nonstandard_ibase.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
