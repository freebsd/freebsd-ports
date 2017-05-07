# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libevent2
PORTVERSION=	2.0.22
DISTVERSIONPREFIX=	release-
DISTVERSIONSUFFIX=	-stable
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	mm@FreeBSD.org
COMMENT=	API for executing callback functions on events or timeouts

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	${GH_PROJECT}
GH_PROJECT=	${PORTNAME:S/2$//}

GNU_CONFIGURE=	yes
USES=		autoreconf libtool pathfix
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	OPENSSL THREADS
OPTIONS_DEFAULT=	OPENSSL THREADS
OPTIONS_SUB=	yes
INSTALL_TARGET=	install-strip

OPENSSL_USE=	openssl=yes
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}
OPENSSL_CONFIGURE_ENABLE=	openssl

THREADS_CONFIGURE_ENABLE=	thread-support

post-patch:
	${ECHO_CMD} 'AC_CONFIG_MACRO_DIR([m4])' >>${WRKSRC}/configure.in
# error: using '$(top_srcdir)' in TESTS is currently broken
	${REINPLACE_CMD} 's/^TESTS.*top_srcdir/#&/' ${WRKSRC}/test/Makefile.am

regression-test: build
	@(${SH} ${WRKSRC}/test/regress)

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENSSL} && ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.include <bsd.port.post.mk>
