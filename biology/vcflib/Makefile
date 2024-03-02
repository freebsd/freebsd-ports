PORTNAME=		vcflib
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.7
PORTREVISION=		1
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ library and CLI tools for parsing and manipulating VCF files
WWW=		https://github.com/vcflib/vcflib

LICENSE=	MIT

NOT_FOR_ARCHS=	armv6 armv7
NOT_FOR_ARCHS_REASON=	requires OpenMP which is not supported

BUILD_DEPENDS=	pybind11>0:devel/pybind11
LIB_DEPENDS=	libhts.so:biology/htslib \
		libcurl.so:ftp/curl \
		libwfa2.so:biology/wfa2-lib

USES=		cmake:noninja gmake localbase:ldflags pkgconfig python shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	ekg
GH_TUPLE=	ekg:fastahack:bb33265:fastahack/contrib/fastahack \
		ekg:filevercmp:df20dcc:filevercmp/contrib/filevercmp \
		ekg:fsom:56695e1:fsom/contrib/fsom \
		ekg:intervaltree:aa59377:intervaltree/contrib/intervaltree \
		edawson:libVCFH:44b6580:libVCFH/contrib/libVCFH \
		ekg:multichoose:e1f94ae:multichoose/contrib/multichoose \
		ekg:smithwaterman:2610e25:smithwaterman/contrib/smithwaterman \
		simd-everywhere:simde-no-tests:9af03cd:simd/src/simde \
		vcflib:tabixpp:v1.1.2:tabixpp/contrib/tabixpp
SHEBANG_FILES=	scripts/*

# FIXME: Add Zig option + lang/zig dep
OPTIONS_DEFINE=		ZIG
OPTIONS_DEFAULT=
OPTIONS_SUB=		yes

ZIG_DESC=		Include Zig language support

ZIG_BUILD_DEPENDS=	zig010>0:lang/zig010

CMAKE_ARGS+=	-DWFA_GITMODULE=OFF -DWFALIB=${LOCALBASE}/lib/libwfa2.so
ZIG_CMAKE_OFF=	-DZIG=OFF

# Clang and GCC disable sse2 by default on i386, but it's required for vcflib
CFLAGS_i386=	-msse2

CONFLICTS_INSTALL=	filevercmp libdisorder # include/disorder.h include/filevercmp.h include/pdflib.hpp

.include <bsd.port.options.mk>

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/bin/libvcflib.a ${STAGEDIR}${PREFIX}/lib
.if ${PORT_OPTIONS:MZIG}
	${MV} ${STAGEDIR}/usr/lib/libzig.a ${STAGEDIR}${PREFIX}/lib
.endif

.include <bsd.port.mk>
