# New ports collection makefile for:	sane
# Version required:     0.73
# Date created:         Sat Jul 19 16:23:10 MET DST 1997
# Whom:                 gary@hotlava.com
#			obrien@FreeBSD.org
#
# $Id: Makefile,v 1.4 1998/05/26 08:17:56 dburr Exp $
#

DISTNAME=       sane-0.73
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/ \
		ftp://ftp.lahn.de/pub/platforms/linux/libs/

MAINTAINER=	gary@hotlava.com

LIB_DEPENDS=	gtk\\.1\\.:${PORTSDIR}/x11/gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		scanimage.1 xscanimage.1 saned.1
MAN5=		sane-dll.5 sane-hp.5 sane-mustek.5 sane-net.5 sane-pnm.5 \
		sane-pint.5 sane-qcam.5 sane-umax.5 sane-scsi.5 sane-dmc.5 \
		sane-epson.5 sane-microtek.5 sane-microtek2.5

pre-configure:
	@${ECHO} "*** Note: SANE can be built with an X scanner interface"
	@${ECHO} "*** (xscanimage) as well as a GIMP plug-in.  If you wish"
	@${ECHO} "*** to do this, hit Ctrl-C right now and build/install"
	@${ECHO} "*** the GIMP and GTK packages/ports."

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
