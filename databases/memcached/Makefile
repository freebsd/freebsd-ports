# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	memcached
PORTVERSION=	1.4.15
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	swills@FreeBSD.org
COMMENT=	High-performance distributed memory object cache system

LIB_DEPENDS=	libevent-1.4.so:${PORTSDIR}/devel/libevent

TEST_DEPENDS=	prove:${PORTSDIR}/lang/${PERL_PORT} \
		git:${PORTSDIR}/devel/git

CONFLICTS=	memcached-1.2*

# Dtrace option disabled until it is fixed upstream
OPTIONS_DEFINE=	REPCACHED SASL
DTRACE_DESC=	Enable dtrace probes
REPCACHED_DESC=	Enable data replication feature
SASL_DESC=	Enable SASL Authentication

USE_RC_SUBR=	memcached
SUB_LIST+=	RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX}

USE_CSTD=	c99
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent=${LOCALBASE} --program-prefix= \
		--disable-coverage

MAN1=		memcached.1

PLIST_FILES=	bin/memcached \
		bin/memcached-tool \
		include/memcached/protocol_binary.h
PLIST_DIRS=	include/memcached

PORTDOCS=	protocol.txt readme.txt

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
CFLAGS+=	-fstack-protector
.endif

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--enable-64bit
.endif

.if ${PORT_OPTIONS:MDTRACE}
BROKEN=			DTRACE broken with gcc/clang - reported upstream
CONFIGURE_ARGS+=	--enable-dtrace
.else
CONFIGURE_ARGS+=	--disable-dtrace
.endif

.if ${PORT_OPTIONS:MREPCACHED}
PATCH_SITES+=		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	swills
PATCH_DIST_STRIP+=	-p1
PATCHFILES+=		repcached-2.3.1-${PORTVERSION}.patch.gz
CONFIGURE_ARGS+=	--enable-replication
.endif

.if ${PORT_OPTIONS:MSASL} && !defined(WITHOUT_SASL)
LIB_DEPENDS+=		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-sasl
CFLAGS+=		-I${LOCALBASE}/include
CPPFLAGS+=		${CFLAGS}
LDFLAGS+=		-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-sasl
.endif

post-configure:
	@${REINPLACE_CMD} -e 's#doc/memcached.1##' ${WRKSRC}/Makefile

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/memcached-tool ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

regression-test: test
test: build
	${MAKE} -C ${WRKSRC} test

.include <bsd.port.post.mk>
