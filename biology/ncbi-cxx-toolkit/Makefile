PORTNAME=	ncbi-cxx-toolkit
DISTVERSIONPREFIX=	release-
DISTVERSION=	28.0.7
CATEGORIES=	biology science devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NCBI C++ Toolkit
WWW=		https://ncbi.github.io/cxx-toolkit/

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/doc/public/LICENSE

BROKEN_armv6=	platform not defined for FreeBSD arm, see https://github.com/ncbi/ncbi-cxx-toolkit-public/issues/2
BROKEN_armv7=	link fails due to a missing function, see https://github.com/ncbi/ncbi-cxx-toolkit-public/issues/8

LIB_DEPENDS=	libbz2.so:archivers/bzip2 \
		libcdd.so:math/cddlib \
		liblmdb.so:databases/lmdb \
		libpcre.so:devel/pcre \
		libunwind.so:devel/libunwind \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++17-lang gmake mysql perl5 python shebangfix ssl xorg
USE_XORG=	x11 xpm

USE_GITHUB=	yes
GH_ACCOUNT=	ncbi
GH_PROJECT=	${PORTNAME}-public

SHEBANG_FILES=	src/app/blast/get_species_taxids.sh
SHEBANG_GLOB=	*.pl *.py

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-debug --with-dll --without-static \
		--without-vdb

CONFLICTS_INSTALL=	dakota libxdiff ncbi-blast+ ncbi-toolkit proj \
			py*-speedtest-cli # bin/blast_formatter bin/speedtest bin/test_regexp lib/libeutils.so lib/libproj.so lib/libxdiff.so

post-install:
	# strip
	@${FIND} ${STAGEDIR}${PREFIX}/bin -type f | ${GREP} -v -E '\.(sh|py|pl)$$' | ${XARGS} ${STRIP_CMD}
	@${FIND} ${STAGEDIR}${PREFIX}/lib -name "*.so" | ${XARGS} ${STRIP_CMD}
	# remove the conflicting files
	@${RM} \
		${STAGEDIR}${PREFIX}/lib/libcdd.so \
		${STAGEDIR}${PREFIX}/lib/liblmdb.so
	# autoplist: thousands of files
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
