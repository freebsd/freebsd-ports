# Created by: cartola (Carlos E. G. Carvalho)
# $FreeBSD$

PORTNAME=	linux-panorama-tools
PORTVERSION=	2.6b1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.all-in-one.ee/~dersch/
DISTNAME=	PanoTools

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Software to view, create, edit, and remap panoramic images

DEPRECATED=	Vendor site is gone, archive is from 2001 and depends on to-be-removed libpng

NO_BUILD=	yes
USE_LINUX_PREFIX=yes
USE_LDCONFIG=	yes
# USE_LINUX is supposed to be defined automatically when USE_LINUX_PREFIX and
# USE_LDCONFIG are defined but it is not :-/
USE_LINUX=	yes
USE_LINUX_APPS=	jpeg png10 tiff

WRKSRC=	${WRKDIR}/PTLinux

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Helpers/PTStitcher ${PREFIX}/usr/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/libpano12.so ${PREFIX}/usr/lib/
	${LN} -sf ${PREFIX}/usr/bin/PTStitcher ${LOCALBASE}/bin/

.include <bsd.port.mk>
