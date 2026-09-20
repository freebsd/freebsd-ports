PORTNAME=	taskwarrior
PORTVERSION=	3.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Feature-rich command-line todo list manager
WWW=		https://taskwarrior.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cxxbridge:devel/rust-cxxbridge \
		${LOCALBASE}/lib/cmake/Corrosion/CorrosionConfig.cmake:devel/corrosion
TEST_DEPENDS=	faketime:devel/libfaketime

USES=		cmake cargo compiler:c++17-lang python:3.8+,test shebangfix

# The Rust part is built by corrosion through CMake, so let cargo.mk
# only fetch and vendor the crates (librsvg2-rust style).
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CONFIGURE_ENV+=	${CARGO_ENV}
MAKE_ENV+=	${CARGO_ENV}

USE_GITHUB=	yes
GH_ACCOUNT=	GothenburgBitFactory
GH_PROJECT=	taskwarrior libshared:libshared
GH_TAGNAME=	8693555:libshared
GH_SUBDIR=	src/libshared:libshared

CMAKE_ON=	SYSTEM_CORROSION
CMAKE_ARGS+=	-DTASK_DOCDIR:STRING=${DATADIR:S/${PREFIX}\///} \
		-DTASK_MAN1DIR:STRING=share/man/man1 \
		-DTASK_MAN5DIR:STRING=share/man/man5

SHEBANG_FILES=	test/*.test.py

post-patch:
	# The hook test wrapper invokes a bare "python3" to timestamp hook logs.
	@${REINPLACE_CMD} -e 's|python3 -c|${PYTHON_CMD} -c|' \
		${WRKSRC}/test/test_hooks/wrapper.sh

# corrosion_add_cxxbridge() only uses a preinstalled cxxbridge if its
# version exactly matches the cxx crate version from Cargo.lock;
# otherwise it would try to "cargo install" it at build time (network!).
pre-configure:
	@v=$$(cxxbridge --version 2>/dev/null | ${SED} -En 's/^cxxbridge ([0-9.]+)$$/\1/p'); \
	l=$$(${SED} -En '/^name = "cxx"$$/{n;s/^version = "([^"]+)".*/\1/p;}' ${WRKSRC}/Cargo.lock); \
	if [ "$$v" != "$$l" ]; then \
		${ECHO_MSG} "===> cxxbridge ($$v) does not match the cxx crate in Cargo.lock ($$l)"; \
		${ECHO_MSG} "===> Update devel/cxxbridge (or Cargo.lock) so both versions match"; \
		exit 1; \
	fi

do-test:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${CMAKE_BIN} --build . --target test_runner
	@${CP} ${WRKSRC}/doc/rc/* ${TEST_WRKSRC}/test/
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ctest -j${MAKE_JOBS_NUMBER} --output-on-failure

.include <bsd.port.pre.mk>

# i386 has a 32-bit time_t; the braced init in Datetime::operator+/- then
# narrows int64_t -> time_t, which clang rejects with -Wc++11-narrowing.
.if ${ARCH} == i386
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src_libshared_src_Datetime.cpp
.endif

.include <bsd.port.post.mk>
