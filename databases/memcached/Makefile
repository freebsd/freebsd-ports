# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	1.5.19
CATEGORIES=	databases
MASTER_SITES=	http://www.memcached.org/files/ \
		GENTOO

MAINTAINER=	swills@FreeBSD.org
COMMENT=	High-performance distributed memory object cache system

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=		fails to link: failed to merge target specific data of file /usr/lib/dtrace/drti.o
BROKEN_mips64=		fails to link: failed to merge target specific data of file /usr/lib/dtrace/drti.o

LIB_DEPENDS=	libevent.so:devel/libevent

CONFLICTS=	memcached-1.2*

USES=		cpe shebangfix autoreconf
SHEBANG_FILES=	scripts/memcached-tool

USE_RC_SUBR=	memcached
SUB_LIST+=	RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX}

USE_CSTD=	c99
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE} \
		--program-prefix= \
		--disable-coverage

# Dtrace option disabled until it is fixed upstream
OPTIONS_DEFINE=		SASL DOCS DTRACE
OPTIONS_DEFAULT=	SASL DTRACE

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE+=	DTRACE
.endif

OPTIONS_EXCLUDE_i386=		DTRACE
# ld(1) fails to link probes: Relocations in generic ELF (EM: 0)
OPTIONS_EXCLUDE_aarch64=	DTRACE
OPTIONS_EXCLUDE_armv6=		DTRACE
OPTIONS_EXCLUDE_armv7=		DTRACE
# /tmp/conftest-4d18ad.s:2: Error: unknown pseudo-op: `.abiversion'
OPTIONS_EXCLUDE_powerpc64=	DTRACE

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

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--enable-64bit
.endif

# avoid triggering a bug in libdtrace, see illumos issue 6653
.if ${PORT_OPTIONS:MDTRACE}
CFLAGS+=		-no-integrated-as
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
