# $FreeBSD$

PORTNAME=	cjose
PORTVERSION=	0.4.1
CATEGORIES=	devel

MAINTAINER=	jamie@chair6.net
COMMENT=	C library implementing Javascript Object Signing & Encryption (JOSE)

LICENSE=	MIT

LIB_DEPENDS+=	libjansson.so:devel/jansson

USES=		libtool pathfix ssl
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	cisco
GH_PROJECT=	cjose

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jansson=${PREFIX} --with-openssl=${PREFIX}

.include <bsd.port.mk>
