# New ports collection makefile for:    cdd
# Date created:         Wed Dec 23 11:15:30 CET 1998
# Whom:                 luigi@iet.unipi.it
#
# $FreeBSD$
#

PORTNAME=	cdd
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.iet.unipi.it/~luigi/cdd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	luigi@iet.unipi.it

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 400000
BROKEN=		pre-CAM SCSI layer
.endif

post-extract:
	${CP} ${FILESDIR}/cdd_atapicmds.[ch] ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdd ${PREFIX}/bin

.include <bsd.port.post.mk>
