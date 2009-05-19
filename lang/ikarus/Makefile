# New ports collection makefile for:	ikarus
# Date created:		30 January 2009
# Whom:			Vitaly Magerya <vmagerya@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ikarus
PORTVERSION=	0.0.3
PORTREVISION=	2
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.ikarus-scheme.org/ \
		LOCAL/glarkin

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Optimizing incremental native-code compiler for R6RS Scheme

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=\
		CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

ONLY_FOR_ARCHS=	i386
NO_PACKAGE=	Pointyhat cluster CPUs do not support required SSE instruction set

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile.in \
		${FILESDIR}/extra-patch-doc__Makefile.in
.endif

.if ${OSVERSION} < 700042
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
