PORTNAME=	pcemu
PORTVERSION=	1.01b
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	LOCAL/joerg
DISTNAME=	pcemu1.01alpha

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	8086 PC emulator, by David Hedley

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf
RUN_DEPENDS=	mkfontscale:x11-fonts/mkfontscale

USES=		dos2unix xorg fonts
USE_XORG=	x11 xext
DOS2UNIX_FILES=	programs/config.sys
MAKE_ENV=	FILESDIR=${FILESDIR} STAGEDIR=${STAGEDIR} FONTSDIR=${FONTSDIR}
MAKE_ARGS=	CC="${CC}"

.include <bsd.port.mk>
