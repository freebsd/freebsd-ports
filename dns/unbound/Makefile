PORTNAME=	unbound
DISTVERSION=	1.23.1
CATEGORIES=	dns
MASTER_SITES=	https://www.nlnetlabs.nl/downloads/unbound/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Validating, recursive, and caching DNS resolver
WWW=		https://www.nlnetlabs.nl/projects/unbound

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libnghttp2.so:www/libnghttp2

USES=		autoreconf cpe libtool pkgconfig ssl
CPE_VENDOR=	nlnetlabs
USE_LDCONFIG=	yes
USE_RC_SUBR=	unbound

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libexpat=${LOCALBASE} \
		--with-libnghttp2 \
		--with-ssl=${OPENSSLBASE}
TEST_TARGET=	test

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PORTDOCS=	CNAME-basedRedirectionDesignNotes.pdf CREDITS Changelog \
		FEATURES IP-BasedActions.pdf LICENSE README README.DNS64 \
		README.ipset.md README.svn README.tests TODO \
		control_proto_spec.txt example.conf ietf67-design-02.odp \
		ietf67-design-02.pdf requirements.txt

OPTIONS_DEFINE=		DEP-RSA1024 DNSCRYPT DNSTAP DOCS DYNLIB ECDSA EVAPI \
			FILTER_AAAA GOST HIREDIS LIBEVENT MUNIN_PLUGIN PYTHON \
			SUBNET TFOCL TFOSE THREADS
OPTIONS_DEFAULT=	DNSCRYPT DYNLIB ECDSA EVAPI GOST LIBEVENT THREADS
OPTIONS_SUB=		yes

DEP-RSA1024_DESC=	Deprecate the use of RSA 1024 keys
DNSCRYPT_DESC=		Enable dnscrypt support
DNSTAP_DESC=		Enable dnstap logging support
DYNLIB_DESC=		Enable support for dynamic (shared) 3rd-party libraries
ECDSA_DESC=		Enable ECDSA (elliptic curve) support (OpenSSL >= 1.0)
EVAPI_DESC=		Pluggable event based libunbound API support
FILTER_AAAA_DESC=	Build with AAAA filter functionality (contrib)
GOST_DESC=		Enable GOST support (requires OpenSSL >= 1.0)
HIREDIS_DESC=		Enable hiredis support for the cachedb module
LIBEVENT_DESC=		Build against libevent
MUNIN_PLUGIN_DESC=	Install Munin plugin
SUBNET_DESC=		Enable client subnet support
TFOCL_DESC=		Enable TCP Fast Open for client mode
TFOSE_DESC=		Enable TCP Fast Open for server mode

STRIP_FILES=	.libs/libunbound.so unbound-checkconf unbound unbound-control \
		.libs/unbound-host .libs/unbound-anchor

DEP-RSA1024_CONFIGURE_ON=	--with-deprecate-rsa-1024
DNSCRYPT_LIB_DEPENDS=		libsodium.so:security/libsodium
DNSCRYPT_CONFIGURE_ENABLE=	dnscrypt
DNSTAP_LIB_DEPENDS=		libfstrm.so:devel/fstrm \
				libprotobuf-c.so:devel/protobuf-c
DNSTAP_CONFIGURE_ENABLE=	dnstap
DYNLIB_CONFIGURE_ON=		--with-dynlibmodule
ECDSA_CONFIGURE_ENABLE=		ecdsa
ECDSA_VARS=			DEPENDS_ARGS+=WITH_ECDSA=yes
EVAPI_CONFIGURE_ENABLE=		event-api
GOST_CONFIGURE_ENABLE=		gost
GOST_VARS=			DEPENDS_ARGS+=WITH_GOST=yes
HIREDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
HIREDIS_CONFIGURE_ON=		--enable-cachedb \
				--with-libhiredis
LIBEVENT_LIB_DEPENDS=		libevent.so:devel/libevent
LIBEVENT_CONFIGURE_WITH=	libevent
LIBEVENT_CPPFLAGS+=		$$(pkg-config libevent --cflags-only-I)
LIBEVENT_LDFLAGS+=		$$(pkg-config libevent --libs-only-L)
MUNIN_PLUGIN_SUB_FILES=		pkg-message
PYTHON_BUILD_DEPENDS=		swig:devel/swig
PYTHON_USES=			python
PYTHON_CONFIGURE_ON=		--with-pythonmodule=yes \
				--with-pyunbound=yes \
				ac_cv_path_SWIG=${LOCALBASE}/bin/swig \
				LDFLAGS="-L${LOCALBASE}/lib"
PYTHON_VARS=			STRIP_FILES+=.libs/_unbound.so
SUBNET_CONFIGURE_ENABLE=	subnet
TFOCL_CONFIGURE_ENABLE=		tfo-client
TFOSE_CONFIGURE_ENABLE=		tfo-server
THREADS_CONFIGURE_WITH=		pthreads

post-patch:
	@${RM} ${WRKSRC}/util/configlexer.c
	@${REINPLACE_CMD} -e 's|if test ! -e "$$(DESTDIR)$$(configfile)"; then || ; \
		s|$$(configfile)"; fi|$$(configfile).sample"|' \
		${WRKSRC}/Makefile.in

post-patch-FILTER_AAAA-on:
	@${CAT} ${WRKSRC}/contrib/aaaa-filter-iterator.patch | \
		${PATCH} -d ${WRKSRC} -p1 -s

post-build:
	@for s in ${STRIP_FILES}; \
		do ${STRIP_CMD} ${WRKSRC}/$$s; \
		done

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} \
		${STAGEDIR}${DOCSDIR}

post-install-MUNIN_PLUGIN-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/munin/plugins
	${INSTALL_SCRIPT} ${WRKDIR}/unbound-${DISTVERSION}/contrib/unbound_munin_ \
		${STAGEDIR}${PREFIX}/share/munin/plugins/
	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================="
	@${CAT} ${WRKDIR}/pkg-message
	@${ECHO_MSG} "============================================================="

post-install-PYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_unbound.so

.include <bsd.port.mk>
