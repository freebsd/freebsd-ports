# Created by: Felix Hanley

PORTNAME=	capnproto
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	felix@userspace.com.au
COMMENT=	Serialization/RPC system

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		autoreconf compiler:c++14-lang gmake libtool ssl
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_lib_ssl_OPENSSL_init_ssl=yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

WRKSRC_SUBDIR=	c++

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

.include <bsd.port.mk>
