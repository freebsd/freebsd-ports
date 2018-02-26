# $FreeBSD$
# pkg-help formatted with fmt 59 63

PORTNAME=	bind
PORTVERSION=	${ISCVERSION:S/-P/P/:S/b/.b/:S/a/.a/:S/rc/.rc/}
.if defined(BIND_TOOLS_SLAVE)
# dns/bind-tools here
PORTREVISION=	0
.else
# dns/bind9xx here
PORTREVISION=	0
.endif
CATEGORIES=	dns net ipv6
MASTER_SITES=	LOCAL/mat/bind \
		https://gitlab.isc.org/isc-projects/bind9/repository/${HASH}/archive.tar.bz2?d/
.if defined(BIND_TOOLS_SLAVE)
PKGNAMESUFFIX=	-tools
.else
PKGNAMESUFFIX=	9-devel
.endif
DISTNAME=	${PORTNAME}9-${HASH}-${HASH}

MAINTAINER=	mat@FreeBSD.org
.if defined(BIND_TOOLS_SLAVE)
COMMENT=	Command line tools from BIND: delv, dig, host, nslookup...
.else
COMMENT=	BIND DNS suite with updated DNSSEC and DNS64
.endif

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

# ISC releases things like 9.8.0-P1, which our versioning doesn't like
ISCVERSION=	9.13.0a0.2018.02.26
HASH=		e1d6c9a6631f2db967d1a6331b5a177b78e08b89

USES=	cpe libedit tar:bz2

CPE_VENDOR=	isc
CPE_VERSION=	${ISCVERSION:C/-.*//}
.if ${ISCVERSION:M*-*}
CPE_UPDATE=	${ISCVERSION:C/.*-//:tl}
.endif

LIB_DEPENDS=	libxml2.so:textproc/libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps \
		--disable-symtable \
		--with-randomdev=/dev/random \
		--with-libxml2=${LOCALBASE} \
		--with-readline="-L${LOCALBASE}/lib -ledit" \
		--with-dlopen=yes \
		--sysconfdir=${ETCDIR}
ETCDIR=		${PREFIX}/etc/namedb

CONFLICTS=	bind99 bind910 bind911 bind912

.if defined(BIND_TOOLS_SLAVE)
CONFIGURE_ARGS+=	--disable-shared
CONFLICTS+=		bind9-devel
.else
USE_RC_SUBR=	named
SUB_FILES=	pkg-message named.conf
CONFLICTS+=		bind-tools
.endif	# BIND_TOOLS_SLAVE

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

OPTIONS_DEFAULT=	SSL THREADS SIGCHASE IDN GSSAPI_NONE JSON PYTHON
OPTIONS_DEFINE=		IDN LARGE_FILE PYTHON JSON \
			FIXED_RRSET SIGCHASE IPV6 THREADS

OPTIONS_RADIO=	CRYPTO GOSTDEF
OPTIONS_RADIO_CRYPTO=	SSL NATIVE_PKCS11
OPTIONS_RADIO_GOSTDEF=	GOST GOST_ASN1

.if !defined(BIND_TOOLS_SLAVE)
OPTIONS_DEFAULT+=	DLZ_FILESYSTEM LMDB RPZ_NSDNAME RPZ_NSIP TCP_FASTOPEN
OPTIONS_DEFINE+=	RPZ_NSIP RPZ_NSDNAME DOCS GEOIP \
			MINCACHE PORTREVISION QUERYTRACE LMDB DNSTAP \
			START_LATE TUNING_LARGE TCP_FASTOPEN
OPTIONS_GROUP=		DLZ
OPTIONS_GROUP_DLZ=	DLZ_POSTGRESQL DLZ_MYSQL DLZ_BDB \
			DLZ_LDAP DLZ_FILESYSTEM DLZ_STUB
.endif	# BIND_TOOLS_SLAVE
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

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
GEOIP_DESC=		Allow geographically based ACL.
GOSTDEF_DESC=		Enable GOST ciphers, needs SSL
GOST_ASN1_DESC=		GOST using ASN.1
GOST_DESC=		GOST raw keys (new default)
GSSAPI_BASE_DESC=	Using Heimdal in base
GSSAPI_HEIMDAL_DESC=	Using security/heimdal
GSSAPI_MIT_DESC=	Using security/krb5
GSSAPI_NONE_DESC=	Disable
LARGE_FILE_DESC=	64-bit file support
LMDB_DESC=		Use LMDB for zone management
MINCACHE_DESC=		Use the mincachettl patch
NATIVE_PKCS11_DESC=	Use PKCS\#11 native API (**READ HELP**)
PORTREVISION_DESC=	Show PORTREVISION in the version string
PYTHON_DESC=		Build with Python utilities
QUERYTRACE_DESC=	Enable the very verbose query tracelogging
RPZ_NSDNAME_DESC=	Enable RPZ NSDNAME policy records
RPZ_NSIP_DESC=		Enable RPZ NSIP trigger rules
SIGCHASE_DESC=		dig/host/nslookup will do DNSSEC validation
SSL_DESC=		Build with OpenSSL (Required for DNSSEC)
START_LATE_DESC=	Start BIND late in the boot process (see help)
TCP_FASTOPEN_DESC=	RFC 7413 support
TUNING_LARGE_DESC=	Tune named for large systems (**READ HELP**)

DLZ_BDB_CONFIGURE_ON=	--with-dlz-bdb=yes
DLZ_BDB_USES=		bdb

DLZ_FILESYSTEM_CONFIGURE_ON=	--with-dlz-filesystem=yes

DLZ_LDAP_CONFIGURE_ON=	--with-dlz-ldap=yes
DLZ_LDAP_USE=		openldap=yes

DLZ_MYSQL_CONFIGURE_ON=	--with-dlz-mysql=yes
DLZ_MYSQL_PREVENTS=	THREADS
DLZ_MYSQL_USES=		mysql

DLZ_POSTGRESQL_CONFIGURE_ON=	--with-dlz-postgres=yes
DLZ_POSTGRESQL_USES=		pgsql

DLZ_STUB_CONFIGURE_ON=	--with-dlz-stub=yes

DNSTAP_CONFIGURE_ENABLE=	dnstap
DNSTAP_IMPLIES=		THREADS
DNSTAP_LIB_DEPENDS=	libfstrm.so:devel/fstrm \
			libprotobuf-c.so:devel/protobuf-c

FIXED_RRSET_CONFIGURE_ENABLE=	fixed-rrset

GEOIP_CONFIGURE_WITH=	geoip
GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP

GOST_ASN1_CONFIGURE_ON=	--with-gost=asn1

GOST_CONFIGURE_ON=	--with-gost

GSSAPI_BASE_CONFIGURE_ON= \
	--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_BASE_USES=	gssapi

GSSAPI_HEIMDAL_CONFIGURE_ON= \
	--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_HEIMDAL_USES=	gssapi:heimdal

GSSAPI_MIT_CONFIGURE_ON= \
	--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_MIT_USES=	gssapi:mit

GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi

IDN_CONFIGURE_OFF=	--without-idn
IDN_CONFIGURE_ON=	--with-idn=${LOCALBASE} ${ICONV_CONFIGURE_BASE}
IDN_LIB_DEPENDS=	libidnkit.so:dns/idnkit
IDN_USES=		iconv

IPV6_CONFIGURE_ENABLE=	ipv6

JSON_CONFIGURE_WITH=	libjson
JSON_LIB_DEPENDS=	libjson-c.so:devel/json-c

LARGE_FILE_CONFIGURE_ENABLE=	largefile

LMDB_CONFIGURE_WITH=	lmdb
LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb

MINCACHE_EXTRA_PATCHES=	${FILESDIR}/extrapatch-bind-min-override-ttl

NATIVE_PKCS11_CONFIGURE_ENABLE=	native-pkcs11
NATIVE_PKCS11_IMPLIES=	THREADS

PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply
PYTHON_CONFIGURE_WITH=	python=${PYTHON_CMD}
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply
PYTHON_USES=	python

QUERYTRACE_CONFIGURE_ENABLE=	querytrace

RPZ_NSDNAME_CONFIGURE_ENABLE=	rpz-nsdname

RPZ_NSIP_CONFIGURE_ENABLE=	rpz-nsip

SIGCHASE_CONFIGURE_ON=	STD_CDEFINES="-DDIG_SIGCHASE=1"

SSL_CONFIGURE_OFF=	--disable-openssl-version-check --without-openssl
SSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
SSL_USES=		ssl

START_LATE_SUB_LIST=	NAMED_REQUIRE="SERVERS cleanvar" \
			NAMED_BEFORE="LOGIN"
START_LATE_SUB_LIST_OFF=NAMED_REQUIRE="NETWORKING ldconfig syslogd" \
			NAMED_BEFORE="SERVERS"

TCP_FASTOPEN_CONFIGURE_ENABLE=	tcp-fastopen

THREADS_CONFIGURE_ENABLE=	threads

TUNING_LARGE_IMPLIES=	THREADS
TUNING_LARGE_CONFIGURE_ON=	--with-tuning=large
TUNING_LARGE_CONFIGURE_OFF=	--with-tuning=default

.include <bsd.port.pre.mk>

.if !${PORT_OPTIONS:MGOST} && !${PORT_OPTIONS:MGOST_ASN1}
CONFIGURE_ARGS+=	--without-gost
.endif

.if ( ${PORT_OPTIONS:MGOST} || ${PORT_OPTIONS:MGOST_ASN1} ) && ${SSL_DEFAULT} == base
BROKEN=	OpenSSL from the base system does not support GOST, add \
	DEFAULT_VERSIONS+=ssl=openssl to your /etc/make.conf and rebuild everything \
	that needs SSL.
.endif

post-extract:
	echo "SRCID=${HASH}" > ${WRKSRC}/srcid

post-patch:
	@${REINPLACE_CMD} -e '/RELEASETYPE=/s#$$#-${HASH}#' \
		${WRKSRC}/version
.if defined(BIND_TOOLS_SLAVE)
	@${REINPLACE_CMD} -e 's#^SUBDIRS.*#SUBDIRS = lib bin#' \
		-e 's#isc-config.sh installdirs#installdirs#' \
		-e 's#.*INSTALL.*isc-config.*##' \
		-e 's#.*INSTALL.*bind.keys.*##' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's#^SUBDIRS.*#SUBDIRS = delv dig dnssec tools nsupdate \\#' \
		-e 's#^	.*check confgen ##' \
		${WRKSRC}/bin/Makefile.in
.else
.  for FILE in check/named-checkconf.8 named/named.8 nsupdate/nsupdate.1 \
	rndc/rndc.8
	@${REINPLACE_CMD} -e 's#/etc/named.conf#${ETCDIR}/named.conf#g' \
		-e 's#/etc/rndc.conf#${ETCDIR}/rndc.conf#g' \
		-e "s#/var\/run\/named\/named.pid#/var/run/named/pid#" \
		${WRKSRC}/bin/${FILE}
.  endfor
.endif

.if !defined(BIND_TOOLS_SLAVE)
.  if ${PORTREVISION:N0}
post-patch-PORTREVISION-on:
	@${REINPLACE_CMD} -e '/EXTENSIONS/s#=$$#=_${PORTREVISION}#' \
		${WRKSRC}/version
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

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/*.html ${STAGEDIR}${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES* ${WRKSRC}/HISTORY.md \
		${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.endif	# BIND_TOOLS_SLAVE

# Can't use USE_PYTHON=autoplist
post-install-PYTHON-on:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -type f | ${SED} -e 's|${STAGEDIR}||' >> ${TMPPLIST}

.include <bsd.port.post.mk>
