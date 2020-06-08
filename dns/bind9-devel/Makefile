# $FreeBSD$
# pkg-help formatted with fmt 59 63

PORTNAME=	bind
PORTVERSION=	${ISCVERSION:S/-P/P/:S/b/.b/:S/a/.a/:S/rc/.rc/}
.if defined(BIND_TOOLS_SLAVE)
# dns/bind-tools here
PORTREVISION=	0
.else
# XXX: correct version
# dns/bind9xx here
PORTREVISION=	0
.endif
CATEGORIES=	dns net
# XXX: put the ISC master_site
#MASTER_SITES=	ISC/bind9/${ISCVERSION}
MASTER_SITES=	LOCAL/mat/bind
.if defined(BIND_TOOLS_SLAVE)
PKGNAMESUFFIX=	-tools
.else
# XXX: correct SUFFIX.
PKGNAMESUFFIX=	9-devel
.endif
# XXX: correct DISTNAME.
#DISTNAME=	${PORTNAME}-${ISCVERSION}

MAINTAINER=	mat@FreeBSD.org
.if defined(BIND_TOOLS_SLAVE)
COMMENT=	Command line tools from BIND: delv, dig, host, nslookup...
.else
COMMENT=	BIND DNS suite with updated DNSSEC and DNS64
.endif

# Uncomment when bind9xx comes of age. +3 years if ESV, +1year otherwise, see
# https://kb.isc.org/docs/aa-00896
# DEPRECATED=	End of life, please migrate to a newer version of BIND9
# EXPIRATION_DATE=	XXX-12-31

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libuv.so:devel/libuv \
		libxml2.so:textproc/libxml2
.if !defined(BIND_TOOLS_SLAVE)
RUN_DEPENDS=	bind-tools>0:dns/bind-tools
.endif

# XXX: remove tar:bz2
USES=		autoreconf compiler:c11 cpe libedit libtool pkgconfig ssl tar:bz2
# ISC releases things like 9.8.0-P1, which our versioning doesn't like
ISCVERSION=	9.17.0a0.2020.06.06
# XXX: Remove gitlab
USE_GITLAB=	yes
GL_SITE=	https://gitlab.isc.org
GL_ACCOUNT=	isc-projects
GL_PROJECT=	bind9
GL_COMMIT=	d95951729025a8775a8a85d61a76fb5389a71adc

CPE_VENDOR=	isc
CPE_VERSION=	${ISCVERSION:C/-.*//}
.if ${ISCVERSION:M*-*}
CPE_UPDATE=	${ISCVERSION:C/.*-//:tl}
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-linux-caps \
		--disable-shared \
		--localstatedir=/var \
		--sysconfdir=${ETCDIR} \
		--with-dlopen=yes \
		--with-libxml2 \
		--with-openssl=${OPENSSLBASE} \
		--with-readline="-L${LOCALBASE}/lib -ledit"
ETCDIR=		${PREFIX}/etc/namedb

.if defined(BIND_TOOLS_SLAVE)
EXTRA_PATCHES=		${PATCHDIR}/extrapatch-bind-tools
.else
USE_RC_SUBR=		named
# XXX: remove the big warning about it being a development version from pkg-message
SUB_FILES=		named.conf pkg-message
EXTRA_PATCHES=		${PATCHDIR}/extrapatch-no-bind-tools

PORTDOCS=	*

# XXX: Add -devel
CONFLICTS=	bind911 bind912 bind913 bind914 bind916
.endif	# BIND_TOOLS_SLAVE

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFAULT=	DLZ_FILESYSTEM GSSAPI_NONE IDN JSON LMDB MANPAGES \
			SIGCHASE TCP_FASTOPEN
OPTIONS_DEFINE=		DNSTAP DOCS FIXED_RRSET GEOIP IDN JSON LARGE_FILE LMDB \
			MANPAGES OVERRIDECACHE PORTREVISION QUERYTRACE \
			SIGCHASE START_LATE TCP_FASTOPEN TUNING_LARGE

OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	NATIVE_PKCS11

OPTIONS_GROUP=		DLZ
OPTIONS_GROUP_DLZ=	DLZ_BDB DLZ_FILESYSTEM DLZ_LDAP DLZ_MYSQL \
			DLZ_POSTGRESQL DLZ_STUB

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

.if defined(BIND_TOOLS_SLAVE)
OPTIONS_EXCLUDE=	${OPTIONS_GROUP_DLZ} DNSTAP DOCS GEOIP LMDB \
			OVERRIDECACHE PORTREVISION QUERYTRACE START_LATE \
			TCP_FASTOPEN TUNING_LARGE
.endif	# BIND_TOOLS_SLAVE

OPTIONS_SUB=	yes

CRYPTO_DESC=		Choose which crypto engine to use
DLZ_BDB_DESC=		DLZ BDB driver
DLZ_DESC=		Dynamically Loadable Zones
DLZ_FILESYSTEM_DESC=	DLZ filesystem driver
DLZ_LDAP_DESC=		DLZ LDAP driver
DLZ_MYSQL_DESC=		DLZ MySQL driver (no threading)
DLZ_POSTGRESQL_DESC=	DLZ Postgres driver
DLZ_STUB_DESC=		DLZ stub driver
DNSTAP_DESC=		Provides fast passive logging of DNS messages
FIXED_RRSET_DESC=	Enable fixed rrset ordering
GSSAPI_BASE_DESC=	Using Heimdal in base
GSSAPI_HEIMDAL_DESC=	Using security/heimdal
GSSAPI_MIT_DESC=	Using security/krb5
GSSAPI_NONE_DESC=	Disable
LARGE_FILE_DESC=	64-bit file support
LMDB_DESC=		Use LMDB for zone management
OVERRIDECACHE_DESC=	Use the override-cache patch
NATIVE_PKCS11_DESC=	Use PKCS\#11 native API (**READ HELP**)
PORTREVISION_DESC=	Show PORTREVISION in the version string
QUERYTRACE_DESC=	Enable the very verbose query tracelogging
SIGCHASE_DESC=		dig/host/nslookup will do DNSSEC validation
START_LATE_DESC=	Start BIND late in the boot process (see help)
TCP_FASTOPEN_DESC=	RFC 7413 support
TUNING_LARGE_DESC=	Tune named for large systems (**READ HELP**)

DLZ_BDB_CONFIGURE_ON=	--with-dlz-bdb=yes
DLZ_BDB_USES=		bdb

DLZ_FILESYSTEM_CONFIGURE_ON=	--with-dlz-filesystem=yes

DLZ_LDAP_CONFIGURE_ON=	--with-dlz-ldap=yes
DLZ_LDAP_USE=		OPENLDAP=yes

DLZ_MYSQL_CONFIGURE_ON=	--with-dlz-mysql=yes
DLZ_MYSQL_USES=		mysql

DLZ_POSTGRESQL_CONFIGURE_ON=	--with-dlz-postgres=yes
DLZ_POSTGRESQL_USES=		pgsql

DLZ_STUB_CONFIGURE_ON=	--with-dlz-stub=yes

DNSTAP_CONFIGURE_ENABLE=	dnstap
DNSTAP_LIB_DEPENDS=		libfstrm.so:devel/fstrm \
				libprotobuf-c.so:devel/protobuf-c

FIXED_RRSET_CONFIGURE_ENABLE=	fixed-rrset

GEOIP_CONFIGURE_ENABLE=	geoip
GEOIP_CONFIGURE_WITH=	maxminddb
GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

GSSAPI_BASE_CONFIGURE_ON=	--with-gssapi="${KRB5CONFIG}"
GSSAPI_BASE_USES=		gssapi

GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-gssapi="${KRB5CONFIG}"
GSSAPI_HEIMDAL_USES=		gssapi:heimdal

GSSAPI_MIT_CONFIGURE_ON=	--with-gssapi="${KRB5CONFIG}"
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

MANPAGES_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

OVERRIDECACHE_EXTRA_PATCHES=	${FILESDIR}/extrapatch-bind-min-override-ttl

NATIVE_PKCS11_CONFIGURE_ENABLE=	native-pkcs11

QUERYTRACE_CONFIGURE_ENABLE=	querytrace

SIGCHASE_CONFIGURE_ON=	STD_CDEFINES="-DDIG_SIGCHASE=1"

START_LATE_SUB_LIST=		NAMED_BEFORE="LOGIN" \
				NAMED_REQUIRE="SERVERS cleanvar"
START_LATE_SUB_LIST_OFF=	NAMED_BEFORE="SERVERS" \
				NAMED_REQUIRE="NETWORKING ldconfig syslogd"

TCP_FASTOPEN_CONFIGURE_ENABLE=	tcp-fastopen

TUNING_LARGE_CONFIGURE_ON=	--with-tuning=large
TUNING_LARGE_CONFIGURE_OFF=	--with-tuning=default

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-developer \
			--enable-symtable
USES+=			perl5
USE_PERL5=		build
BUILD_DEPENDS+=		cmocka>0:sysutils/cmocka
.endif

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
SUB_LIST+=	ENGINES=/usr/lib/engines
.else
SUB_LIST+=	ENGINES=${LOCALBASE}/lib/engines
.endif

# XXX: Remove
post-extract:
	echo "SRCID=${GL_COMMIT}" > ${WRKSRC}/srcid

# XXX: Remove first REINPLACE_CMD
post-patch:
	@${REINPLACE_CMD} -e '/^m4_define.*bind_VERSION_EXTRA/s#)#-${GL_COMMIT})#' \
		${WRKSRC}/configure.ac
.for FILE in check/named-checkconf.rst named/named.rst nsupdate/nsupdate.rst \
	rndc/rndc.rst
	@${REINPLACE_CMD} -e 's#/etc/named.conf#${ETCDIR}/named.conf#g' \
		-e 's#/etc/rndc.conf#${ETCDIR}/rndc.conf#g' \
		-e "s#/var\/run\/named\/named.pid#/var/run/named/pid#" \
		${WRKSRC}/bin/${FILE}
.endfor

.if !defined(BIND_TOOLS_SLAVE)
.  if ${PORTREVISION:N0}
post-patch-PORTREVISION-on:
	@${REINPLACE_CMD} '/^m4_define.*bind_VERSION_EXTRA/s#)#_${PORTREVISION})#' \
		${WRKSRC}/configure.ac
.  endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mtree
	${MKDIR} ${STAGEDIR}${ETCDIR}
.  for i in dynamic master slave working
	@${MKDIR} ${STAGEDIR}${ETCDIR}/$i
.  endfor
	${INSTALL_DATA} ${WRKDIR}/named.conf ${STAGEDIR}${ETCDIR}/named.conf.sample
	${INSTALL_DATA} ${FILESDIR}/named.root ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/empty.db ${STAGEDIR}${ETCDIR}/master
	${INSTALL_DATA} ${FILESDIR}/localhost-forward.db ${STAGEDIR}${ETCDIR}/master
	${INSTALL_DATA} ${FILESDIR}/localhost-reverse.db ${STAGEDIR}${ETCDIR}/master
	${INSTALL_DATA} ${FILESDIR}/BIND.chroot.dist ${STAGEDIR}${PREFIX}/etc/mtree/BIND.chroot.dist.sample
	${INSTALL_DATA} ${FILESDIR}/BIND.chroot.local.dist ${STAGEDIR}${PREFIX}/etc/mtree/BIND.chroot.local.dist.sample
	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf \
		${STAGEDIR}${ETCDIR}/rndc.conf.sample
# FIXME: these are strange.
	@${RM} -rf ${STAGEDIR}/wrkdirs ${STAGEDIR}${PREFIX}/lib/bind

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES* ${WRKSRC}/HISTORY.md \
		${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.else

do-install:
	for dir in bin doc/man; do \
		(cd ${INSTALL_WRKSRC}/$$dir && ${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}) ; \
	done

.endif	# BIND_TOOLS_SLAVE

.include <bsd.port.post.mk>
