# Created by: joerg
# $FreeBSD$

PORTNAME=	pcemu
PORTVERSION=	1.01b
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	joerg
DISTNAME=	pcemu1.01alpha

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	8086 PC emulator, by David Hedley

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_XORG=	x11 xext
MAKE_ENV=	FILESDIR=${FILESDIR} STAGEDIR=${STAGEDIR}
MAKE_ARGS=	CC="${CC}"

.include <bsd.port.mk>
