# New ports collection makefile for:	libtool
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	libtool
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtool

MAINTAINER=	reg@FreeBSD.org

# This port has not been upgraded to 1.3.5 because it makes no changes to
# FreeBSD support, and would require that all Ports users upgrade for no
# reason.

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-ltdl-install
CONFIGURE_ENV=	PREFIX=${PREFIX}

.include <bsd.port.mk>
