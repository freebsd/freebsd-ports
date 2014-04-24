# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libevent2
PORTVERSION=	2.0.21
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://cloud.github.com/downloads/libevent/libevent/
DISTNAME=	${PORTNAME:S/2//}-${DISTVERSION}-stable

MAINTAINER=	mm@FreeBSD.org
COMMENT=	API for executing callback functions on events or timeouts

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USES=		libtool:oldver pathfix
USE_LDCONFIG=	${PREFIX}/lib/event2

OPTIONS_DEFINE=	OPENSSL THREADS
OPTIONS_DEFAULT=	OPENSSL THREADS

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/event2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
PLIST_SUB+=		OPENSSL=""
.else
CONFIGURE_ARGS+=	--disable-openssl
PLIST_SUB+=		OPENSSL="@comment "
.endif

.if ${PORT_OPTIONS:MTHREADS}
PLIST_SUB+=		THREADS=""
.else
CONFIGURE_ARGS+=	--disable-thread-support
PLIST_SUB+=		THREADS="@comment "
.endif

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/event_rpcgen.py ${STAGEDIR}${PREFIX}/bin/event2_rpcgen.py

regression-test: build
	@(${SH} ${WRKSRC}/test/regress)

.include <bsd.port.mk>
