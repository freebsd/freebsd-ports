PORTNAME=	systemc
DISTVERSION=	3.0.0
DISTVERSIONSUFFIX=	_pub_rev_20231129
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ classes and macros for describing complex hardware systems
WWW=		https://www.accellera.org/downloads/standards/systemc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	configure: error: sorry...architecture not supported

USES=		compiler:c++17-lang gmake libtool
USE_CXXSTD=	c++17 # needs to match that of cad/verilator, to avoid mismatches like https://github.com/verilator/verilator/issues/4499
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	accellera-official

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unix-layout=yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
