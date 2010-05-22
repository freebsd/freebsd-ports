# New ports collection makefile for:	abiword-docs
# Date created:		2008-04-16
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/abiword-docs/Makefile,v 1.1 2009/11/10 14:08:20 kwm Exp $
#

PORTNAME=	abiword-docs
PORTVERSION=	2.8.4
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/%SUBDIR%/${PORTVERSION}/source/
MASTER_SITE_SUBDIR=	abiword
DIST_SUBDIR=	AbiWord

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	AbiWord help files

BUILD_DEPENDS=	abiword:${PORTSDIR}/editors/abiword
RUN_DEPENDS=	abiword:${PORTSDIR}/editors/abiword

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
# Don't give X warnings if DISPLAY is set
CONFIGURE_ENV=	DISPLAY=""
MAKE_ENV=	DISPLAY=""

.include <bsd.port.mk>
