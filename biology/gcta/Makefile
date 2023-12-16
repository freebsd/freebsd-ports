PORTNAME=	gcta
DISTVERSIONPREFIX=	v
DISTVERSION=	1.94.1
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Genome-wide Complex Trait Analysis
WWW=		https://cnsgenomics.com/software/gcta/index.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		spectra>0:math/spectra
LIB_DEPENDS=	libgsl.so:math/gsl \
		libopenblas.so:math/openblas \
		libsqlite3.so:databases/sqlite3 \
		libzstd.so:archivers/zstd

USES=		cmake eigen:3 localbase:ldflags
USE_GITHUB=	yes

GH_ACCOUNT=	jianyangqt
GH_TUPLE=	zhilizheng:plink-ng:3744540:plink/submods/plink-ng

CONFIGURE_ENV+=	EIGEN3_INCLUDE_DIR=${LOCALBASE}/include/eigen3 \
		BOOST_INCLUDE_DIR=${LOCALBASE}/include/boost \
		OPENBLAS=${LOCALBASE} \
		SPECTRA_INCLUDE_DIR=${LOCALBASE}/include/Spectra

LDFLAGS+=	-fopenmp

PLIST_FILES=	bin/gcta64 bin/gcta

.include <bsd.port.pre.mk>

# Temporary hack for clang build errors:
# /usr/ports/biology/gcta/work/gcta-1.94.1/submods/plink-ng/2.0/plink2_base.h:1008:23: error: argument to '__builtin_neon_vshrq_n_v' must be a constant integer
# return R_CAST(VecW, _mm_srli_epi64(R_CAST(__m128i, vv), ct));
# /usr/lib/clang/14.0.5/include/arm_neon.h:25260:24: note: expanded from macro 'vshrq_n_u64'
# __ret = (uint64x2_t) __builtin_neon_vshrq_n_v((int8x16_t)__s0, __p1, 51);
.if ${ARCH} == aarch64
USE_GCC=	yes
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gcta64 ${STAGEDIR}${PREFIX}/bin
	${RLN} ${STAGEDIR}${PREFIX}/bin/gcta64 ${STAGEDIR}${PREFIX}/bin/gcta

.include <bsd.port.post.mk>
