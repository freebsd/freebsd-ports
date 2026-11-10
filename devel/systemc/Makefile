PORTNAME=	systemc
DISTVERSION=	3.0.2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ classes and macros for describing complex hardware systems
WWW=		https://www.accellera.org/downloads/standards/systemc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386 powerpc powerpc64 powerpc64le
ONLY_FOR_ARCHS_REASON=	configure: error: sorry...architecture not supported

USES=		autoreconf compiler:c++17-lang gmake libtool
USE_CXXSTD=	c++17 # needs to match that of cad/verilator, to avoid mismatches like https://github.com/verilator/verilator/issues/4499
USE_GITHUB=	yes
GH_ACCOUNT=	accellera-official
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unix-layout=yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
CONFIGURE_ARGS+=	--enable-pthreads
.endif

# tests as of 3.0.2: SystemC examples: 22 tests, 22 PASS, 0 FAIL; TLM 2.0.6 examples: 11 tests, 11 PASS, 0 FAIL

.include <bsd.port.mk>
