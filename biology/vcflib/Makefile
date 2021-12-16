PORTNAME=		vcflib
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.2
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files

LICENSE=	MIT

LIB_DEPENDS=	libhts.so:biology/htslib \
		libtabix.so:biology/tabixpp

USES=		cmake localbase:ldflags pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ekg
GH_TUPLE=	ekg:smithwaterman:2610e25:smithwaterman/smithwaterman \
		ekg:multichoose:68733cd:multichoose/multichoose \
		ekg:fastahack:bb33265:fastahack/fastahack \
		ekg:intervaltree:17ddd57:intervaltree/intervaltree \
		ekg:fsom:a6ef318:fsom/fsom \
		ekg:filevercmp:1a9b779:filevercmp/filevercmp \
		google:googletest:d225acc:googletest/googletest \
		edawson:libVCFH:615a06b:libVCFH/libVCFH \
		simd-everywhere:simde-no-tests:2931676:simd/src/simde

# Clang and GCC disable sse2 by default on i386, but it's required for vcflib
CFLAGS_i386=	-msse2

.include <bsd.port.mk>
