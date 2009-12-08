# New ports collection makefile for:	abiword-extras
# Date created:		2008-04-16
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abiword-extras
PORTVERSION=	2.6.8
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/%SUBDIR%/${PORTVERSION}/source/
MASTER_SITE_SUBDIR=	abiword
DIST_SUBDIR=	AbiWord

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	AbiWord extras (Templates, clipart, dictionary files, etc)

BUILD_DEPENDS=	abiword:${PORTSDIR}/editors/abiword
RUN_DEPENDS=	abiword:${PORTSDIR}/editors/abiword

GNU_CONFIGURE=	yes

BROKEN=	requires author to publish updated distfile

.include <bsd.port.mk>
