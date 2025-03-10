PORTNAME=	MMseqs2
DISTVERSION=	17-b804f
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultra fast and sensitive sequence search and clustering suite
WWW=		https://github.com/soedinglab/MMseqs2/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc powerpcspe

BUILD_DEPENDS=	zstd>0:archivers/zstd

USES=		cmake perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	soedinglab
USE_PERL5=	build

SHEBANG_GLOB=	*.sh

CMAKE_ARGS+=	-DVERSION_OVERRIDE=${DISTVERSION}
CMAKE_ON=	DISABLE_IPS4O USE_SYSTEM_ZSTD

LDFLAGS+=	-lpthread

PLIST_FILES=	bin/mmseqs ${DATADIR}/bash-completion.sh

.if !exists(/usr/include/omp.h)
CMAKE_ARGS+=	-DREQUIRE_OPENMP=0
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" && empty(CFLAGS:M*march=native*)
# Need at least SSE2 for decent performance.  x86-64 groups SSE2 with other
# common features in low-end AMD64 CPUs.
CFLAGS+=	-march=x86-64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|MMSEQS_HOME/util|${DATADIR}|g' \
		${WRKSRC}/src/commons/Application.cpp

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/util ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
