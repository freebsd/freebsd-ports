# Created by: jmz
# $FreeBSD$

PORTNAME=	xjewel
PORTVERSION=	1.6
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/../R5contrib
EXTRACT_SUFX=	.tar.z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 dropping jewels game

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_XORG=	x11 xext
USE_IMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN6=		xjewel.6

FONTSDIR=	lib/X11/fonts/local
PLIST_SUB=	FONTSDIR=${FONTSDIR}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/bitmaps/seven_seg.pcf.gz ${PREFIX}/${FONTSDIR}
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)

.include <bsd.port.mk>
