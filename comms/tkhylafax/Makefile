# New ports collection Makefile for:	tkhylafax-3.0
# Version required:	3.0b2
# Date created:		Sun Jun  8 11:51:21 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.5 1998/02/21 22:38:07 fenner Exp $
#

DISTNAME=	tkhylafax-3.0b2
PKGNAME=	tkhylafax-3.0
CATEGORIES=	comms tk42
MASTER_SITES=	http://www.NeoSoft.com/tcl/ftparchive/sorted/comm/tkhylafax-3.0b2/

MAINTAINER=	andreas@FreeBSD.ORG

RUN_DEPENDS=	wish4.2:${PORTSDIR}/x11-toolkits/tk42 \
		sendfax:${PORTSDIR}/comms/hylafax \
		gs:${PORTSDIR}/print/ghostscript4 \
		gv:${PORTSDIR}/print/gv

WRKSRC=		${WRKDIR}/tkhylafax-3.0
MAN1=		tkhylafax.1

.include <bsd.port.mk>
