# New ports collection makefile for:	c-a-i-r
# Date created:				18 Oct 2008
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	c-a-i-r
PORTVERSION=	2.16
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	CAIR_MT_v2.16

MAINTAINER=	buganini@gmail.com
COMMENT=	Content Aware Image Resizer is an implementation of seam carving

USE_ZIP=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/cair

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
EXTRA_PATCHES=	${PATCHDIR}/amd64-CAIR.cpp
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cair ${PREFIX}/bin

.include <bsd.port.post.mk>
