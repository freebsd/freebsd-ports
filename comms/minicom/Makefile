# ex:ts=8
# New ports collection makefile for:    minicom
# Version required:     1.74
# Date created:         Fri Dec 01, 1995
# Whom:                 obrien@cs.ucdavis.edu
#
# $Id: Makefile,v 1.17 1999/02/14 06:55:16 asami Exp $
#

DISTNAME=	${PKGNAME}.src
PKGNAME=	minicom-1.82.1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.cistron.nl/pub/people/miquels/software/  \
		${MASTER_SITE_SUNSITE}  \
		http://www.clinet.fi/~walker/
MASTER_SITE_SUBDIR=	apps/serialcomm/dialout

MAINTAINER=     obrien@FreeBSD.org

RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz \
		lsz:${PORTSDIR}/comms/lrzsz

WRKSRC=		${WRKDIR}/${PKGNAME}/src
#USE_GMAKE=	"for ``po'' dir stuff"
MAN1=		minicom.1 runscript.1 ascii-xfr.1

.if !defined(BATCH)
pre-install:
	# this script creates a link from your comm port to /dev/modem
	${SH} ${SCRIPTDIR}/create-dev-link
.endif

.include <bsd.port.mk>
