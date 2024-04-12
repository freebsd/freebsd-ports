PORTNAME=	sra-tools
DISTVERSION=	3.0.6
CATEGORIES=	biology java

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	NCBI's toolkit for handling data in INSDC Sequence Read Archives
WWW=		https://github.com/ncbi/sra-tools

LICENSE=		PD LGPL21+
LICENSE_COMB=		multi
LICENSE_FILE_PD=	${WRKSRC}/LICENSE
LICENSE_DISTFILES_LGPL21+ =

# Untested on other platforms, aarch64 support was recently added upstream
ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Upstream explicitly supports specific platforms

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libhdf5.so:science/hdf5 \
		libepoll-shim.so:devel/libepoll-shim \
		libzstd.so:archivers/zstd

USES=		bison cmake shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	${PREFIX}/lib64
USE_JAVA=	yes

# Builds with earlier versions, but ngs-doc plist differs if jdk17 is present
JAVA_VERSION=	17+

OPTIONS_DEFINE=	EXAMPLES

SHEBANG_GLOB=	*.sh
GH_ACCOUNT=	ncbi
GH_TUPLE+=	ncbi:ncbi-vdb:${DISTVERSION}:vdb/ncbi-vdb

CMAKE_ARGS+=	-DVDB_LIBDIR:STRING=${WRKSRC}/ncbi-vdb/build/lib

post-extract:
	@${MKDIR} ${WRKSRC}/ncbi-vdb/interfaces/os/bsd
	@${CP} ${FILESDIR}/*.h ${WRKSRC}/ncbi-vdb/interfaces/os/bsd
	# cd ${WRKDIR} && ${LN} -s ${WRKSRC}/ncbi-vdb .

pre-configure:
	# This follows a static patch.  Run "make clean patch" before
	# updating the patch.
	${REINPLACE_CMD} -e 's|/usr/local/etc/ncbi|${PREFIX}/etc/ncbi|g' \
		${WRKSRC}/ncbi-vdb/libs/kfg/config.c
	${REINPLACE_CMD} -e 's|/usr/local/bin|${PREFIX}/bin|g' \
		${WRKSRC}/tools/external/driver-tool/file-path.posix.cpp
	cd ${WRKSRC}/ncbi-vdb/build && cmake .. && make

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*.${DISTVERSION}
	${MV} ${STAGEDIR}${PREFIX}/share/examples ${STAGEDIR}${PREFIX}/share/examples-sratools
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${PREFIX}/share/examples-sratools/* ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/share/examples-sratools
	${MV} ${STAGEDIR}${PREFIX}/share/examples-java ${STAGEDIR}${EXAMPLESDIR}/java
	${MV} ${STAGEDIR}${PREFIX}/share/examples-python ${STAGEDIR}${EXAMPLESDIR}/python

post-stage-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
