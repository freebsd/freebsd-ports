# $FreeBSD$

PORTNAME=		freebayes
DISTVERSIONPREFIX=	v
DISTVERSION=		1.2.0
PORTREVISION=	1
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

BROKEN_aarch64=		fails to compile: invalid conversion between vector type and integer type
BROKEN_armv6=		fails to compile: invalid conversion between vector type and integer type
BROKEN_armv7=		fails to compile: invalid conversion between vector type and integer type

# Submodules use older versions than the ports, so we cannot safely unbundle
# No shared libs are built by the submodules so there will be no conflicts
USES=		compiler:c++11-lang gmake tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TUPLE=	walaj:SeqLib:5941c68:SeqLib/SeqLib-temp \
		jwalabroad:bwa:c02766e:bwa/SeqLib/bwa \
		jwalabroad:fermi-lite:5bc90f8:fermi/SeqLib/fermi-lite \
		samtools:htslib:49fdfbd:htslib/SeqLib/htslib \
		ekg:bamtools:e77a43f:bamtools/bamtools \
		ekg:intervaltree:dbb4c51:interval1/intervaltree \
		vcflib:vcflib:5e3ce04:vcflib/vcflib-temp \
		ekg:fastahack:c68cebb:fastahack/vcflib/fastahack \
		ekg:filevercmp:1a9b779:filevercmp/vcflib/filevercmp \
		ekg:fsom:a6ef318:fsom/vcflib/fsom \
		google:googletest:d225acc:google/vcflib/googletest \
		ekg:intervaltree:b704f19:interval2/vcflib/intervaltree \
		ekg:multichoose:73d35da:multichoose/vcflib/multichoose \
		ekg:smithwaterman:84c08d7:smithwaterman/vcflib/smithwaterman \
		ekg:tabixpp:80012f8:tabixpp/vcflib/tabixpp \
		samtools:htslib:0f298ce:hts2/vcflib/tabixpp/htslib

# GCC disables sse2 by default on i386, but it's required for vcflib
CXXFLAGS+=		--std=c++11
CFLAGS_i386=		-msse2
MAKE_JOBS_UNSAFE=	yes
PLIST_FILES=		bin/bamleftalign bin/freebayes

# GH_TUPLEs cannot seem to share a top-level subdirectory, so we work around
# by dumping the parent in a temp directory and then moving the contents
post-extract:
	${MV} -n ${WRKSRC}/SeqLib-temp/* ${WRKSRC}/SeqLib
	${MV} -n ${WRKSRC}/vcflib-temp/* ${WRKSRC}/vcflib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
