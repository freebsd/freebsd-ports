# ex:ts=8
# Ports collection makefile for:  minicom
# Date created:			  Fri Dec 01, 1995
# Whom:				  obrien@cs.ucdavis.edu
#
# $FreeBSD$
#

PORTNAME=	minicom
PORTVERSION=	1.83.1
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SUNSITE}  \
		http://www.pp.clinet.fi/~walker/mc-dev/  \
		http://www.clinet.fi/~walker/  \
		http://www.pp.clinet.fi/~walker/
MASTER_SITE_SUBDIR=	apps/serialcomm/dialout
DISTFILES=	${DISTNAME}.src${EXTRACT_SUFX}

FORBIDDEN=	"Local exploit yielding setuid uucp"

MAINTAINER=	obrien@FreeBSD.org

RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz \
		lsz:${PORTSDIR}/comms/lrzsz

WRKSRC=		${WRKDIR}/${DISTNAME}/src
#USE_GMAKE=	"for ``po'' dir stuff"
MAN1=		minicom.1 runscript.1 ascii-xfr.1

.if !defined(BATCH)
pre-install:
	# this script creates a link from your comm port to /dev/modem
	${SH} ${SCRIPTDIR}/create-dev-link
.endif

.include <bsd.port.mk>
