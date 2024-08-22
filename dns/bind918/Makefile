# pkg-help formatted with fmt 59 63

PORTNAME=	bind
DISTVERSION=	9.18.29
.if defined(BIND_TOOLS_SLAVE)
# dns/bind-tools here
PORTREVISION=	0
.else
# dns/bind918 here
PORTREVISION=	0
.endif
CATEGORIES=	dns net
MASTER_SITES=	ISC/bind9/${DISTVERSION}
.if defined(BIND_TOOLS_SLAVE)
PKGNAMESUFFIX=	-tools
.else
PKGNAMESUFFIX=	918
.endif

MAINTAINER=	mat@FreeBSD.org
WWW=		https://www.isc.org/bind/
.if defined(BIND_TOOLS_SLAVE)
COMMENT=	Command line tools from BIND: delv, dig, host, nslookup...
.else
COMMENT=	BIND DNS suite with updated DNSSEC and DNS64
.endif

# Uncomment when bind920 comes of age. +3 years if ESV, +1year otherwise, see
# https://kb.isc.org/docs/aa-00896
# DEPRECATED=	End of life, please migrate to a newer version of BIND9
# EXPIRATION_DATE=	2023-12-31

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuv.so:devel/libuv \
		libnghttp2.so:www/libnghttp2 \
		libxml2.so:textproc/libxml2

.if !defined(BIND_TOOLS_SLAVE)
RUN_DEPENDS=	bind-tools>0:dns/bind-tools
.endif

USES=		autoreconf compiler:c11 cpe libedit libtool pkgconfig ssl tar:xz

CPE_VENDOR=	isc
CPE_VERSION=	${DISTVERSION:C/-.*//}
.if ${DISTVERSION:M*-*}
CPE_UPDATE=	${DISTVERSION:C/.*-//:tl}
.endif

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-linux-caps \
		--localstatedir=/var \
		--sysconfdir=${ETCDIR} \
		--with-dlopen=yes \
		--with-libxml2 \
		--with-openssl=${OPENSSLBASE} \
		--enable-dnsrps \
		--with-readline=libedit
CONFIGURE_ENV=	READLINE_CFLAGS="-L${LOCALBASE}/lib"
ETCDIR=		${PREFIX}/etc/namedb

.if defined(BIND_TOOLS_SLAVE)
EXTRA_PATCHES=		${PATCHDIR}/extrapatch-bind-tools
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/bind-tools
.else
USE_RC_SUBR=		named
SUB_FILES=		named.conf pkg-message
EXTRA_PATCHES=		${PATCHDIR}/extrapatch-no-bind-tools

PORTDOCS=	*

CONFLICTS=	bind916 bind9-devel
.endif	# BIND_TOOLS_SLAVE

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFAULT=	GSSAPI_NONE IDN JSON LMDB \
			TCP_FASTOPEN DNSTAP
OPTIONS_DEFINE=		DNSTAP DOCS FIXED_RRSET GEOIP IDN JSON LARGE_FILE LMDB \
			OVERRIDECACHE QUERYTRACE \
			START_LATE TCP_FASTOPEN

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

.if defined(BIND_TOOLS_SLAVE)
OPTIONS_EXCLUDE=	DOCS GEOIP LMDB \
			OVERRIDECACHE QUERYTRACE START_LATE \
			TCP_FASTOPEN
.endif	# BIND_TOOLS_SLAVE

OPTIONS_SUB=	yes

DNSTAP_DESC=		Provides fast passive logging of DNS messages
FIXED_RRSET_DESC=	Enable fixed rrset ordering
GSSAPI_BASE_DESC=	Using Heimdal in base (nsupdate is broken)
GSSAPI_HEIMDAL_DESC=	Using security/heimdal (nsupdate is broken)
GSSAPI_MIT_DESC=	Using security/krb5
GSSAPI_NONE_DESC=	Disable
LARGE_FILE_DESC=	64-bit file support
LMDB_DESC=		Use LMDB for zone management
OVERRIDECACHE_DESC=	Use the override-cache patch
QUERYTRACE_DESC=	Enable the very verbose query tracelogging
START_LATE_DESC=	Start BIND late in the boot process (see help)
TCP_FASTOPEN_DESC=	RFC 7413 support

DOCS_ALL_TARGET=	all html
DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
DOCS_USES=	gmake python:env

DNSTAP_CONFIGURE_ENABLE=	dnstap
DNSTAP_LIB_DEPENDS=		libfstrm.so:devel/fstrm \
				libprotobuf-c.so:devel/protobuf-c

FIXED_RRSET_CONFIGURE_ENABLE=	fixed-rrset

GEOIP_CONFIGURE_ENABLE=	geoip
GEOIP_CONFIGURE_WITH=	maxminddb
GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

GSSAPI_BASE_CONFIGURE_ON=	--with-gssapi="${KRB5CONFIG}" \
				${GSSAPI_CONFIGURE_ARGS}
GSSAPI_BASE_USES=		gssapi

GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-gssapi="${KRB5CONFIG}" \
				${GSSAPI_CONFIGURE_ARGS}
GSSAPI_HEIMDAL_USES=		gssapi:heimdal

GSSAPI_MIT_CONFIGURE_ON=	--with-gssapi="${KRB5CONFIG}" \
				${GSSAPI_CONFIGURE_ARGS}
GSSAPI_MIT_USES=		gssapi:mit

GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi

IDN_CONFIGURE_OFF=	--without-libidn2
IDN_CONFIGURE_ON=	${ICONV_CONFIGURE_BASE} \
			--with-libidn2=${LOCALBASE}
IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2
IDN_USES=		iconv

JSON_CONFIGURE_WITH=	json-c
JSON_LIB_DEPENDS=	libjson-c.so:devel/json-c
JSON_LDFLAGS=		-L${LOCALBASE}/lib -ljson-c

LARGE_FILE_CONFIGURE_ENABLE=	largefile

LMDB_CONFIGURE_WITH=	lmdb=${LOCALBASE}
LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb

OVERRIDECACHE_EXTRA_PATCHES=	${FILESDIR}/extrapatch-bind-min-override-ttl

QUERYTRACE_CONFIGURE_ENABLE=	querytrace

START_LATE_SUB_LIST=		NAMED_BEFORE="LOGIN" \
				NAMED_REQUIRE="SERVERS cleanvar"
START_LATE_SUB_LIST_OFF=	NAMED_BEFORE="SERVERS" \
				NAMED_REQUIRE="NETWORKING ldconfig syslogd"

TCP_FASTOPEN_CONFIGURE_ENABLE=	tcp-fastopen

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-developer \
			--enable-symtable
USES+=			perl5
USE_PERL5=		build
BUILD_DEPENDS+=		cmocka>0:sysutils/cmocka
.endif

.if !${PORT_OPTIONS:MDOCS}
CONFIGURE_ENV+=		ac_cv_path_SPHINX_BUILD=
.endif

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
SUB_LIST+=	ENGINES=/usr/lib/engines
.else
SUB_LIST+=	ENGINES=${LOCALBASE}/lib/engines
.endif

post-patch:
.for FILE in check/named-checkconf.rst named/named.rst nsupdate/nsupdate.rst \
	rndc/rndc.rst
	@${REINPLACE_CMD} -e 's#/etc/named.conf#${ETCDIR}/named.conf#g' \
		-e 's#/etc/rndc.conf#${ETCDIR}/rndc.conf#g' \
		-e "s#/var\/run\/named\/named.pid#/var/run/named/pid#" \
		${WRKSRC}/bin/${FILE}
.endfor

.if !defined(BIND_TOOLS_SLAVE)
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mtree
	${MKDIR} ${STAGEDIR}${ETCDIR}
.  for i in dynamic primary secondary working
	@${MKDIR} ${STAGEDIR}${ETCDIR}/$i
.  endfor
	${INSTALL_DATA} ${WRKDIR}/named.conf ${STAGEDIR}${ETCDIR}/named.conf.sample
	${INSTALL_DATA} ${FILESDIR}/named.root ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/empty.db ${STAGEDIR}${ETCDIR}/primary
	${INSTALL_DATA} ${FILESDIR}/localhost-forward.db ${STAGEDIR}${ETCDIR}/primary
	${INSTALL_DATA} ${FILESDIR}/localhost-reverse.db ${STAGEDIR}${ETCDIR}/primary
	${INSTALL_DATA} ${FILESDIR}/BIND.chroot.dist ${STAGEDIR}${PREFIX}/etc/mtree/BIND.chroot.dist.sample
	${INSTALL_DATA} ${FILESDIR}/BIND.chroot.local.dist ${STAGEDIR}${PREFIX}/etc/mtree/BIND.chroot.local.dist.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/CHANGES* \
		${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/arm/_build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/arm
.else

do-install:
	for dir in bin lib doc/man; do \
		(cd ${INSTALL_WRKSRC}/$$dir && ${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}) ; \
	done
	@${RM} -r ${STAGEDIR}${PREFIX}/include

.endif	# BIND_TOOLS_SLAVE

.include <bsd.port.post.mk>
