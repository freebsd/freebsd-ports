# New ports collection makefile for:	swarm
# Date created:		26 June 1998
# Whom:			Horance C.H Chou <horance@freedom.ie.cycu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	swarm
PORTVERSION=	2.1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.santafe.edu/pub/swarm/src/swarm/

MAINTAINER=	horance@freedom.ie.cycu.edu.tw

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs21
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		BLT24.2:${PORTSDIR}/x11-toolkits/blt

USE_JAVA=	1.3+
USE_GMAKE=	yes
USE_XPM=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-defaultdir=${PREFIX} \
		--with-tclincludedir=${PREFIX}/include/tcl8.3 \
		--with-tkincludedir=${PREFIX}/include/tk8.3 \
		--with-tclscriptdir=${PREFIX}/lib/tcl8.3 \
		--with-tkscriptdir=${PREFIX}/lib/tk8.3 \
		--enable-subdirs

post-install:
	${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%PREFIX%%:${PREFIX}:g"

.include <bsd.port.mk>
