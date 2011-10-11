# New ports collection makefile for:	R-cran-RMySQL
# Date created:		2011-08-16
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	RMySQL
DISTVERSION=	0.8-0
PORTREVISION=	1
CATEGORIES=	databases
PKGNAMEPREFIX=	R-cran-
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R interface to the MySQL database

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-DBI>=0.2.2:${PORTSDIR}/databases/R-cran-DBI

USE_MYSQL=	yes
USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
