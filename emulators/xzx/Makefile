# New ports collection makefile for:	xzx
# Date created:         13 Nov 1997
# Whom:                 Sheldon Hearn <axl@iafrica.com>
#
# $FreeBSD$
#

PORTNAME=	xzx
PORTVERSION=	4.3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	adamw
DISTNAME=	${PORTNAME}-pro-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ZX Spectrum (48K/128K/+3) Emulator for X11

# xmkmf is used in configure script
BUILD_DEPENDS=  xmkmf:${PORTSDIR}/devel/imake-4

USE_MOTIF=      yes
USE_X_PREFIX=	yes

# License forbids redistribution
RESTRICTED=	Redistribution forbidden by license

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-oss

MAN1=		xzx.1

.include <bsd.port.mk>
