# New ports collection makefile for:    workman
# Version required:     1.3a
# Date created:         25 Now 1995
# Whom:                 Donald Burr <d_burr@ix.netcom.com>
#
# $Id: Makefile,v 1.7 1998/09/28 01:54:23 steve Exp $
#

DISTNAME=       WorkMan-1.3a
PKGNAME=	workman-1.3a
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/WorkMan

MAINTAINER=	d_burr@ix.netcom.com

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview-lib

OSVERSION!=     sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=		scsi.h
.endif

WRKSRC=		${WRKDIR}/workman
USE_IMAKE=	yes
MAN1=		workman.1

.include <bsd.port.mk>
