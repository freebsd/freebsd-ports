PORTNAME=	libhtp
DISTVERSION=	0.5.51
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Security-aware parser for the HTTP protocol
WWW=		https://github.com/ironbee/libhtp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf cpe iconv:translit libtool localbase:ldflags pathfix \
		pkgconfig
CPE_VENDOR=	oisf
USE_GITHUB=	yes
GH_ACCOUNT=	OISF
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}

MAKE_ARGS=	LIBS="-lz ${ICONV_LIB}"
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
