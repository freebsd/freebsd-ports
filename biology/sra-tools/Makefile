PORTNAME=	sra-tools
DISTVERSION=	3.3.0
PORTREVISION=	2
CATEGORIES=	biology java

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI's toolkit for handling data in INSDC Sequence Read Archives
WWW=		https://github.com/ncbi/sra-tools

LICENSE=		PD LGPL21+
LICENSE_COMB=		multi
LICENSE_FILE_PD=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_LGPL21+ =

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Upstream explicitly supports specific platforms

# hdf5 is dynamically loaded by some tools, but nothing links to it
BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	hdf5>0:science/hdf5

USES=		bison cmake java shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/lib64

# Builds with earlier versions, but ngs-doc plist differs if jdk17 is present
JAVA_VERSION=	17

OPTIONS_DEFINE=	EXAMPLES

SHEBANG_GLOB=	*.sh
GH_ACCOUNT=	ncbi
# FIXME: At the time this was added, sra-tools build required access to the
# ncbi-vdb source tree.  Use a separate dependent port if that is no
# longer the case.  CMakeLists.txt still looks for ../ncbi-vdb in 3.1.1.
GH_TUPLE+=	ncbi:ncbi-vdb:${DISTVERSION}:vdb/ncbi-vdb

CMAKE_ARGS+=	-DVDB_LIBDIR:STRING=${WRKSRC}/ncbi-vdb/build/lib
# Prevent cmake from using a later Java version, if present
CMAKE_ARGS+=	-DJAVA_HOME:PATH=${JAVA_HOME}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

pre-configure:
	# Reinplaces may follow static patches.  Run "make clean patch"
	# before updating those patches so reinplaces do not get added to them.
	@${REINPLACE_CMD} -e 's|"/etc/ncbi"|"${PREFIX}/etc/ncbi"|g' \
		${WRKSRC}/ncbi-vdb/libs/kfg/config.c
	@${REINPLACE_CMD} -e 's|/usr/local/bin|${PREFIX}/bin|g' \
		${WRKSRC}/tools/external/driver-tool/file-path.posix.cpp
	@${REINPLACE_CMD} -e 's|/../ncbi-vdb|/ncbi-vdb|g' \
		${WRKSRC}/CMakeLists.txt
	cd ${WRKSRC}/ncbi-vdb/build && cmake .. && make

# FIXME: Unsure where the jquery version comes from and it differs on
# amd64 (jquery-3.7.1.min.js) and aarch64 (jquery-3.6.1.min.js).
# Just hack the version out for now.  Not sure we even need javadoc installed.
post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*.${DISTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib64/*.${DISTVERSION}
	${MV} ${STAGEDIR}${JAVASHAREDIR}doc/ngs-doc/script-dir/jquery-[0-9]*.min.js \
		${STAGEDIR}${JAVASHAREDIR}doc/ngs-doc/script-dir/jquery.min.js

post-stage-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
