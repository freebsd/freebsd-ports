# ex:ts=8
# New ports collection makefile for:    ical
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	ical
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	deskutils tk84
MASTER_SITES=	ftp://ftp.sunet.se/pub/vendor/sco/skunkware/src/shellutil/

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	A calendar application

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclconfig=${PREFIX}/lib/tcl8.4 \
		--with-tclhdir=${PREFIX}/include/tcl8.4 \
		--with-tclsh=${PREFIX}/bin/tclsh8.4 \
		--with-tkconfig=${PREFIX}/lib/tk8.4 \
		--with-tkhdir=${PREFIX}/include/tk8.4

MAN1=		ical.1

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
