# Created by: Vitaly Magerya <vmagerya@gmail.com>
# $FreeBSD$

PORTNAME=	ikarus
PORTVERSION=	0.0.3
PORTREVISION=	3
CATEGORIES=	lang scheme
MASTER_SITES=	http://launchpad.net/ikarus/0.0/${PORTVERSION}/+download/ \
		http://www.ikarus-scheme.org/ \
		http://tx97.net/pub/distfiles/ \
		LOCAL/glarkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optimizing incremental native-code compiler for R6RS Scheme

DEPRECATED=	Upstream project died in 2009
EXPIRATION_DATE=2014-07-20

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

# Both install bin/scheme-script
CONFLICTS=	petite-chez-*

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=\
		CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

ONLY_FOR_ARCHS=	i386
.if defined(PACKAGE_BUILDING)
NO_PACKAGE=	Pointyhat cluster CPUs do not support required SSE instruction set
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile.in \
		${FILESDIR}/extra-patch-doc__Makefile.in
.endif

.include <bsd.port.post.mk>
