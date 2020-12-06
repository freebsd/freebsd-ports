# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	1.6.9
CATEGORIES=	databases
MASTER_SITES=	http://www.memcached.org/files/ \
		GENTOO

MAINTAINER=	swills@FreeBSD.org
COMMENT=	High-performance distributed memory object cache system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	as:devel/binutils
LIB_DEPENDS=	libevent.so:devel/libevent

USES=		autoreconf cpe shebangfix
SHEBANG_FILES=	scripts/memcached-tool

USE_RC_SUBR=	memcached
SUB_LIST+=	RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX}

USE_CSTD=	c99
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-coverage \
		--program-prefix= \
		--with-libevent=${LOCALBASE}

# Dtrace option disabled until it is fixed upstream
OPTIONS_DEFINE=		DOCS SASL
OPTIONS_DEFAULT=	SASL
OPTIONS_DEFINE_amd64=	DTRACE
OPTIONS_DEFAULT_amd64=	DTRACE
OPTIONS_DEFINE_powerpc64=	DTRACE
OPTIONS_DEFAULT_powerpc64=	DTRACE
OPTIONS_EXCLUDE_powerpc64=	${OPTIONS_EXCLUDE_${ARCH}_${OSREL:R}}
OPTIONS_EXCLUDE_powerpc64_11=	DTRACE
OPTIONS_EXCLUDE_powerpc64_12=	DTRACE
OPTIONS_DEFINE_powerpc64le=	DTRACE
OPTIONS_DEFAULT_powerpc64le=	DTRACE

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE+=	DTRACE
.endif

DTRACE_DESC=	Enable dtrace probes
SASL_DESC=	Enable SASL Authentication

DOCS_BUILD_DEPENDS=	xml2rfc:textproc/xml2rfc
DOCS_CONFIGURE_ENABLE=	docs

DTRACE_CONFIGURE_ENABLE=	dtrace

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ENABLE=	sasl
SASL_CFLAGS=		-I${LOCALBASE}/include
SASL_CPPFLAGS+=		${CFLAGS}
SASL_LDFLAGS=		-L${LOCALBASE}/lib

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200057
CONFIGURE_ARGS+=	--enable-tls
USES+=			ssl
.endif

.if ${ARCH} == amd64 || ${ARCH:Mpowerpc64*}
CONFIGURE_ARGS+=	--enable-64bit
.endif

# avoid triggering a bug in libdtrace, see illumos issue 6653
.if ${PORT_OPTIONS:MDTRACE} && ${ARCH} == amd64
CFLAGS+=	-no-integrated-as
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/memcached-tool ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in protocol-binary-range.txt protocol-binary.txt protocol.txt \
		readme.txt threads.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

regression-test: test
test: build
	${MAKE} -C ${WRKSRC} test

.include <bsd.port.post.mk>
