# New ports collection makefile for: otcl
# Version required:	1.0a5
# Date created:		23 April 1999
# Whom:			obonilla
#
# $FreeBSD$
#

DISTNAME=	otcl-1.0a5
CATEGORIES=	lang
MASTER_SITES=	http://www-mash.cs.berkeley.edu/dist/

MAINTAINER=	obonilla@fisicc-ufm.edu

LIB_DEPENDS=    tk82.1:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-ver=8.2 --with-tk-ver=8.2
USE_AUTOCONF= yes

post-install:
	${LN} -sf libotcl.so ${PREFIX}/lib/libotcl.so.1
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	strip ${PREFIX}/bin/otclsh
	strip ${PREFIX}/bin/owish

.include <bsd.port.mk>
