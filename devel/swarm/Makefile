# New ports collection makefile for:	swarm
# Version required:	1.4.1
# Date created:		26 June 1998
# Whom:			Horance C.H Chou <horance@freedom.ie.cycu.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	swarm-1.4.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.santafe.edu/pub/swarm/

MAINTAINER=	horance@freedom.ie.cycu.edu.tw

LIB_DEPENDS=	ffi.2:${PORTSDIR}/devel/libffi \
		png.3:${PORTSDIR}/graphics/png \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		BLT24.2:${PORTSDIR}/x11-toolkits/blt

USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-defaultdir=${PREFIX} \
		--with-tclincludedir=${PREFIX}/include/tcl8.2 \
		--with-tkincludedir=${PREFIX}/include/tk8.2 \
		--with-tclscriptdir=${PREFIX}/lib/tcl8.2 \
		--with-tkscriptdir=${PREFIX}/lib/tk8.2

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
