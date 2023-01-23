PORTNAME=		vcflib
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.5
PORTREVISION=		1
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files
WWW=		https://github.com/vcflib/vcflib

LICENSE=	MIT

BUILD_DEPENDS=	zig>0:lang/zig \
		pybind11>=0:devel/pybind11
LIB_DEPENDS=	libhts.so:biology/htslib \
		libcurl.so:ftp/curl

USES=		cmake:noninja gmake localbase:ldflags pkgconfig python shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	ekg
GH_TUPLE=	ekg:fastahack:bb33265:fastahack/contrib/fastahack \
		ekg:filevercmp:1a9b779:filevercmp/contrib/filevercmp \
		ekg:fsom:a6ef318:fsom/contrib/fsom \
		google:googletest:d225acc:googletest/contrib/googletest \
		ekg:intervaltree:aa59377:intervaltree/contrib/intervaltree \
		edawson:libVCFH:44b6580:libVCFH/contrib/libVCFH \
		ekg:multichoose:68733cd:multichoose/contrib/multichoose \
		ekg:smithwaterman:2610e25:smithwaterman/contrib/smithwaterman \
		simd-everywhere:simde-no-tests:9af03cd:simd/src/simde \
		vcflib:tabixpp:v1.1.2:tabixpp/contrib/tabixpp \
		smarco:WFA2-lib:v2.3:wfa2/contrib/WFA2-lib
SHEBANG_FILES=	scripts/*

# Clang and GCC disable sse2 by default on i386, but it's required for vcflib
CFLAGS_i386=	-msse2

CONFLICTS_INSTALL=	filevercmp libdisorder # include/disorder.h include/filevercmp.h include/pdflib.hpp

post-stage:
	${MV} ${STAGEDIR}/usr/lib/libzig.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
