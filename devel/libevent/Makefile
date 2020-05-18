# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libevent
DISTVERSIONPREFIX=	release-
DISTVERSION=	2.1.11
DISTVERSIONSUFFIX=	-stable
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	API for executing callback functions on events or timeouts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf libtool pathfix pkgconfig python:env shebangfix
SHEBANG_FILES=	event_rpcgen.py
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	OPENSSL THREADS
OPTIONS_DEFAULT=	OPENSSL THREADS
OPTIONS_SUB=	yes

OPENSSL_USES=	ssl
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}
OPENSSL_CONFIGURE_ENABLE=	openssl

THREADS_CONFIGURE_ENABLE=	thread-support

.include <bsd.port.mk>
