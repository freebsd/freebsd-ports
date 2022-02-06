PORTNAME=		freebayes
DISTVERSIONPREFIX=	v
DISTVERSION=		1.3.6
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bayesian haplotype-based polymorphism discovery and genotyping

LICENSE=	MIT

LIB_DEPENDS=	libhts.so:biology/htslib \
		libtabix.so:biology/tabixpp

# Submodules use older versions than the ports, so we cannot safely unbundle
# No shared libs are built by the submodules so there will be no conflicts
# Yes, there are actually 2 versions of intervaltree required
USES=		compiler:c++14-lang localbase meson perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TUPLE=	ekg:intervaltree:b90527f:intervaltree/vcflib/intervaltree \
		ekg:vcflib:d4073c3:vcflib/vcflib-temp \
		ekg:fastahack:bb33265:fastahack/vcflib/fastahack \
		ekg:filevercmp:1a9b779:filevercmp/vcflib/filevercmp \
		ekg:fsom:a6ef318:fsom/vcflib/fsom \
		google:googletest:d225acc:googletest/vcflib/googletest \
		ekg:intervaltree:17ddd57:intervaltree/vcflib/intervaltree \
		edawson:libVCFH:615a06b:libVCFH/vcflib/libVCFH \
		ekg:multichoose:68733cd:multichoose/vcflib/multichoose \
		ekg:smithwaterman:2610e25:smithwaterman/vcflib/smithwaterman \
		ekg:tabixpp:b255df1:tabixpp/vcflib/tabixpp \
		simd-everywhere:simde-no-tests:2931676:simd/vcflib/src/simde \
		ingydotnet:test-simple-bash:124673f:testsimplebash/test/test-simple-bash \
		illusori:bash-tap:c38fbfa:bashtap/test/bash-tap
USE_PERL5=	build

LDFLAGS+=		-lexecinfo
PLIST_FILES=		bin/bamleftalign bin/freebayes

# GH_TUPLEs cannot seem to share a top-level subdirectory, so we work around
# by dumping the parent in a temp directory and then moving the contents
post-extract:
	${CP} -r ${WRKSRC}/vcflib-temp/* ${WRKSRC}/vcflib

.include <bsd.port.mk>
