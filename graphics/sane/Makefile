# New ports collection makefile for:	sane
# Version required:     0.61
# Date created:         Sat Jul 19 16:23:10 MET DST 1997
# Whom:                 gary@hotlava.com
#			obrien@FreeBSD.org
#
# $Id$
#

DISTNAME=       sane-0.65
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/capture

MAINTAINER=	gary@hotlava.com

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	scanimage.1 xscanimage.1 saned.1
MAN5=	sane-dll.5 sane-hp.5 sane-mustek.5 sane-net.5 sane-pnm.5 sane-pint.5  \
	sane-qcam.5 sane-umax.5 sane-scsi.5

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
