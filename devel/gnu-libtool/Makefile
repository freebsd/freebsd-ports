# New ports collection makefile for:	libtool
# Date created:		6 May 1998
# Whom:			Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	libtool
PORTVERSION=	1.5.14
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libtool
PKGNAMEPREFIX=	gnu-
DISTNAME=	libtool-${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Generic shared library support script (version 1.5)

PREFIX?=	${LOCALBASE}/gnu-autotools

PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
GNU_CONFIGURE=	yes
NO_MTREE=	yes
INFO=		libtool
CONFIGURE_ARGS=	--disable-ltdl-install
CONFIGURE_ENV=	PREFIX=${PREFIX}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
