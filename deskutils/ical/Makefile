# New ports collection makefile for:    ical
# Version required:     2.1
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.12 1997/11/22 01:11:31 asami Exp $
#

DISTNAME=	ical-2.1b2
CATEGORIES=	misc
MASTER_SITES=	http://www.research.digital.com/SRC/personal/Sanjay_Ghemawat/ical/icalbins/

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS=    tk42\\.1:${PORTSDIR}/x11/tk42

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclsh=${PREFIX}/bin/tclsh7.6 \
		--with-tclconfig=${PREFIX}/lib/tcl7.6 \
		--with-tkconfig=${PREFIX}/lib/tk4.2
MAN1=		ical.1

post-install:
	@strip ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
