# New ports collection makefile for: otcl
# Version required:	1.0a4
# Date created:		23 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

DISTNAME=	otcl-1.0a4
CATEGORIES=	lang
MASTER_SITES=	http://www-mash.cs.berkeley.edu/dist/

MAINTAINER=	obonilla@fisicc-ufm.edu

LIB_DEPENDS=    tk82.1:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/tcl8.2/generic \
		--with-tcl-ver=8.2

post-install:
	${LN} -sf libotcl.so.1 ${PREFIX}/lib/libotcl.so
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
