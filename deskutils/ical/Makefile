# ex:ts=8
# New ports collection makefile for:    ical
# Date created:         Mon Aug 28 13:35:31 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	ical
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES?=	deskutils tk
MASTER_SITES=	ftp://ftp.sunet.se/pub/vendor/sco/skunkware/src/shellutil/

PATCH_SITES=	http://www.isi.edu/~johnh/SOFTWARE/ICAL/
PATCHFILES=	ical-2.3.1-upvar.patch

MAINTAINER?=	obrien@FreeBSD.org
COMMENT?=	A calendar application

USE_TK?=	85

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclconfig=${TCL_LIBDIR} \
		--with-tclhdir=${TCL_INCLUDEDIR} \
		--with-tclsh=${TCLSH} \
		--with-tkconfig=${TK_LIBDIR} \
		--with-tkhdir=${TK_INCLUDEDIR}

MAN1=		ical.1

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
