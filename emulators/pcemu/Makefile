# Created by: joerg
# $FreeBSD$

PORTNAME=	pcemu
PORTVERSION=	1.01b
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	LOCAL/joerg
DISTNAME=	pcemu1.01alpha

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	8086 PC emulator, by David Hedley

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontdir:x11-fonts/mkfontdir \
		mkfontscale:x11-fonts/mkfontscale

USE_XORG=	x11 xext
MAKE_ENV=	FILESDIR=${FILESDIR} STAGEDIR=${STAGEDIR}
MAKE_ARGS=	CC="${CC}"

.include <bsd.port.mk>
