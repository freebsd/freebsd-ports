# Created by: Sergey Matveychuk <sem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unbound
PORTVERSION=	1.5.9
CATEGORIES=	dns
MASTER_SITES=	http://unbound.net/downloads/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Validating, recursive, and caching DNS resolver

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		autoreconf cpe libtool
CPE_VENDOR=	nlnetlabs
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-ssl=${OPENSSLBASE} --with-libexpat=${LOCALBASE}
USE_LDCONFIG=	yes

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

.include <bsd.port.options.mk>

LIB_DEPENDS+=	libexpat.so:textproc/expat2 \
		libldns.so:dns/ldns

STRIP_FILES=	.libs/libunbound.so unbound-checkconf unbound \
		unbound-control .libs/unbound-host .libs/unbound-anchor

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python:2
CONFIGURE_ARGS+=--with-pyunbound=yes --with-pythonmodule=yes LDFLAGS="-L${LOCALBASE}/lib"
BUILD_DEPENDS+=	swig:devel/swig13
STRIP_FILES+=	.libs/_unbound.so
.endif

.if ${PORT_OPTIONS:MGOST}
. if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000015
WITH_OPENSSL_PORT=	yes
. endif
DEPENDS_ARGS+=	WITH_GOST=yes
.else
CONFIGURE_ARGS+=--disable-gost
.endif

.if ${PORT_OPTIONS:MECDSA}
DEPENDS_ARGS+=	WITH_ECDSA=yes
.else
CONFIGURE_ARGS+=--disable-ecdsa
.endif

.if ${PORT_OPTIONS:MDNSTAP}
CONFIGURE_ARGS+=--enable-dnstap
LIB_DEPENDS+=	libprotobuf-c.so:devel/protobuf-c
LIB_DEPENDS+=	libfstrm.so:devel/fstrm
.endif

.if ${PORT_OPTIONS:MMUNIN_PLUGIN}
SUB_FILES+=	pkg-message
MUNIN_PLUGIN_ALL=	hits queue memory by_type by_class by_opcode by_rcode \
		by_flags histogram
.endif

.if ${PORT_OPTIONS:MLIBEVENT}
LIB_DEPENDS+=	libevent.so:devel/libevent2
USES+=		pkgconfig
CONFIGURE_ARGS+=--with-libevent
CPPFLAGS+=	$$(pkg-config libevent --cflags-only-I)
LDFLAGS+=	$$(pkg-config libevent --libs-only-L)
.else
CONFIGURE_ARGS+=--with-libevent=no
.endif

.if empty(PORT_OPTIONS:MTHREADS)
CONFIGURE_ARGS+=--without-pthreads
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
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/munin/plugins
	@${INSTALL_SCRIPT} ${WRKDIR}/unbound-${PORTVERSION}/contrib/unbound_munin_ \
		${STAGEDIR}${PREFIX}/share/munin/plugins/
	@for i in ${MUNIN_PLUGIN_ALL}; do \
		${LN} -fs ${PREFIX}/share/munin/plugins/unbound_munin_ \
			${STAGEDIR}${PREFIX}/etc/munin/plugins/unbound_munin_$$i; \
	done
	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================="
	@${CAT} ${WRKDIR}/pkg-message
	@${ECHO_MSG} "============================================================="

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

regression-test: build
	(cd ${WRKSRC} && ${MAKE} test)

.include <bsd.port.mk>
