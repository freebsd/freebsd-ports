# New ports collection makefile for:    ical
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	ical
PORTVERSION=	2.2
CATEGORIES=	deskutils tk83
MASTER_SITES=	ftp://ftp.sco.com/skunkware/src/shellutil/ \
		ftp://ftp.sunet.se/pub/vendor/sco/skunkware/src/shellutil/ \
		ftp://ftp.netsw.org/netsw/X11/Tools/Desktop/ \
		ftp://ftp.kddlabs.co.jp/sourceforge/ical/ \
		ftp://ftp.sunsite.org.uk/Mirrors/ftp.sco.com/skunkware/src/shellutil/

MAINTAINER=	obrien@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclconfig=${PREFIX}/lib/tcl8.3 \
		--with-tclhdir=${PREFIX}/include/tcl8.3 \
		--with-tclsh=${PREFIX}/bin/tclsh8.3 \
		--with-tkconfig=${PREFIX}/lib/tk8.3 \
		--with-tkhdir=${PREFIX}/include/tk8.3

MAN1=		ical.1

post-install:
	@strip ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
