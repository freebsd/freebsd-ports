# New ports collection makefile for:   ivtools
# Date created:        13 March 2002
# Whom:                scott
#
# $FreeBSD$
#

PORTNAME=	ivtools
PORTVERSION=	1.2.6
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Drawing editors derived from idraw

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262
CONFIGURE_ARGS=	--with-tiff=${PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
MAKE_ARGS=	ARCH=FREEBSD
USE_XORG=	x11 xaw ice xext

MANCOMPRESSED=	no
MAN1=	idraw.1 iclass.1 drawtool.1 comterp.1 comdraw.1 flipbook.1 graphdraw.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		incomplete pkg-plist
.endif

.if ${OSVERSION} <= 604100
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
