PORTNAME=	capnproto
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMESUFFIX=	080

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Serialization/RPC system

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		autoreconf compiler:c++14-lang cpe gmake libtool ssl

CONFIGURE_ARGS=	ac_cv_lib_ssl_OPENSSL_init_ssl=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}
WRKSRC_SUBDIR=	c++

USE_GITHUB=	yes

CONFLICTS_INSTALL=	capnproto

# databases/tiledb requires capnproto 0.8.0
PORTSCOUT=	ignore:1

.include <bsd.port.mk>
