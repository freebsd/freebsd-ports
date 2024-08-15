PORTNAME=		kallisto
DISTVERSIONPREFIX=	v
DISTVERSION=		0.51.0
PORTEPOCH=		1
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Quantify abundances of transcripts from RNA-Seq data
WWW=		https://pachterlab.github.io/kallisto/about.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le riscv64
ONLY_FOR_ARCHS_REASON=	Requires a 64-bit processor

LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsz.so:science/libaec \
		libhts.so:biology/htslib

USES=		cmake:noninja compiler:c++11-lang gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	pachterlab

EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/ext/htslib --no-same-owner --no-same-permissions

SUB_FILES=	kallisto-test

PORTEXAMPLES=		*
PLIST_FILES=		bin/kallisto
EXAMPLES_PLIST_FILES=	bin/kallisto-test

# hdf5 is being phased out and is no longer built in by default, but is still
# required for Sleuth (requires kallisto bootstrap estimates) and other
# downstream tools.  Remove this after Sleuth et al catch up.
CMAKE_ARGS+=		-DUSE_HDF5:BOOL=ON -DUSE_BAM:BOOL=ON
# WIP: Remove before committing
CMAKE_ARGS+=		-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON
MAKE_JOBS_UNSAFE=	yes
LDFLAGS+=		-lhts -lz

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${INSTALL_SCRIPT} ${WRKDIR}/kallisto-test ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/test && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
