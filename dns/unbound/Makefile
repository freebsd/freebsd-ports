# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unbound
PORTVERSION=	1.6.0
CATEGORIES=	dns
MASTER_SITES=	http://unbound.net/downloads/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Validating, recursive, and caching DNS resolver

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libldns.so:dns/ldns

BROKEN_aarch64=	Fails to link: missing sbrk

USES=		autoreconf cpe libtool ssl
CPE_VENDOR=	nlnetlabs
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE} --with-libexpat=${LOCALBASE}
USE_LDCONFIG=	yes
TEST_TARGET=	test

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

USE_RC_SUBR=	unbound

PORTDOCS=	CREDITS Changelog FEATURES LICENSE README README.svn \
		README.tests TODO control_proto_spec.txt ietf67-design-02.odp \
		ietf67-design-02.pdf requirements.txt

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	THREADS PYTHON GOST ECDSA MUNIN_PLUGIN DOCS LIBEVENT FILTER_AAAA DNSTAP
OPTIONS_DEFAULT=THREADS ECDSA

LIBEVENT_DESC=	Build against libevent
GOST_DESC=	Enable GOST support (requires OpenSSL >= 1.0)
ECDSA_DESC=	Enable ECDSA (elliptic curve) support (OpenSSL >= 1.0)
MUNIN_PLUGIN_DESC=	Install Munin plugin
FILTER_AAAA_DESC=	Build with AAAA filter functionality (contrib)
DNSTAP_DESC=	Enable dnstap logging support

STRIP_FILES=	.libs/libunbound.so unbound-checkconf unbound \
		unbound-control .libs/unbound-host .libs/unbound-anchor

DNSTAP_CONFIGURE_ENABLE=dnstap
DNSTAP_LIB_DEPENDS=	libfstrm.so:devel/fstrm \
			libprotobuf-c.so:devel/protobuf-c
ECDSA_CONFIGURE_ENABLE=	ecdsa
ECDSA_VARS=		DEPENDS_ARGS+=WITH_ECDSA=yes
GOST_CONFIGURE_ENABLE=	gost
GOST_VARS=		DEPENDS_ARGS+=WITH_GOST=yes
LIBEVENT_CONFIGURE_WITH=libevent
LIBEVENT_CPPFLAGS+=	$$(pkg-config libevent --cflags-only-I)
LIBEVENT_LIB_DEPENDS=	libevent.so:devel/libevent2
LIBEVENT_LDFLAGS+=	$$(pkg-config libevent --libs-only-L)
LIBEVENT_USES=		pkgconfig
MUNIN_PLUGIN_SUB_FILES=	pkg-message
PYTHON_BUILD_DEPENDS=	swig:devel/swig13
PYTHON_CONFIGURE_ON=	--with-pyunbound=yes --with-pythonmodule=yes LDFLAGS="-L${LOCALBASE}/lib"
PYTHON_USES=		python:2
PYTHON_VARS=		STRIP_FILES+=.libs/_unbound.so
THREADS_CONFIGURE_WITH=	pthreads

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGOST}
. if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000015
WITH_OPENSSL_PORT=	yes
. endif
.endif

post-patch:
	@${RM} ${WRKSRC}/util/configlexer.c
	@${REINPLACE_CMD} -e 's|if test ! -e $$(DESTDIR)$$(configfile); then || ; \
		s|$$(configfile); fi|$$(configfile).sample|' \
		${WRKSRC}/Makefile.in

post-patch-FILTER_AAAA-on:
	${CAT} ${WRKSRC}/contrib/aaaa-filter-iterator.patch | ${PATCH} -d ${WRKSRC} -p1 -s

post-build:
	@for s in ${STRIP_FILES}; do ${STRIP_CMD} ${WRKSRC}/$$s; done

post-install-PYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_unbound.so

post-install-MUNIN_PLUGIN-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/munin/plugins
	${INSTALL_SCRIPT} ${WRKDIR}/unbound-${PORTVERSION}/contrib/unbound_munin_ \
		${STAGEDIR}${PREFIX}/share/munin/plugins/
	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================="
	@${CAT} ${WRKDIR}/pkg-message
	@${ECHO_MSG} "============================================================="

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
