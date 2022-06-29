PORTNAME=		vcflib
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.3
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files

LICENSE=	MIT

LIB_DEPENDS=	libhts.so:biology/htslib \
		libtabix.so:biology/tabixpp

USES=		cmake localbase:ldflags pkgconfig python shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	ekg
GH_TUPLE=	ekg:fastahack:bb33265:fastahack/fastahack \
		ekg:filevercmp:1a9b779:filevercmp/filevercmp \
		ekg:fsom:a6ef318:fsom/fsom \
		google:googletest:d225acc:googletest/googletest \
		ekg:intervaltree:aa59377:intervaltree/intervaltree \
		edawson:libVCFH:44b6580:libVCFH/libVCFH \
		ekg:multichoose:68733cd:multichoose/multichoose \
		ekg:smithwaterman:2610e25:smithwaterman/smithwaterman \
		simd-everywhere:simde-no-tests:9af03cd:simd/src/simde
SHEBANG_FILES=	scripts/*

# Clang and GCC disable sse2 by default on i386, but it's required for vcflib
CFLAGS_i386=	-msse2

CONFLICTS_INSTALL=	filevercmp libdisorder # include/disorder.h include/filevercmp.h include/pdflib.hpp

.include <bsd.port.mk>
