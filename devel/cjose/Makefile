# $FreeBSD$

PORTNAME=	cjose
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jamie@chair6.net
COMMENT=	C library implementing Javascript Object Signing & Encryption (JOSE)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjansson.so:devel/jansson

USES=		compiler:c++11-lang libtool pathfix pkgconfig ssl
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	cisco

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jansson=${PREFIX} --with-openssl=${OPENSSLBASE}

.include <bsd.port.mk>
