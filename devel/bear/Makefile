PORTNAME=	bear
DISTVERSION=	3.1.5
PORTREVISION=	13
CATEGORIES=	devel

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Tool that generates a compilation database for clang tooling
WWW=		https://github.com/rizsotto/Bear

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libabsl_hash.so:devel/abseil \
		libfmt.so:devel/libfmt \
		libgrpc.so:devel/grpc \
		libprotobuf.so:devel/protobuf \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rizsotto
GH_PROJECT=	Bear

CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR=${DOCSDIR} \
		-DENABLE_FUNC_TESTS=OFF \
		-DENABLE_UNIT_TESTS=OFF

OPTIONS_DEFINE=	DOCS

CLANG_COMPILERS=	33 34 35 36 37 38 39 40 50 60 70 80 90 10 11 12 13 14 \
			15 16 17 18 19 20
GNU_COMPILERS=		34 42 43 44 45 46 47 48 49 5 6 7 8 9 10 11 12 13 14 15
COMPILERS=		cc c++ CC clang clang++ ${CLANG_COMPILERS:S|^|clang|} \
			${CLANG_COMPILERS:S|^|clang++|} \
			${CLANG_COMPILERS:S|^|cpp|} gcc g++ \
			${GNU_COMPILERS:S|^|gcc|} ${GNU_COMPILERS:S|^|g++|} \
			${GNU_COMPILERS:S|^|cpp|} icc icpc llvm-gcc llvm-c++ \
			llvm-g++
WRAPPERS=		${COMPILERS} R ar as bison ctangle cweave f77 flex \
			gfortran ld lex lint m2c makeinfo nm objcopy objdump pc \
			ranlib readelf strip tangle tex tex2dvi weave yacc

pre-install:
	${MV} ${STAGEDIR}/${CONFIGURE_WRKSRC}/stage ${CONFIGURE_WRKSRC}/
	${RM} -r ${STAGEDIR}/wrkdirs

post-install:
.for l in bin/bear lib/bear/libexec.so lib/bear/wrapper
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${l}
.endfor
.for w in ${WRAPPERS}
	${RLN} ${STAGEDIR}${PREFIX}/lib/bear/wrapper \
		${STAGEDIR}${PREFIX}/lib/bear/wrapper.d/${w}
.endfor

.include <bsd.port.mk>
