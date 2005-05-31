# New ports collection makefile for:	resid
# Date created:				6 October 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	resid
PORTVERSION=	0.15
CATEGORIES=	audio emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sidplay2
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cycle-based SID emulator engine

USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-shared
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
