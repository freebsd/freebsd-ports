# New ports collection makefile for:    ical
# Version required:     2.1
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.19 1998/08/07 22:17:52 asami Exp $
#

DISTNAME=	ical-2.2
CATEGORIES=	deskutils tk80
MASTER_SITES=	http://www.research.digital.com/SRC/personal/Sanjay_Ghemawat/ical/icalbins/

MAINTAINER=	erich@FreeBSD.ORG

LIB_DEPENDS=    tk80\\.1:${PORTSDIR}/x11-toolkits/tk80

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tclconfig=${PREFIX}/lib/tcl8.0 \
		--with-tclhdir=${PREFIX}/include/tcl8.0 \
		--with-tclsh=${PREFIX}/bin/tclsh8.0 \
		--with-tkconfig=${PREFIX}/lib/tk8.0 \
		--with-tkhdir=${PREFIX}/include/tk8.0

MAN1=		ical.1

post-install:
	@strip ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
