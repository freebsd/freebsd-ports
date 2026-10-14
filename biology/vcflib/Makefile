PORTNAME=	vcflib
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.15
CATEGORIES=	biology

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files
WWW=		https://github.com/vcflib/vcflib

LICENSE=	MIT

NOT_FOR_ARCHS=	armv6 armv7
NOT_FOR_ARCHS_REASON=	requires OpenMP which is not supported

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pypandoc>=1.4:textproc/py-pypandoc@${PY_FLAVOR} \
		pybind11>0:devel/pybind11
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libhts.so:biology/htslib \
		libwfa2.so:biology/wfa2-lib

USES=		cmake:noninja gmake localbase:ldflags pkgconfig python \
		shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	ekg
GH_TUPLE=	pjotrp:WFA2-lib:f86a35a:wfa2lib/contrib/WFA2-lib \
		ekg:fastahack:bb33265:fastahack/contrib/fastahack \
		ekg:filevercmp:df20dcc:filevercmp/contrib/filevercmp \
		ekg:fsom:56695e1:fsom/contrib/fsom \
		ekg:intervaltree:aa59377:intervaltree/contrib/intervaltree \
		edawson:libVCFH:44b6580:libvcfh/contrib/libVCFH \
		vcflib:multichoose:255192e:multichoose/contrib/multichoose \
		ekg:smithwaterman:2610e25:smithwaterman/contrib/smithwaterman \
		vcflib:tabixpp:0f55194:tabixpp/contrib/tabixpp \
		samtools:htslib:53f9808:htslib/contrib/tabixpp/htslib \
		samtools:htscodecs:3ef17f6f:htscodecs/contrib/tabixpp/htslib/htscodecs \
		simd-everywhere:simde-no-tests:099e711:simdenotests/src/simde

SHEBANG_FILES=	scripts/*

OPTIONS_DEFINE=	ZIG
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

ZIG_DESC=	Use the Zig language implementation

ZIG_BUILD_DEPENDS=	zig015>=0.15.0:lang/zig015
ZIG_CMAKE_BOOL=		ZIG

CMAKE_ARGS+=	-DTABIXPP_LOCAL=${WRKSRC}/contrib/tabixpp \
		-DWFA_GITMODULE=OFF \
		-DWFALIB=${LOCALBASE}/lib/libwfa2.so.0

# Clang and GCC disable sse2 by default on i386, but it's required for vcflib
CFLAGS_i386=	-msse2

# filevercmp is deprecated.  Remove conflict when the port is removed.
CONFLICTS_INSTALL=	filevercmp libdisorder # include/disorder.h include/filevercmp.h include/pdflib.hpp

.include <bsd.port.mk>
