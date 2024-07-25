PORTNAME=	capnproto
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	c++-
CATEGORIES=	devel
MASTER_SITES=	https://capnproto.org/
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Serialization/RPC system
WWW=		https://capnproto.org/ \
		https://github.com/capnproto/capnproto

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++14-lang cpe gmake libtool pathfix ssl

CONFIGURE_ARGS=	ac_cv_lib_ssl_OPENSSL_init_ssl=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CONFLICTS_INSTALL=	capnproto

# databases/tiledb requires capnproto 1.0.1
PORTSCOUT=	ignore:1

.include <bsd.port.mk>
