PORTNAME=		salmon
DISTVERSIONPREFIX=	v
DISTVERSION=		1.10.3
CATEGORIES=		biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Transcript-level quantification of RNA-seq from lightweight alignments
WWW=		https://github.com/COMBINE-lab/salmon

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		armv6 armv7 i386 mips powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	Requires 64-bit processor

# libtool and auto* are run manually in submodules, so don't put them in USES
BUILD_DEPENDS=	bash:shells/bash \
		cereal>=1.3.0:devel/cereal \
		libgff==2.0.0:biology/libgff \
		libtool:devel/libtool \
		autoreconf:devel/autoconf \
		aclocal:devel/automake \
		eigen>0:math/eigen3 \
		libdivide>0:math/libdivide \
		curl>0:ftp/curl
LIB_DEPENDS=	libtbb.so:devel/onetbb

USES=		cmake:noninja gmake localbase shebangfix
USE_GITHUB=	yes

# Can't unbundle io_lib unless we also unbundle htscodecs from io_lib,
# which is a nightmare: explicitly integrated into configure files and
# installs htscodecs files, conflicting with separate htscodecs port.
GH_ACCOUNT=	COMBINE-lab
GH_TUPLE+=	COMBINE-lab:pufferfish:salmon-v${DISTVERSION}:pf/external/pufferfish
GH_TUPLE+=	jkbonfield:io_lib:io_lib-1-15-1:sio/external/staden-io_lib
# Update commit hash from io_lib release branch
GH_TUPLE+=	samtools:htscodecs:de42211:htscodec/external/staden-io_lib/htscodecs
SHEBANG_FILES=	scripts/*

PLIST_FILES=	bin/salmon
CMAKE_ARGS+=	-DHAVE_FAST_MALLOC:BOOL=on \
		-DBOOST_ROOT:PATH=${LOCALBASE} \
		-DFETCHED_PUFFERFISH:BOOL=on \
		-DFETCHED_LIBGFF:BOOL=on \
		-DFETCH_STADEN:BOOL=true
WITH_DEBUG=	yes
CXXFLAGS+=	-I${LOCALBASE}/include/eigen3
LDFLAGS+=	-lpthread

pre-configure:
	${RM} -rf ${WRKSRC}/include/eigen3 \
		${WRKSRC}/external/pufferfish/include/libdivide
	(cd ${WRKSRC}/external/staden-io_lib && ./bootstrap)

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/salmon ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
