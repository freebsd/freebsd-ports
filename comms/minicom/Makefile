# New ports collection makefile for:    minicom
# Version required:     1.74
# Date created:         Fri Dec 01, 1995
# Whom:                 obrien@cs.ucdavis.edu
#
# $Id: Makefile,v 1.10 1997/04/04 15:58:10 obrien Exp $
#

DISTNAME=	minicom-1.75
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.cistron.nl/pub/people/miquels/software/
MASTER_SITE_SUBDIR= apps/serialcomm/dialout

MAINTAINER=     obrien@FreeBSD.org

RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz \
		lsz:${PORTSDIR}/comms/lrzsz \
		kermit:${PORTSDIR}/comms/kermit

WRKSRC=		${WRKDIR}/${PKGNAME}/src
MAN1=		minicom.1 runscript.1 ascii-xfr.1

.if !defined(BATCH)
pre-install:
	# this script creates a link from your comm port to /dev/modem
	${SH} ${SCRIPTDIR}/create-dev-link
.endif

.include <bsd.port.mk>
