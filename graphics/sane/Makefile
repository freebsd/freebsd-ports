# New ports collection makefile for:	sane
# Version required:     0.72
# Date created:         Sat Jul 19 16:23:10 MET DST 1997
# Whom:                 gary@hotlava.com
#			obrien@FreeBSD.org
#
# $Id: Makefile,v 1.2 1998/03/11 13:17:05 obrien Exp $
#

DISTNAME=       sane-0.72
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/

MAINTAINER=	gary@hotlava.com

LIB_DEPENDS=	gtk\\.1\\.:${PORTSDIR}/x11/gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		scanimage.1 xscanimage.1 saned.1
MAN5=		sane-dll.5 sane-hp.5 sane-mustek.5 sane-net.5 sane-pnm.5 \
		sane-pint.5 sane-qcam.5 sane-umax.5 sane-scsi.5 sane-dmc.5 \
		sane-epson.5 sane-microtek.5

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
