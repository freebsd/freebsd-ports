PORTNAME=		salmon
DISTVERSIONPREFIX=	v
DISTVERSION=		1.10.2
PORTREVISION=	2
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
		aclocal:devel/automake
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libtbb.so:devel/onetbb \
		libcurl.so:ftp/curl

USES=		cmake:noninja gmake localbase shebangfix
USE_GITHUB=	yes

GH_ACCOUNT=	COMBINE-lab
GH_TUPLE+=	COMBINE-lab:pufferfish:salmon-v1.10.2:pf/external/pufferfish
GH_TUPLE+=	jkbonfield:io_lib:io_lib-1-14-15:sio/external/staden-io_lib
GH_TUPLE+=	samtools:htscodecs:5aecc6e:htscodec/external/staden-io_lib/htscodecs
SHEBANG_FILES=	scripts/*

PLIST_FILES=	bin/salmon
CMAKE_ARGS+=	-DHAVE_FAST_MALLOC:BOOL=on \
		-DBOOST_ROOT:PATH=${LOCALBASE} \
		-DFETCHED_PUFFERFISH:BOOL=on \
		-DFETCHED_LIBGFF:BOOL=on \
		-DFETCH_STADEN:BOOL=true
WITH_DEBUG=	yes
LDFLAGS+=	-lpthread

pre-configure:
	(cd ${WRKSRC}/external/staden-io_lib && ./bootstrap)

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/salmon ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
