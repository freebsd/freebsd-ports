# $FreeBSD$

PORTNAME=		vcflib
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.0-rc1-130
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g7e3d806
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files

LICENSE=	MIT

BROKEN_aarch64=		fails to compile: mmintrin.h:47:5: use of undeclared identifier '__builtin_ia32_emms'; did you mean '__builtin_isless'?

LIB_DEPENDS=	libhts.so:biology/htslib \
		libtabix.so:biology/tabixpp \
		libsw.so:biology/smithwaterman
COMMON_DEPENDS=	fastahack:biology/fastahack \
		filevercmp:sysutils/filevercmp \
		fsom:science/fsom \
		multichoose>=1.0.3:math/multichoose \
		interval_tree_test:math/intervaltree
BUILD_DEPENDS=	${COMMON_DEPENDS}
RUN_DEPENDS=	${COMMON_DEPENDS}

USES=		gmake shebangfix
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ekg

CXXFLAGS+=	-I${LOCALBASE}/include/smithwaterman \
		-I${LOCALBASE}/include/multichoose \
		-I${LOCALBASE}/include/filevercmp \
		-I${LOCALBASE}/include/fastahack \
		-I${LOCALBASE}/include/intervaltree \
		-DVERSION='\"${PORTVERSION}\"'

# Clang and GCC disable sse2 by default on i386, but it's required for vcflib
CFLAGS_i386=	-msse2

MAKEFILE=	${FILESDIR}/Makefile.external-libs
INSTALL_TARGET=	install-strip

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libvcflib.so.1 \
		${STAGEDIR}${PREFIX}/lib/libvcflib.so

.include <bsd.port.mk>
