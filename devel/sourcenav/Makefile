# ex: ts=8
# New ports collection makefile for:	sourcenav
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	sourcenav
PORTVERSION=	4
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	sourcenavigator-NG${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Source code analysis tool

USE_BZIP2=	yes
USE_XORG=	x11

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}/${PORTNAME}

post-install:
	${LN} -s ${PREFIX}/${PORTNAME}/bin/snavigator ${PREFIX}/bin

.include <bsd.port.mk>
