# New ports collection makefile for:	swarm
# Date created:		26 June 1998
# Whom:			Horance C.H Chou <horance@freedom.ie.cycu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	swarm
PORTVERSION=	1.4.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.santafe.edu/pub/swarm/src/swarm/

MAINTAINER=	horance@freedom.ie.cycu.edu.tw

LIB_DEPENDS=	ffi.2:${PORTSDIR}/devel/libffi \
		png.4:${PORTSDIR}/graphics/png \
		BLT24.2:${PORTSDIR}/x11-toolkits/blt

USE_GMAKE=	yes
USE_XPM=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-defaultdir=${PREFIX} \
		--with-tclincludedir=${PREFIX}/include/tcl8.3 \
		--with-tkincludedir=${PREFIX}/include/tk8.3 \
		--with-tclscriptdir=${PREFIX}/lib/tcl8.3 \
		--with-tkscriptdir=${PREFIX}/lib/tk8.3

.include <bsd.port.mk>
