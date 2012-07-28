# New ports collection makefile for:   linux-panorama-tools
# Date created:        26 august 2004
# Whom:                cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
#
# This port has been made as a running dependence for the hugin port.
# The hugin port for itself would run with no problem without this port,
# but the final step that generates the panorama images make use of the
# external program PTStitcher, installed by this port.
# This port, as a dependence, does not install the complete linux
# panorama tools, just the few things necessary to hugin.

PORTNAME=	linux-panorama-tools
PORTVERSION=	2.6b1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.all-in-one.ee/~dersch/
DISTNAME=	PanoTools

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Software to view, create, edit, and remap panoramic images

NO_BUILD=	yes
USE_LINUX_PREFIX=yes
USE_LDCONFIG=	yes
# USE_LINUX is supposed to be defined automatically when USE_LINUX_PREFIX and
# USE_LDCONFIG are defined but it is not :-/
USE_LINUX=	yes
USE_LINUX_APPS=	jpeg png10 tiff

WRKSRC=	${WRKDIR}/PTLinux

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Helpers/PTStitcher ${PREFIX}/usr/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/libpano12.so ${PREFIX}/usr/lib/
	${LN} -sf ${PREFIX}/usr/bin/PTStitcher ${LOCALBASE}/bin/

.include <bsd.port.mk>
