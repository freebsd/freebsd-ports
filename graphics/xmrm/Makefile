# New ports collection makefile for:	xmrm
# Date created:		Sa  01 May 1999 15:00:00 MET
# Whom:			Tobias Reifenberger <treif@mayn.de>
#
# $FreeBSD$
#

PORTNAME=	xmrm
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cg.tuwien.ac.at/pub/linux/xmrm/ \
		ftp://ftp.uni-passau.de/mount/common.lib.archive.unix/Graphic/xmrm/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}_sources
EXTRACT_SUFX=	.tgz

MAINTAINER=	treif@mayn.de

RUN_DEPENDS=	mpeg:${PORTSDIR}/graphics/mpeg
LIB_DEPENDS=	forms.0:${PORTSDIR}/x11-toolkits/xforms \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_XPM=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmrm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xmrm_mpeg ${PREFIX}/bin

.include <bsd.port.mk>
