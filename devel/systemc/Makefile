PORTNAME=	systemc
DISTVERSION=	3.0.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ classes and macros for describing complex hardware systems
WWW=		https://www.accellera.org/downloads/standards/systemc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	configure: error: sorry...architecture not supported

USES=		autoreconf compiler:c++17-lang gmake libtool
USE_CXXSTD=	c++17 # needs to match that of cad/verilator, to avoid mismatches like https://github.com/verilator/verilator/issues/4499
USE_GITHUB=	yes
GH_ACCOUNT=	accellera-official
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unix-layout=yes

INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
