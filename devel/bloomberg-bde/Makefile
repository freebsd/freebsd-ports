PORTNAME=	bde
DISTVERSION=	3.117.0.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	bloomberg-

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Foundational C++ libraries used at Bloomberg
WWW=		https://github.com/bloomberg/bde

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	Build uses -march=westmere

USES=		cmake python:build pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	bloomberg
GH_PROJECT=	bde-tools:tools

PORTSCOUT=	ignore:testtag

_tools=		${WRKDIR}/bde-tools-${DISTVERSION}

CMAKE_ARGS=	\
		-DBBS_ENV_MARKER=ON \
		-DBBS_BUILD_SYSTEM=ON \
		-DBDE_BUILD_TARGET_CPP17=1 \
		-DBdeBuildSystem_DIR=${_tools}/BdeBuildSystem/ \
		-DCMAKE_TOOLCHAIN_FILE=${_tools}/BdeBuildSystem/toolchains/linux/clang-default.cmake \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DCMAKE_INSTALL_LIBDIR=lib \
		--log-level=ERROR

post-stage:
		${RM} ${STAGEDIR}/${LOCALBASE}/lib/libpcre2.a
		${RM} ${STAGEDIR}/${LOCALBASE}/libdata/pkgconfig/pcre2.pc

# Tests are limited to this label. The BDE tests are grouped and hierarchical,
# with "all.t" being the most general, and then groups like "bsla.t" to select
# specific tests, down to "bsla_printf.t" for just a single test. We don't
# do all of the tests since many of them don't build yet.
_test_label=	bsla.t

do-test:
		cd ${TEST_WRKSRC} && ninja `ctest -N -L ${_test_label} | ${AWK} '/Test *#/{print $$3}'`
		cd ${TEST_WRKSRC} && ctest -L ${_test_label}

.include <bsd.port.mk>
