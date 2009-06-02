# New ports collection makefile for:	linux-curl
# Date created:		2006-08-04
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.13.1
PORTREVISION=	2
CATEGORIES=	ftp linux
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION}-5.fc4

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Curl linux version

CONFLICTS=	linux-f8-curl-[0-9]* linux-f10-curl-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
AUTOMATIC_PLIST=	yes
DESCR=	${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
