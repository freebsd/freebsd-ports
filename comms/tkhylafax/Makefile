# New ports collection Makefile for:	tkhylafax
# Date created:		Sun Jun  8 11:51:21 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	tkhylafax
PORTVERSION=	3.0b2
CATEGORIES=	comms tk82
MASTER_SITES=	http://www.NeoSoft.com/tcl/ftparchive/sorted/comm/tkhylafax-3.0b2/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A tcl/tk interface to Sam Leffler's fax package

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82 \
		sendfax:${PORTSDIR}/comms/hylafax \
		gs:${PORTSDIR}/print/ghostscript-gnu \
		gv:${PORTSDIR}/print/gv

WRKSRC=		${WRKDIR}/tkhylafax-3.0
MAN1=		tkhylafax.1

.include <bsd.port.mk>
