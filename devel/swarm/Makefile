# New ports collection makefile for:	swarm
# Version required:			1.3.1
# Date created:				26 June 1998
# Whom:					Horance C.H Chou <horance@freedom.ie.cycu.edu.tw>
#
# $Id: Makefile,v 1.28 1999/01/23 07:05:23 vanilla Exp $
#

DISTNAME=	swarm-1.3.1
#PKGNAME=	swarm-1.3.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.santafe.edu/pub/swarm/

MAINTAINER=	horance@freedom.ie.cycu.edu.tw

LIB_DEPENDS=	ffi.2:${PORTSDIR}/devel/libffi \
		png.3:${PORTSDIR}/graphics/png \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		tcl80.1:${PORTSDIR}/lang/tcl80 \
		tk80.1:${PORTSDIR}/x11-toolkits/tk80 \
		BLT.2:${PORTSDIR}/x11-toolkits/blt

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-defaultdir=${PREFIX} \
		--with-tclincludedir=${PREFIX}/include/tcl8.0/generic \
		--with-tkincludedir=${PREFIX}/include/tk8.0/generic \

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
