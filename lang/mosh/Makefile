# Created by: Katsuji ISHIKAWA <katsuji.ishikawa@gmail.com>
# $FreeBSD$

PORTNAME=	mosh
PORTVERSION=	0.2.7
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	mosh-scheme
PKGNAMESUFFIX=	-scheme

MAINTAINER=	mjt@cltn.org
COMMENT=	Fast R6RS Scheme interpreter

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libonig.so:devel/oniguruma5

CONFLICTS_INSTALL=	mosh-1.[0-9].*

USES=		gmake
USE_OPENSSL=	yes
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
