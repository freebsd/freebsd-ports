# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libevent2
PORTVERSION=	2.0.21
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/libevent/libevent/
DISTNAME=	${PORTNAME:S/2//}-${DISTVERSION}-stable

MAINTAINER=	mm@FreeBSD.org
COMMENT=	API for executing callback functions on events or timeouts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USES=		libtool pathfix
USE_LDCOFNIG=	yes

OPTIONS_DEFINE=	OPENSSL THREADS
OPTIONS_DEFAULT=	OPENSSL THREADS
OPTIONS_SUB=	yes
INSTALL_TARGET=	install-strip

OPENSSL_USE=	openssl=yes
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}
OPENSSL_CONFIGURE_ENABLE=	openssl

THREADS_CONFIGURE_ENABLE=	support

regression-test: build
	@(${SH} ${WRKSRC}/test/regress)

.include <bsd.port.mk>
