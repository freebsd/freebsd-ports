PORTNAME=	ncbi-blast+
DISTVERSION=	2.17.0
CATEGORIES=	biology perl5 python
MASTER_SITES=	https://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/ \
		https://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/${PORTVERSION}/
DISTNAME=	ncbi-blast-${PORTVERSION}+-src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI implementation of Basic Local Alignment Search Tool
WWW=		https://blast.ncbi.nlm.nih.gov/

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/scripts/projects/blast/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	Requires 64-bit processor

BUILD_DEPENDS=	grpc>0:devel/grpc
LIB_DEPENDS=	libdw.so:devel/elfutils \
		liblmdb.so:databases/lmdb \
		liblzo2.so:archivers/lzo2 \
		libnghttp2.so:www/libnghttp2 \
		libpcre2-8.so:devel/pcre2 \
		libsqlite3.so:databases/sqlite3 \
		libuv.so:devel/libuv \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-JSON>=0:converters/p5-JSON

USES=		compiler:c++14-lang gmake localbase:ldflags perl5 python shebangfix
USE_LDCONFIG=	${PREFIX}/lib/ncbi-tools++

SHEBANG_FILES=	src/app/blast/cleanup-blastdb-volumes.py \
		src/app/blast/get_species_taxids.sh \
		src/app/blast/legacy_blast.pl \
		src/app/blast/update_blastdb.pl \
		src/app/winmasker/windowmasker_2.2.22_adapter.py
GNU_CONFIGURE=	yes

# configure chooses /usr/local/bin/ar with no flags
# FreeBSD boost port flagged by configure as untested version
# --libdir=${PREFIX}/lib/ncbi-tools++ doesn't respect DESTDIR, so do
# a postinstall mv.
CONFIGURE_ARGS=	AR="ar cr" --without-boost --libdir=${PREFIX}/lib/ncbi-tools++

CONFLICTS_INSTALL=	ncbi-cxx-toolkit

WRKSRC_SUBDIR=	c++

.if !exists(/usr/include/omp.h)
CONFIGURE_ARGS+=	--without-openmp
.endif

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
# In case of problems: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=220822
LDFLAGS+=	-latomic # Only exists in gcc libs
.endif

# Build system attempts to access NCBI file server paths such as
# /net/snowman in many places.  :-/
# This causes NFS timeouts if autofs is enabled.
pre-configure:
	${REINPLACE_CMD} -e 's|/net/|/nonexistent/net/|g' \
	      ${WRKSRC}/include/sra/readers/ncbi_traces_path.hpp \
	      ${WRKSRC}/scripts/common/impl/create_flat_makefile.sh \
	      ${WRKSRC}/src/objects/genomecoll/gc_cli/Makefile.in \
	      ${WRKSRC}/src/objtools/blast/seqdb_reader/configuration.txt \
	      ${WRKSRC}/src/objtools/align_format/unit_test/data/large_gi.asn \
	      ${WRKSRC}/src/build-system/project_tree_builder.ini \
	      ${WRKSRC}/src/build-system/cmake/CMake.NCBIptb.datatool.cmake \
	      ${WRKSRC}/src/build-system/new_module.sh.in \
	      ${WRKSRC}/src/build-system/Makefile.meta_l \
	      ${WRKSRC}/src/build-system/config.site.ncbi

post-install:
	${RM} ${STAGEDIR}${PREFIX}/include/ncbi-tools++/*/*/.cvsignore.extra
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/X11
	${RM} ${STAGEDIR}${PREFIX}/include/ncbi-tools++/common/config/ncbiconf_msvc_site.h.in
	${RM} ${STAGEDIR}${PREFIX}/include/ncbi-tools++/common/ncbi_build_ver.h.in
	${RM} ${STAGEDIR}${PREFIX}/include/ncbi-tools++/common/ncbi_revision.h.in
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/debug
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ncbi-tools++/*.so

.include <bsd.port.post.mk>
