# New ports collection makefile for:    ical
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	ical
PORTVERSION=	2.2
CATEGORIES=	deskutils tk82
MASTER_SITES=	http://www.research.digital.com/SRC/personal/Sanjay_Ghemawat/ical/icalbins/

MAINTAINER=	erich@FreeBSD.org

LIB_DEPENDS=    tk82.1:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclconfig=${PREFIX}/lib/tcl8.2 \
		--with-tclhdir=${PREFIX}/include/tcl8.2 \
		--with-tclsh=${PREFIX}/bin/tclsh8.2 \
		--with-tkconfig=${PREFIX}/lib/tk8.2 \
		--with-tkhdir=${PREFIX}/include/tk8.2

MAN1=		ical.1

post-install:
	@strip ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
