# New ports collection makefile for:   ivtools
# Date created:        13 March 2002
# Whom:                scott
#
# $FreeBSD$
#

PORTNAME=	ivtools
PORTVERSION=	1.2.1
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drawing editors derived from idraw

BUILD_DEPENDS=	imake:${X_IMAKE_PORT}

USE_XLIB=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
INSTALLS_SHLIB=	yes

MANCOMPRESSED=	no
MAN1=	idraw.1 iclass.1 drawtool.1 comterp.1 comdraw.1 flipbook.1 graphdraw.1

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"fails to configure on ${ARCH}"
.endif

.include <bsd.port.post.mk>
