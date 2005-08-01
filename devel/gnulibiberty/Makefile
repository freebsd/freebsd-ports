# New ports collection makefile for:	libiberty
# Date created:		27 Feb 2004
# Whom:			Joerg Wunsch <joerg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gnulibiberty
PORTVERSION=	2.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
DISTNAME=	binutils-${PORTVERSION}

MAINTAINER=	joerg@freebsd.org
COMMENT=	Miscellaneous GNU functions

WRKSRC=		${WRKDIR}/binutils-${PORTVERSION}/libiberty

USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-install-libiberty
USE_LIBTOOL_VER=13

CONFLICTS=	freelibiberty-*

.include <bsd.port.mk>
