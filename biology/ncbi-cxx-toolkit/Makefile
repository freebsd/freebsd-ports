PORTNAME=	ncbi-cxx-toolkit
DISTVERSION=	22_0_0
CATEGORIES=	biology science devel
MASTER_SITES=	ftp://ftp.ncbi.nih.gov/toolbox/ncbi_tools++/2019/Mar_28_2019/
DISTNAME=	ncbi_cxx--${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NCBI C++ Toolkit

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/doc/public/LICENSE

LIB_DEPENDS=	liblmdb.so:databases/lmdb \
		libpcre.so:devel/pcre
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang gmake mysql perl5 python shebangfix ssl xorg
SHEBANG_FILES=	src/app/blast/get_species_taxids.sh src/app/blast/legacy_blast.pl src/app/blast/update_blastdb.pl src/app/winmasker/windowmasker_2.2.22_adapter.py
USE_XORG=	x11 xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-debug --with-dll --without-static

post-install:
	# strip
	@${FIND} ${STAGEDIR}${PREFIX}/bin -type f | ${GREP} -v -E '\.(sh|py|pl)$$' | ${XARGS} ${STRIP_CMD}
	@${FIND} ${STAGEDIR}${PREFIX}/lib -name "*.so" | ${XARGS} ${STRIP_CMD}
	# remove an empty directory
	@${RMDIR} ${STAGEDIR}${PREFIX}/include/ncbi-tools++/objtools/data_loaders/genbank/psg
	# remove the conflicting file
	@${RM} ${STAGEDIR}${PREFIX}/lib/liblmdb.so
	# autoplist: thousands of files
	@cd ${STAGEDIR}${PREFIX} && \
		${RMDIR} include/ncbi-tools++/algo/blast/bl2api include/ncbi-tools++/objtools/test && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
