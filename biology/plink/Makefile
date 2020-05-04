# $FreeBSD$

PORTNAME=		plink
DISTVERSIONPREFIX=	v
DISTVERSION=		1.90b6.17
CATEGORIES=		biology

MAINTAINER=	mzaki@e-mail.ne.jp
COMMENT=	Whole genome association analysis toolset

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		aarch64 mips64 powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	64bit code requires SSE2 instructions

USES=		gmake fortran

USE_GITHUB=	yes
GH_ACCOUNT=	chrchang
GH_PROJECT=	plink-ng
GH_TAGNAME=	79b2df8c

WRKSRC_SUBDIR=	1.9
MAKEFILE=	Makefile.std
MAKE_ARGS=	ZLIB=-lz BLASFLAGS="${BLASLIB} ${LAPACKLIB}"
CFLAGS+=	-DDYNAMIC_ZLIB -I${LOCALBASE}/include
LDFLAGS+=	-lthr
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_SINGLE=		BLAS
OPTIONS_SINGLE_BLAS=	NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS

BLAS_DESC=	BLAS/LAPACK implementation

OPENBLAS_USES=	blaslapack:openblas

NETLIB_DESC=		Netlib's reference
NETLIB_USES=		blaslapack:netlib
NETLIB_LIB_DEPENDS=	libcblas.so:math/cblas
NETLIB_LDFLAGS=		-lcblas

EXAMPLES=	toy.map toy.ped

post-build:
	(cd ${WRKSRC}; ${CC} ${CFLAGS} prettify.c -o prettify)

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/prettify ${STAGEDIR}${PREFIX}/bin

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
