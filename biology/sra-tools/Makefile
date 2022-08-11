PORTNAME=	sra-tools
DISTVERSION=	2.11.0
PORTREVISION=	3
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI's toolkit for handling data in INSDC Sequence Read Archives

LICENSE=		PD LGPL21+
LICENSE_COMB=		multi
LICENSE_FILE_PD=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_LGPL21+ =

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	NCBI-VDB requires SSE2 instructions, no 32-bit support

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/lib/libngs-c++.a:biology/ngs-sdk
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5 \
		libepoll-shim.so:devel/libepoll-shim

USES=		compiler:c11 gmake localbase:ldflags perl5 shebangfix
USE_PERL5=	build
USE_GITHUB=	yes

SHEBANG_GLOB=	*.sh *.pl
GH_ACCOUNT=	ncbi
GH_TUPLE+=	ncbi:ngs:${DISTVERSION}:ngs/ngs # ported as biology/ngs-sdk
GH_TUPLE+=	ncbi:ncbi-vdb:${DISTVERSION}:vdb/ncbi-vdb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ngs-sdk-prefix=${LOCALBASE} \
		--with-ncbi-vdb-sources=${NCBI_VDB_WRKSRC} \
		--with-xml2-prefix=${LOCALBASE} \
		--with-hdf5-prefix=${LOCALBASE} \
		CC="${CC}" CXX="${CXX}" TOOLS="${CHOSEN_COMPILER_TYPE}" \
		--with-ncbi-vdb-build=${NCBI_VDB_WRKSRC}/amd64-portbld-freebsd$$(${FREEBSD_RELEASE})
MAKE_ARGS=	CCNAME=${CC} CXXNAME=${CXX} PKGCFLAGS="${CFLAGS}" \
		INST_ETCDIR=${STAGEDIR}${PREFIX}/etc

NCBI_VDB_WRKSRC=	${WRKSRC}/ncbi-vdb
NCBI_VDB_FILESDIR=	${FILESDIR}
FREEBSD_RELEASE=	uname -r | cut -d - -f 1

CFLAGS+=	-I${WRKSRC}/interfaces/os/sun
CXXFLAGS+=	-I${WRKSRC}/interfaces/os/sun

CONFLICTS_INSTALL=	kget

BINARY_ALIAS=	gcc=${CC} g++=${CXX}

# for port developers, building with these options may fail
OPTIONS_DEFINE=		DEBUG OPTIMIZED_CFLAGS TEST
DEBUG_PREVENTS=		OPTIMIZED_CFLAGS
DEBUG_CONFIGURE_WITH=	debug
OPTIMIZED_CFLAGS_MAKE_ARGS_OFF=	OPT=""
TEST_TEST_TARGET=	test
TEST_USES=		python

# ncbi-vdb build extras
VDB_CONFIGURE_ARGS=	\
		--with-xml2-prefix=${LOCALBASE} \
		--with-hdf5-prefix=${LOCALBASE} \
		--prefix=${PREFIX} \
		--build=amd64-portbld-freebsd$$(${FREEBSD_RELEASE}) \
		CC="${CC}" CXX="${CXX}" TOOLS="${CHOSEN_COMPILER_TYPE}"
VDB_MAKE_ARGS+=	-j 1 CCNAME=${CC} CXXNAME=${CXX} PKGCFLAGS="${CFLAGS}"
MAKE_ENV+=	CPATH="${LOCALBASE}/include/libepoll-shim"
CFLAGS+=	-I${WRKSRC}/lib

pre-patch:
	@${CP} ${FILESDIR}/Makefile.bsd ${NCBI_VDB_WRKSRC}/build/
	@${CP} ${FILESDIR}/ld.bsd.*.sh ${NCBI_VDB_WRKSRC}/build/
	@${MKDIR} ${NCBI_VDB_WRKSRC}/interfaces/os/bsd
	@${CP} -p ${NCBI_VDB_WRKSRC}/interfaces/os/mac/endian.h \
		${NCBI_VDB_WRKSRC}/interfaces/os/bsd/

post-patch:
	@${GREP} -q '@@PREFIX@@' ${WRKSRC}/ncbi-vdb/libs/kfg/config.c || (echo "@@PREFIX@@ in file/patch-libs_kfg_config.c is overwritten probably due to using 'make makepatch'"; exit 1)
	@${REINPLACE_CMD} -e 's#@@PREFIX@@#"${PREFIX}"#' ${WRKSRC}/ncbi-vdb/libs/kfg/config.c
	@${LN} -s ${WRKSRC}/ncbi-vdb/interfaces/cc/gcc/x86_64 ${WRKSRC}/ncbi-vdb/interfaces/cc/gcc/amd64

post-patch-TEST-on:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|' ${WRKSRC}/test/kget/Makefile

pre-configure:
	@${CP} ${NCBI_VDB_WRKSRC}/setup/os-arch.prl ${WRKSRC}/setup/os-arch.prl
	# same as in biology/ncbi-vdb
	@${CP} ${NCBI_VDB_FILESDIR}/Makefile.bsd ${WRKSRC}/build/
	@${CP} ${NCBI_VDB_WRKSRC}/build/ld.bsd.*.sh ${WRKSRC}/build/
	@${MKDIR} ${WRKSRC}/interfaces/override
	@${CP} ${NCBI_VDB_WRKSRC}/interfaces/os/sun/atomic32.h ${WRKSRC}/interfaces/override
	@${CP} ${FILESDIR}/byteswap.h ${WRKSRC}/interfaces/override
	@cd ${WRKSRC}/ncbi-vdb && ./configure ${VDB_CONFIGURE_ARGS}
	@${ECHO} ${CHOSEN_COMPILER_TYPE} > ${WRKSRC}/ncbi-vdb/build/COMP
	@cd ${WRKSRC}/ncbi-vdb && ${DO_MAKE_BUILD} ${VDB_MAKE_ARGS}

post-build-TEST-on:	do-test

do-install:
	cd ${WRKSRC}/amd64-portbld-freebsd*/sra-tools/bsd/clang/*/rel/bin && \
	    for f in `ls *.${PORTVERSION}`; do \
		${INSTALL_PROGRAM} $${f} \
		${STAGEDIR}${PREFIX}/bin/`basename $${f%%.${PORTVERSION}}`; \
	done

.include <bsd.port.mk>
