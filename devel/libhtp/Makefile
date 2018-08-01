# $FreeBSD$

PORTNAME=	libhtp
PORTVERSION=	0.5.27
CATEGORIES=	devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Security-aware parser for the HTTP protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	OISF

USES=		autoreconf iconv:translit libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
MAKE_ARGS=	LIBS="-lz ${ICONV_LIB}"
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
