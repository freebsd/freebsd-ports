# New ports collection makefile for:	xzx
# Date created:         13 Nov 1997
# Whom:                 Sheldon Hearn <axl@iafrica.com>
#
# $FreeBSD$
#

PORTNAME=	xzx
PORTVERSION=	4.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.philosys.de/~kunze/xzx.purespace.de/xzx/
DISTNAME=	${PORTNAME}-pro-${PORTVERSION}-eval

MAINTAINER=	adamw@FreeBSD.org

PORTCOMMENT=	ZX Spectrum (48K/128K/+3) Emulator for X11

# xmkmf is used in configure script
BUILD_DEPENDS=	xmkmf:${PORTSDIR}/devel/imake-4

WRKSRC=		${WRKDIR}/${PORTNAME}-pro-${PORTVERSION}

USE_MOTIF=      yes
USE_XPM=        yes
USE_X_PREFIX=	yes

# License forbids redistribution
NO_CDROM=	Redistribution forbidden by license
NO_PACKAGE=	Redistribution forbidden by license

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-oss

MAN1=		xzx.1

.include <bsd.port.mk>
