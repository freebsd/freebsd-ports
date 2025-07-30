PORTNAME=	memcached
DISTVERSION=	1.6.39
CATEGORIES=	databases
MASTER_SITES=	http://www.memcached.org/files/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High-performance distributed memory object cache system
WWW=		https://memcached.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		autoreconf cpe pkgconfig shebangfix
USE_CSTD=	c99
USE_RC_SUBR=	memcached

SHEBANG_FILES=	scripts/memcached-tool

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-coverage \
		--program-prefix= \
		--with-libevent=${LOCALBASE}

MAKE_JOBS_UNSAFE=	yes

SUB_LIST+=	RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX}

# Dtrace option disabled until it is fixed upstream
OPTIONS_DEFINE=		DOCS SASL
OPTIONS_DEFINE_amd64=	DTRACE
OPTIONS_DEFINE_powerpc64=	DTRACE
OPTIONS_DEFINE_powerpc64le=	DTRACE
OPTIONS_DEFAULT=	SASL
OPTIONS_DEFAULT_amd64=	DTRACE
OPTIONS_DEFAULT_powerpc64=	DTRACE
OPTIONS_DEFAULT_powerpc64le=	DTRACE

DTRACE_DESC=	Enable dtrace probes
SASL_DESC=	Enable SASL Authentication

DOCS_BUILD_DEPENDS=	xml2rfc:textproc/xml2rfc
DOCS_CONFIGURE_ENABLE=	docs
DTRACE_CONFIGURE_ENABLE=	dtrace
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_USES=	localbase:ldflags
SASL_CONFIGURE_ENABLE=	sasl

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CONFIGURE_ARGS+=	--enable-tls
USES+=			ssl
.endif

.if ${ARCH} == amd64 || ${ARCH:Mpowerpc64*}
CONFIGURE_ARGS+=	--enable-64bit
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
