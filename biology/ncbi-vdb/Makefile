PORTNAME=	ncbi-vdb
DISTVERSION=	2.11.0
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	mzaki@niid.go.jp
COMMENT=	NCBI's virtualized back-end for accessing Sequence Read Archive

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	libs/search/nucstrstr.c requires SSE2 instructions

BUILD_DEPENDS=	bash:shells/bash \
		libepoll-shim>0:devel/libepoll-shim

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5 \
		libmbedtls.so:security/mbedtls

USES=		compiler:c11 gmake localbase:ldflags perl5 shebangfix
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi
GH_TUPLE+=	ncbi:ngs:${DISTVERSION}:ngs # ported as biology/ngs-sdk

SHEBANG_GLOB=	*.sh *.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xml2-prefix=${LOCALBASE} \
		--with-hdf5-prefix=${LOCALBASE} \
		--with-mbedtls-prefix=${LOCALBASE} \
		CC="${CC}" CXX="${CXX}" TOOLS="${CHOSEN_COMPILER_TYPE}"
MAKE_ENV+=	CPATH="${LOCALBASE}/include/libepoll-shim"
MAKE_ARGS+=	CCNAME=${CC} CXXNAME=${CXX} PKGCFLAGS="${CFLAGS}"

CFLAGS+=	-I${WRKSRC}/lib

MAKE_JOBS_UNSAFE=	yes

post-extract:
	@${LN} -sf ${WRKSRC_ngs} ${WRKDIR}/ngs
	@${LN} -sf ${WRKSRC} ${WRKDIR}/${PORTNAME}

pre-patch:
	@${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}/build/
	@for f in ${WRKSRC}/build/ld.linux.*.sh; do ${CP} -p $${f} $${f%linux*}bsd$${f#*linux}; done
	@${CP} -p ${WRKSRC}/build/ld.linux.gcc.sh ${WRKSRC}/build/ld.bsd.clang.sh
	@${MKDIR} ${WRKSRC}/interfaces/os/bsd
	@${CP} -p ${WRKSRC}/interfaces/os/mac/endian.h ${WRKSRC}/interfaces/os/bsd/

post-patch:
	@${GREP} -q '@@PREFIX@@' ${WRKSRC}/libs/kfg/config.c || (echo "@@PREFIX@@ in file/patch-libs_kfg_config.c is overwritten probably due to using 'make makepatch'"; exit 1)
	@${REINPLACE_CMD} -e 's#@@PREFIX@@#"${PREFIX}"#' ${WRKSRC}/libs/kfg/config.c

post-configure:
	@${ECHO} ${CHOSEN_COMPILER_TYPE} > ${WRKSRC}/build/COMP

# The 'install' target installs broken-looking static libs with symlinks.
# This is intentional, see comments https://github.com/ncbi/ncbi-vdb/issues/36#issuecomment-817990790 This may change in future versions.

.include <bsd.port.mk>
