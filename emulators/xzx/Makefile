# New ports collection makefile for:	xzx
# Date created:         13 Nov 1997
# Whom:                 Sheldon Hearn <axl@iafrica.com>
#
# $FreeBSD$
#

PORTNAME=	xzx
PORTVERSION=	4.0
CATEGORIES=	emulators
MASTER_SITES=	http://www.zx-spectrum.net/xzx/files/
DISTNAME=	${PORTNAME}-pro-${PORTVERSION}-eval

MAINTAINER=	flynn@energyhq.homeip.net

# xmkmf is used in configure script
BUILD_DEPENDS=	xmkmf:${PORTSDIR}/devel/imake-4

WRKSRC=		${WRKDIR}/${PORTNAME}-pro-${PORTVERSION}

USE_MOTIF=      yes
USE_XPM=        yes
USE_X_PREFIX=	yes

# Hardcoding FETCH_CMD is necessary since -A argument causes problems
FETCH_CMD=	/usr/bin/fetch

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-oss

MAN1=		xzx.1

.include <bsd.port.mk>
