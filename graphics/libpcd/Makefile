# New ports collection makefile for:	libpcd
# Date created:		2004-08-23
# Whom:			Andrey Slusar <anray@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libpcd
PORTVERSION=	1.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://dl.bytesex.org/releases/libpcd/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	anray@FreeBSD.org
COMMENT=	A library for reading PhotoCD images

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
MAKEFILE=	${WRKSRC}/GNUmakefile

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
post-patch:
	@${REINPLACE_CMD} -e 's/uint_fast16_t/uint32_t/' ${WRKSRC}/yuv2rgb.c
.endif

.include <bsd.port.post.mk>
