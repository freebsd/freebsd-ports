PORTNAME=	ncbi-cxx-toolkit
DISTVERSIONPREFIX=	release-
DISTVERSION=	26.0.1
CATEGORIES=	biology science devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NCBI C++ Toolkit

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/doc/public/LICENSE

LIB_DEPENDS=	libcdd.so:math/cddlib \
		liblmdb.so:databases/lmdb \
		libpcre.so:devel/pcre
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
