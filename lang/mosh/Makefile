# Created by: Katsuji ISHIKAWA <katsuji.ishikawa@gmail.com>
# $FreeBSD$

PORTNAME=	mosh
PORTVERSION=	0.2.7
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/mosh-scheme/
PKGNAMESUFFIX=	-scheme

MAINTAINER=	mjt@cltn.org
COMMENT=	Fast R6RS Scheme interpreter

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libonig.so:devel/oniguruma

BROKEN_armv6=		fails to link: os_dep.c: undefined reference to '__stack_base__'
BROKEN_armv7=		fails to link: os_dep.c: undefined reference to '__stack_base__'
BROKEN_mips64=		fails to compile: os_dep.c: redefinition of 'GC_register_dynamic_libraries'
NOT_FOR_ARCHS=		aarch64
NOT_FOR_ARCHS_REASON=	gcconfig.h: the collector has not been ported to this machine/OS combination

CONFLICTS_INSTALL=	mosh-1.[0-9].*

USES=		gmake ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/lib

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if ${MACHINE_CPU:Msse3}
CONFIGURE_ENV+=	MOSH_OPTS="-msse3 -mfpmath=sse"
.elif ${MACHINE_CPU:Msse2}
CONFIGURE_ENV+=	MOSH_OPTS="-msse2 -mfpmath=sse"
.elif ${MACHINE_CPU:Msse}
CONFIGURE_ENV+=	MOSH_OPTS="-msse -mfpmath=sse"
.elif ${MACHINE_CPU:Mmmx}
CONFIGURE_ENV+=	MOSH_OPTS="-mmmx"
.endif

x-generate-plist: stage
	@(${FIND} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/man -name \
		'*mosh*' ; ${FIND} ${STAGEDIR}${PREFIX}/lib/mosh -type f) \
		| ${SORT} | ${SED} -e 's,^${STAGEDIR}${PREFIX}/,,' \
		> pkg-plist.new

.include <bsd.port.mk>
