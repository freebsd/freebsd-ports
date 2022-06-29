PORTNAME=	ncbi-blast+
DISTVERSION=	2.12.0
PORTREVISION=	6
CATEGORIES=	biology perl5 python
MASTER_SITES=	https://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/LATEST/ \
		https://ftp.ncbi.nlm.nih.gov/blast/executables/blast+/${PORTVERSION}/
DISTNAME=	ncbi-blast-${PORTVERSION}+-src

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI implementation of Basic Local Alignment Search Tool

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/scripts/projects/blast/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre \
		liblmdb.so:databases/lmdb \
		liblzo2.so:archivers/lzo2 \
		libgnutls.so:security/gnutls \
		libtspi.so:security/trousers \
		libgmp.so:math/gmp \
		libidn2.so:dns/libidn2 \
		libnettle.so:security/nettle \
		libhogweed.so:security/nettle \
		libtasn1.so:security/libtasn1 \
		libp11-kit.so:security/p11-kit \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libsqlite3.so:databases/sqlite3 \
		libuv.so:devel/libuv \
		libnghttp2.so:www/libnghttp2 \
		libgrpc.so:devel/grpc
RUN_DEPENDS=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-JSON>=0:converters/p5-JSON

USES=		compiler:c++14-lang gmake localbase:ldflags shebangfix perl5 python:3.6+
USE_LDCONFIG=	yes

SHEBANG_FILES=	src/app/blast/legacy_blast.pl \
		src/app/blast/update_blastdb.pl \
		src/app/blast/cleanup-blastdb-volumes.py \
		src/app/blast/get_species_taxids.sh \
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

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/include/ncbi-tools++/*/*/.cvsignore.extra
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/X11
	@${RM} ${STAGEDIR}${PREFIX}/include/ncbi-tools++/common/config/ncbiconf_msvc_site.h.in
	@${RM} ${STAGEDIR}${PREFIX}/include/ncbi-tools++/common/ncbi_build_ver.h.in
	@${RM} ${STAGEDIR}${PREFIX}/include/ncbi-tools++/common/ncbi_revision.h.in
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/debug
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ncbi-tools++/*.so

.include <bsd.port.post.mk>
