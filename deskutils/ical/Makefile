# New ports collection makefile for:    ical
# Version required:     2.1
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.6 1996/11/11 05:49:38 obrien Exp $
#

DISTNAME=	ical-2.1b2
CATEGORIES=	misc
MASTER_SITES=	http://www.research.digital.com/SRC/personal/Sanjay_Ghemawat/ical/icalbins/

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS=    tk41\\.1:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclsh=/usr/bin/tclsh \
		--with-tclconfig=/usr/libdata/tcl \
		--with-tkconfig=${PREFIX}/lib
MAN1=		ical.1

.include <bsd.port.mk>
