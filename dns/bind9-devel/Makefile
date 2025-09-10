# pkg-help formatted with fmt 59 63

PORTNAME=	bind
DISTVERSION=	9.21.12
.if defined(BIND_TOOLS_SLAVE)
# dns/bind-tools here
PORTREVISION=	0
.else
# XXX: correct version
# dns/bind9xx here
PORTREVISION=	0
.endif
CATEGORIES=	dns net
MASTER_SITES=	ISC/bind9/${DISTVERSION}
.if defined(BIND_TOOLS_SLAVE)
PKGNAMESUFFIX=	-tools
.else
# XXX: correct SUFFIX.
PKGNAMESUFFIX=	9-devel
.endif

MAINTAINER=	mat@FreeBSD.org
.if defined(BIND_TOOLS_SLAVE)
COMMENT=	Command line tools from BIND: delv, dig, host, nslookup...
.else
COMMENT=	BIND DNS suite with updated DNSSEC and DNS64
.endif
WWW=		https://www.isc.org/bind/

# Uncomment when bind9xx comes of age. +3 years if ESV, +1year otherwise, see
# https://kb.isc.org/docs/aa-00896
# DEPRECATED=	End of life, please migrate to a newer version of BIND9
# EXPIRATION_DATE=	XXX-12-31

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libnghttp2.so:www/libnghttp2 \
		liburcu.so:sysutils/liburcu \
		libuv.so:devel/libuv

.if !defined(BIND_TOOLS_SLAVE)
RUN_DEPENDS=	bind-tools>0:dns/bind-tools
.endif

USES=		compiler:c11 cpe gnome libedit libtool meson perl5 pkgconfig \
		ssl tar:xz

CPE_VENDOR=	isc
CPE_VERSION=	${DISTVERSION:C/-.*//}
.if ${DISTVERSION:M*-*}
CPE_UPDATE=	${DISTVERSION:C/.*-//:tl}
.endif

USE_PERL5=	build

.if !defined(BIND_TOOLS_SLAVE)
USE_RC_SUBR=	named
.endif # !BIND_TOOLS_SLAVE

MESON_ARGS=	--localstatedir=/var \
		--sysconfdir=${ETCDIR} \
		-Dcap=disabled \
		-Ddoh=enabled \
		-Djemalloc=disabled

MAKE_JOBS_UNSAFE=	yes

.if !defined(BIND_TOOLS_SLAVE)
# XXX: Add -devel
CONFLICTS=	bind9[0-9][0-9]
.endif # !BIND_TOOLS_SLAVE

ETCDIR=		${PREFIX}/etc/namedb

# FIXME: figure out why build fails if enabled
MESON_ARGS+=	-Dtracing=disabled

.if defined(BIND_TOOLS_SLAVE)
MESON_ARGS+=	-Dbind-tools=enabled \
		-Dlibdir=${PREFIX}/lib/bind-tools
.else
MESON_ARGS+=	-Dbind-tools=disabled
# XXX: remove the big warning about it being a development version from pkg-message
SUB_FILES=	named.conf pkg-message

PORTDOCS=	*
.endif # BIND_TOOLS_SLAVE

OPTIONS_DEFINE=		DNSTAP DOCS GEOIP IDN LMDB OVERRIDECACHE QUERYTRACE \
			START_LATE
OPTIONS_DEFAULT=	DNSTAP GSSAPI_NONE IDN LMDB STATS_JSON STATS_XML

OPTIONS_GROUP=		STATS
OPTIONS_GROUP_STATS=	STATS_JSON STATS_XML

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

.if defined(BIND_TOOLS_SLAVE)
OPTIONS_EXCLUDE=	DOCS GEOIP LMDB OVERRIDECACHE QUERYTRACE START_LATE \
			STATS_JSON STATS_XML
.endif # BIND_TOOLS_SLAVE

OPTIONS_SUB=	yes

DNSTAP_DESC=		Provides fast passive logging of DNS messages
GSSAPI_BASE_DESC=	Using Heimdal in base (nsupdate is broken)
GSSAPI_HEIMDAL_DESC=	Using security/heimdal (nsupdate is broken)
GSSAPI_MIT_DESC=	Using security/krb5
GSSAPI_NONE_DESC=	Disable
LMDB_DESC=		Use LMDB for zone management
OVERRIDECACHE_DESC=	Use the override-cache patch
QUERYTRACE_DESC=	Enable the very verbose query tracelogging
START_LATE_DESC=	Start BIND late in the boot process (see help)
STATS_DESC=		Statistics channels
STATS_JSON_DESC=	Enable JSON statistics channel
STATS_XML_DESC=		Enable XML statistics channel

DNSTAP_LIB_DEPENDS=	libfstrm.so:devel/fstrm \
			libprotobuf-c.so:devel/protobuf-c
DNSTAP_MESON_ENABLED=	dnstap

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
			sphinx-build:textproc/py-sphinx
DOCS_USES=		python:env
DOCS_MESON_ENABLED=	doc
DOCS_ALL_TARGET=	all arm

GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
GEOIP_MESON_ENABLED=	geoip

GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ENV=	${GSSAPI_CONFIGURE_ARGS} \
				KRB5_CONFIG="${KRB5CONFIG}"
GSSAPI_BASE_MESON_ON=		-Dgssapi=enabled

GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ENV=	${GSSAPI_CONFIGURE_ARGS} \
				KRB5_CONFIG="${KRB5CONFIG}"
GSSAPI_HEIMDAL_MESON_ON=	-Dgssapi=enabled

GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ENV=	${GSSAPI_CONFIGURE_ARGS} \
				KRB5_CONFIG="${KRB5CONFIG}"
GSSAPI_MIT_MESON_ON=		-Dgssapi=enabled

GSSAPI_NONE_MESON_ON=	-Dgssapi=disabled

IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2
IDN_USES=		iconv
IDN_MESON_ENABLED=	idn

LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_MESON_ENABLED=	lmdb

OVERRIDECACHE_EXTRA_PATCHES=	${FILESDIR}/extrapatch-bind-min-override-ttl

QUERYTRACE_MESON_ON=	-Dtrace-logging=query

START_LATE_SUB_LIST=		NAMED_BEFORE="LOGIN" \
				NAMED_REQUIRE="SERVERS cleanvar"
START_LATE_SUB_LIST_OFF=	NAMED_BEFORE="SERVERS" \
				NAMED_REQUIRE="NETWORKING ldconfig syslogd"

STATS_JSON_LIB_DEPENDS=		libjson-c.so:devel/json-c
STATS_JSON_MESON_ENABLED=	stats-json
STATS_JSON_LDFLAGS=		-L${LOCALBASE}/lib -ljson-c

STATS_XML_USE=			GNOME=libxml2
STATS_XML_MESON_ENABLED=	stats-xml

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
MESON_ARGS+=	-Ddeveloper=enabled
BUILD_DEPENDS+=	cmocka>0:sysutils/cmocka
.else
MESON_ARGS+=	-Dcmocka=disabled \
		-Ddeveloper=disabled
.endif

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
SUB_LIST+=	ENGINES=/usr/lib/engines
.else
SUB_LIST+=	ENGINES=${LOCALBASE}/lib/engines
.endif

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

	(for dir in ${WRKSRC}/lib/*/include; do \
		cd $$dir && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include '-name *.h'; \
	done)

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/_build/arm && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/arm
.endif # BIND_TOOLS_SLAVE

.include <bsd.port.post.mk>
