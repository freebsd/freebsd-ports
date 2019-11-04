# $FreeBSD$

PORTNAME=	ncbi-cxx-toolkit
DISTVERSION=	21_0_0
PORTREVISION=	2
CATEGORIES=	biology science devel
MASTER_SITES=	ftp://ftp.ncbi.nih.gov/toolbox/ncbi_tools++/2018/Apr_2_2018/
DISTNAME=	ncbi_cxx--${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NCBI C++ Toolkit

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/doc/public/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang gmake mysql perl5 python shebangfix ssl xorg
SHEBANG_FILES=	src/app/blast/get_species_taxids.sh src/app/blast/legacy_blast.pl src/app/blast/update_blastdb.pl src/app/winmasker/windowmasker_2.2.22_adapter.py
USE_XORG=	x11 xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-debug --with-dll --without-static

post-install: # autoplist: thousands of files
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/run_with_lock
	@cd ${STAGEDIR}${PREFIX} && \
		${RMDIR} include/ncbi-tools++/algo/blast/bl2api include/ncbi-tools++/objtools/test && \
		${FIND} * -type f -or -type l >> ${TMPPLIST}

.include <bsd.port.mk>
