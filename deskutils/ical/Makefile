# New ports collection makefile for:    ical
# Version required:     2.1
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.4 1995/11/26 10:47:37 asami Exp $
#

DISTNAME=	ical-2.1b2
CATEGORIES+=	misc
MASTER_SITES=	http://www.research.digital.com/SRC/personal/Sanjay_Ghemawat/ical/icalbins/

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS=    tk41\\.1:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclsh=/usr/bin/tclsh \
		--with-tclconfig=/usr/libdata/tcl \
		--with-tkconfig=${PREFIX}/lib

.if !defined(NOMANCOMPRESS)
afterinstall:
	gzip -9nf ${PREFIX}/man/man1/ical.1
.endif

.include <bsd.port.mk>
