# New ports collection makefile for:   ivtools
# Date created:        13 March 2002
# Whom:                scott
#
# $FreeBSD$
#

PORTNAME=	ivtools
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	johnston@vectaport.com
COMMENT=	Drawing editors derived from idraw

.include <bsd.port.pre.mk>

.if ${ARCH} == alpha || ${ARCH} == sparc64
BROKEN=		"fails to configure on ${ARCH}"
.endif
.if ${ARCH} == i386 && ${OSVERSION} > 500000
BROKEN=		"fails to configure on ${ARCH} with FreeBSD version ${OSVERSION}"
.endif

.if ${XFREE86_VERSION} == 3
BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake
.else
BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4
.endif

USE_XLIB=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

MANCOMPRESSED=	no
MAN1=	idraw.1 iclass.1 drawtool.1 comterp.1 comdraw.1 flipbook.1 graphdraw.1

.include <bsd.port.post.mk>
