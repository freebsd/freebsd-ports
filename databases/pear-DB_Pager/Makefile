# Ports collection makefile for:  pear-DB_Pager
# Date created:			  25 Febrary 2004
# Whom:				  Toshiya Saitoh (<toshiya@saitoh.nu>)
#
# $FreeBSD$
#

PORTNAME=	DB_Pager
PORTVERSION=	0.7
CATEGORIES=	databases www pear

MAINTAINER=	toshiya@saitoh.nu
COMMENT=	PEAR Database Abstraction Layer

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes
FILES=		Pager.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
