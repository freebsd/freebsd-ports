# New ports collection Makefile for:    tkhylafax-3.0
# Version required:		3.0b2
# Date released:		Sun Jun  8 11:51:21 CEST 1997
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id$
#

DISTNAME=	tkhylafax-3.0b2
PKGNAME=	tkhylafax-3.0
CATEGORIES=	comms
MASTER_SITES=	http://www.NeoSoft.com/tcl/ftparchive/sorted/comm/tkhylafax-3.0b2/

MAINTAINER=	andreas@FreeBSD.org

WRKSRC=		${WRKDIR}/tkhylafax-3.0
RUN_DEPENDS=	wish4.2:${PORTSDIR}/x11/tk42 \
		sendfax:${PORTSDIR}/comms/hylafax \
		gs:${PORTSDIR}/print/ghostscript4 \
		gv:${PORTSDIR}/print/gv

MAN1=		tkhylafax.1

.include <bsd.port.mk>
