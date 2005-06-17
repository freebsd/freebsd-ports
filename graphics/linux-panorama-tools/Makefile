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
# panorama tools, just the few things necessary to hugin. If someone
# wants the rest just tell me.

PORTNAME=	linux-panorama-tools
PORTVERSION=	2.6b1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.path.unimelb.edu.au/~dersch/
DISTNAME=	PanoTools

MAINTAINER=	cartola@openit.com.br
COMMENT=	Software to View, Create, Edit and Remap Panoramic Images

RUN_DEPENDS=	${LINUXBASE}/usr/bin/jpegtran:${PORTSDIR}/graphics/linux-jpeg \
		${LINUXBASE}/usr/lib/libtiff.so.3.6.1:${PORTSDIR}/graphics/linux-tiff \
		${LINUXBASE}/usr/lib/libpng12.so.0.1.2.7:${PORTSDIR}/graphics/linux-png

NO_BUILD=	yes
USE_LINUX=	yes

WRKSRC=	${WRKDIR}/PTLinux
PROGRAM=	Helpers/PTStitcher

do-install:
	${MKDIR} ${PREFIX}/${PORTNAME}/lib
	${MKDIR} ${PREFIX}/${PORTNAME}/bin
	${CP} ${WRKSRC}/${PROGRAM} ${PREFIX}/${PORTNAME}/bin
	${CHMOD} 555 ${PREFIX}/${PORTNAME}/bin/PTStitcher
	${CP} ${WRKSRC}/libpano12.so ${PREFIX}/${PORTNAME}/lib
	${CHMOD} 555 ${PREFIX}/${PORTNAME}/lib/libpano12.so
	${LN} -s ${PREFIX}/${PORTNAME}/bin/PTStitcher ${PREFIX}/bin/PTStitcher
	${LINUXBASE}/sbin/ldconfig ${PREFIX}/${PORTNAME}/lib/

.include <bsd.port.mk>
