# Created by: Felix Hanley
# $FreeBSD$

PORTNAME=	capnproto
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	felix@userspace.com.au
COMMENT=	Serialization/RPC system

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		autoreconf compiler:c++14-lang gmake libtool ssl

USE_GITHUB=	yes
GH_ACCOUNT=	capnproto
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	ac_cv_lib_ssl_OPENSSL_init_ssl=yes

WRKSRC_SUBDIR=	c++

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
