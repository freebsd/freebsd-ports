# New ports collection makefile for: otcl
# Version required:	1.0a4
# Date created:		23 April 1999
# Whom:			obonilla
#
# $Id: Makefile,v 1.2 1999/05/09 16:41:29 steve Exp $
#

DISTNAME=	otcl-1.0a4
CATEGORIES=	lang
MASTER_SITES=	http://www-mash.cs.berkeley.edu/dist/

MAINTAINER=	obonilla@fisicc-ufm.edu

LIB_DEPENDS=    tk80.1:${PORTSDIR}/x11-toolkits/tk80

USE_XLIB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/tcl8.0/generic
.include <bsd.port.mk>
