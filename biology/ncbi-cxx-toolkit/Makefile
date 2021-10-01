PORTNAME=	ncbi-cxx-toolkit
DISTVERSION=	25_2_0
CATEGORIES=	biology science devel
MASTER_SITES=	ftp://ftp.ncbi.nih.gov/toolbox/ncbi_tools++/2021/Sep_30_2021/
DISTNAME=	ncbi_cxx--${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NCBI C++ Toolkit

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/doc/public/LICENSE

LIB_DEPENDS=	libcdd.so:math/cddlib \
		liblmdb.so:databases/lmdb \
		libpcre.so:devel/pcre
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++14-lang gmake mysql perl5 python shebangfix ssl xorg
USE_XORG=	x11 xpm

SHEBANG_FILES=	src/app/blast/get_species_taxids.sh
SHEBANG_GLOB=	*.pl *.py

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-debug --with-dll --without-static \
		--without-vdb

post-install:
	# strip
	@${FIND} ${STAGEDIR}${PREFIX}/bin -type f | ${GREP} -v -E '\.(sh|py|pl)$$' | ${XARGS} ${STRIP_CMD}
	@${FIND} ${STAGEDIR}${PREFIX}/lib -name "*.so" | ${XARGS} ${STRIP_CMD}
	# remove an empty directory
	#@${RMDIR} ${STAGEDIR}${PREFIX}/include/ncbi-tools++/objtools/data_loaders/genbank/psg
	@${RMDIR} \
		${STAGEDIR}${PREFIX}/include/ncbi-tools++/algo/ms/formats \
		${STAGEDIR}${PREFIX}/include/ncbi-tools++/algo/ms
	# remove the conflicting file
	@${RM} \
		${STAGEDIR}${PREFIX}/lib/libcdd.so \
		${STAGEDIR}${PREFIX}/lib/liblmdb.so
	# autoplist: thousands of files
	@cd ${STAGEDIR}${PREFIX} && \
		${RMDIR} include/ncbi-tools++/algo/blast/bl2api include/ncbi-tools++/objtools/test && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
