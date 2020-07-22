# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libevent
DISTVERSION=	2.1.12
DISTVERSIONSUFFIX=	-stable
CATEGORIES=	devel
MASTER_SITES=   https://github.com/${PORTNAME}/${PORTNAME}/releases/download/release-${DISTVERSION}${DISTVERSIONSUFFIX}/

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	API for executing callback functions on events or timeouts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libtool pathfix pkgconfig python:env shebangfix
SHEBANG_FILES=	event_rpcgen.py
GNU_CONFIGURE=	yes
CPE_VENDOR=	libevent_project
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
