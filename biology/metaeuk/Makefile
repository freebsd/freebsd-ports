PORTNAME=	metaeuk
DISTVERSION=	7
DISTVERSIONSUFFIX=	-bba0d80
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gene discovery and annotation for large-scale eukaryotic metagenomics
WWW=		https://github.com/soedinglab/metaeuk

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE.md

NOT_FOR_ARCHS=	armv6 armv7 i386 mips powerpc # 32-bit platforms produce wrong results based on https://github.com/soedinglab/metaeuk/issues/85#issuecomment-1888379107
NOT_FOR_ARCHS+=	powerpc64 # many modules produce wrong results on big-endian architectures
BROKEN_powerpc64le=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=276268

BUILD_DEPENDS=	xxd:editors/vim
TEST_DEPENDS=	bash:shells/bash

USES=		cmake perl5 shebangfix
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	soedinglab
GH_TUPLE=	soedinglab:metaeuk-regression:f7c3999:metaeuk_regression/tests \
		soedinglab:MMseqs2-Regression:5e3bc17:MMseqs2_Regression/lib/mmseqs/util/regression

SHEBANG_GLOB=	*.sh

PLIST_FILES=	bin/metaeuk

CMAKE_OFF=	NATIVE_ARCH

.include <bsd.port.options.mk>

.if !exists(/usr/include/omp.h) || ${ARCH} == powerpc64le # https://github.com/soedinglab/metaeuk/issues/85, https://github.com/llvm/llvm-project/issues/63807
CMAKE_ARGS+=	-DREQUIRE_OPENMP:BOOL=OFF

post-patch: # workaround for https://github.com/soedinglab/metaeuk/issues/55
	@${REINPLACE_CMD} -e 's|set(REQUIRE_OPENMP 1 |set(REQUIRE_OPENMP 0 |' ${WRKSRC}/lib/mmseqs/src/CMakeLists.txt
.endif

do-test:
	@cd ${WRKSRC}/tests && ./run.sh ${STAGEDIR}${PREFIX}/bin/metaeuk

.include <bsd.port.mk>
