# New ports collection makefile for:    minicom
# Version required:     1.74
# Date created:         Fri Dec 01, 1995
# Whom:                 obrien@cs.ucdavis.edu
#
# $Id: Makefile,v 1.1.1.1 1996/03/05 07:46:57 asami Exp $
#

DISTNAME=	minicom-1.75
CATEGORIES+=	comms
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/apps/comm/ \
		ftp://ftp.yggdrasil.com/mirrors/sunsite/apps/comm/

MAINTAINER=     obrien@cs.ucdavis.edu

RUN_DEPENDS=	rz:${PORTSDIR}/comms/rzsz \
		sz:${PORTSDIR}/comms/rzsz \
		kermit:${PORTSDIR}/comms/kermit

WRKSRC=		${WRKDIR}/${PKGNAME}/src

.if !defined(BATCH)
pre-install:
	# this script creates a link from your comm port to /dev/modem
	/bin/sh ${SCRIPTDIR}/create-dev-link
.endif

post-install:
.if !defined(NOMANCOMPRESS)
	@for mp in minicom.1 runscript.1 ascii-xfr.1 ; do \
		gzip -9nf ${PREFIX}/man/man1/$$mp ; done
.endif

.include <bsd.port.mk>
