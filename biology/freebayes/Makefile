PORTNAME=		freebayes
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.5
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

# These should be rechecked: Same error resolved on aarch64 in 1.3.5 update.
BROKEN_armv6=		fails to compile: invalid conversion between vector type and integer type

LIB_DEPENDS=	libhts.so:biology/htslib \
		libtabix.so:biology/tabixpp

# Submodules use older versions than the ports, so we cannot safely unbundle
# No shared libs are built by the submodules so there will be no conflicts
USES=		compiler:c++14-lang localbase meson perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TUPLE=	ekg:vcflib:d4073c3:vcflib/vcflib-temp \
		ekg:smithwaterman:2610e25:smithwaterman/vcflib/smithwaterman \
		ekg:multichoose:68733cd:multichoose/vcflib/multichoose \
		ekg:fastahack:bb33265:fastahack/vcflib/fastahack \
		ekg:intervaltree:17ddd57:intervaltree/vcflib/intervaltree \
		ekg:fsom:a6ef318:fsom/vcflib/fsom \
		ekg:filevercmp:1a9b779:filevercmp/vcflib/filevercmp \
		google:googletest:d225acc:googletest/vcflib/googletest \
		edawson:libVCFH:615a06b:libVCFH/vcflib/libVCFH \
		simd-everywhere:simde-no-tests:2931676:simd/vcflib/src/simde \
		ekg:intervaltree:b90527f:intervaltree2/intervaltree \
		ekg:tabixpp:b255df1:tabixpp/vcflib/tabixpp \
		ingydotnet:test-simple-bash:124673f:testsimplebash/test/test-simple-bash \
		illusori:bash-tap:c38fbfa:bashtap/test/bash-tap \
		samtools:htslib:b581944:htslib/contrib/htslib
USE_PERL5=	build

LDFLAGS+=		-lexecinfo
PLIST_FILES=		bin/bamleftalign bin/freebayes

# GH_TUPLEs cannot seem to share a top-level subdirectory, so we work around
# by dumping the parent in a temp directory and then moving the contents
post-extract:
	${CP} -r ${WRKSRC}/vcflib-temp/* ${WRKSRC}/vcflib

.include <bsd.port.mk>
