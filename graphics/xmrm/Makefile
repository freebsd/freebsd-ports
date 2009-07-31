# New ports collection makefile for:	xmrm
# Date created:		Sa  01 May 1999 15:00:00 MET
# Whom:			Tobias Reifenberger <treif@mayn.de>
#
# $FreeBSD$
#

PORTNAME=	xmrm
PORTVERSION=	2.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cg.tuwien.ac.at/pub/linux/xmrm/ \
		ftp://ftp.uni-passau.de/mount/common.lib.archive.unix/Graphic/xmrm/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}_sources
EXTRACT_SUFX=	.tgz

MAINTAINER=	treif@mayn.de
COMMENT=	An image morphing/warping program

RUN_DEPENDS=	mpeg:${PORTSDIR}/multimedia/mpeg \
		mpeg_play:${PORTSDIR}/multimedia/mpeg_play
LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GL=		yes
USE_XORG=	xpm
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on amd64 or sparc64
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmrm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xmrm_mpeg ${PREFIX}/bin

.include <bsd.port.post.mk>
