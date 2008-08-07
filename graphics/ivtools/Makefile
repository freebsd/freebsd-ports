# New ports collection makefile for:   ivtools
# Date created:        13 March 2002
# Whom:                scott
#
# $FreeBSD$
#

PORTNAME=	ivtools
PORTVERSION=	1.2.6
CATEGORIES=	graphics
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Drawing editors derived from idraw

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:261
CONFIGURE_ARGS=	--with-tiff=${PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
USE_LDCONFIG=	yes
MAKE_ARGS=	ARCH=FREEBSD
USE_XORG=	x11 xaw ice xext

MANCOMPRESSED=	no
MAN1=	idraw.1 iclass.1 drawtool.1 comterp.1 comdraw.1 flipbook.1 graphdraw.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
BROKEN=		Incomplete pkg-plist
.endif

.if ${OSVERSION} >= 600000 && ${OSVERSION} < 700000
PLIST_SUB+=	IVDL="@comment"
.endif

.include <bsd.port.post.mk>
