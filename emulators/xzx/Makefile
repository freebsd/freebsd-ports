# New ports collection makefile for:	xzx
# Date created:         13 Nov 1997
# Whom:                 Sheldon Hearn <axl@iafrica.com>
#
# $FreeBSD$
#

PORTNAME=	xzx
PORTVERSION=	3.0.0
CATEGORIES=	emulators
MASTER_SITES=	http://www.zophar.net/unix/Files/

MAINTAINER=	flynn@energyhq.homeip.net

# xmkmf is used in configure script
BUILD_DEPENDS=	xmkmf:${PORTSDIR}/devel/imake-4

USE_MOTIF=      yes
USE_XPM=        yes
USE_X_PREFIX=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-oss

MAN1=		xzx.1

.include <bsd.port.mk>
