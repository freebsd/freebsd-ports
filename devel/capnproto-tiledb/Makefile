PORTNAME=	capnproto
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	c++-
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://capnproto.org/
PKGNAMESUFFIX=	-tiledb

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Serialization/RPC system (for databases/tiledb)
WWW=		https://capnproto.org/ \
		https://github.com/capnproto/capnproto

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c++14-lang cpe gmake libtool ssl

CONFIGURE_ARGS=	ac_cv_lib_ssl_OPENSSL_init_ssl=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CONFLICTS_INSTALL=	capnproto

# databases/tiledb 2.30.1+ requires capnproto 1.3.0
PORTSCOUT=	ignore:1

.include <bsd.port.mk>
