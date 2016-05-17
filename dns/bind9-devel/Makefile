# $FreeBSD$
# pkg-help formatted with fmt 59 63

PORTNAME=	bind
PORTVERSION=	${ISCVERSION:S/-P/P/:S/b/.b/}
PORTREVISION=	0
CATEGORIES=	dns net ipv6
MASTER_SITES=	LOCAL/mat/bind
#MASTER_SITES=	https://source.isc.org/cgi-bin/gitweb.cgi?p=bind9.git;a=snapshot;h=${HASH};sf=tgz;f=
PKGNAMESUFFIX=	9-devel
DISTNAME=	${PORTNAME}9-${HASH}

# Force the filename when fetched from the ISC gitweb.
FETCH_BEFORE_ARGS=	-o ${DISTFILES}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	BIND DNS suite with updated DNSSEC and DNS64

LICENSE=	ISCL

# ISC releases things like 9.8.0-P1, which our versioning doesn't like
ISCVERSION=	9.11.0.a20160517
HASH=		75167fb

MAKE_JOBS_UNSAFE=	yes

USES=	cpe libedit

CPE_VENDOR=	isc
CPE_VERSION=	${ISCVERSION:C/-.*//}
.if ${ISCVERSION:M*-*}
CPE_UPDATE=	${ISCVERSION:C/.*-//:tl}
.endif

LIB_DEPENDS=	libxml2.so:textproc/libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--localstatedir=/var --disable-linux-caps \
		--disable-symtable \
		--with-randomdev=/dev/random \
		--with-libxml2=${LOCALBASE} \
		--with-readline=-ledit \
		--sysconfdir=${ETCDIR}
ETCDIR=		${PREFIX}/etc/namedb

CONFLICTS+=	bind9*-9.[456789].* bind9*-sdb-9.[456789].*

SUB_FILES=	pkg-message

OPTIONS_DEFAULT=	IPV6 SSL THREADS SIGCHASE IDN GSSAPI_NONE
OPTIONS_DEFINE=		IDN LARGE_FILE PYTHON START_LATE \
			FIXED_RRSET SIGCHASE IPV6 THREADS FILTER_AAAA
OPTIONS_RADIO=	CRYPTO GOSTDEF
OPTIONS_RADIO_CRYPTO=	SSL NATIVE_PKCS11
OPTIONS_RADIO_GOSTDEF=	GOST GOST_ASN1

OPTIONS_DEFAULT+=	RRL
OPTIONS_DEFINE+=	LINKS RPZ_NSIP RPZ_NSDNAME RRL DOCS NEWSTATS GEOIP \
			MINCACHE PORTREVISION FETCHLIMIT QUERYTRACE
OPTIONS_GROUP=		DLZ
OPTIONS_GROUP_DLZ=	DLZ_POSTGRESQL DLZ_MYSQL DLZ_BDB \
			DLZ_LDAP DLZ_FILESYSTEM DLZ_STUB
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

OPTIONS_SUB=	yes

SSL_DESC=		Build with OpenSSL (Required for DNSSEC)
LARGE_FILE_DESC=	64-bit file support
FIXED_RRSET_DESC=	Enable fixed rrset ordering
SIGCHASE_DESC=		dig/host/nslookup will do DNSSEC validation
FILTER_AAAA_DESC=	Enable filtering of AAAA records
CRYPTO_DESC=		Choose which crypto engine to use
NATIVE_PKCS11_DESC=	Use PKCS\#11 native API (**READ HELP**)
GEOIP_DESC=		Allow geographically based ACL.
GOSTDEF_DESC=		Enable GOST ciphers, needs SSL (see help on 8 and 9)
GOST_DESC=		GOST raw keys (new default)
GOST_ASN1_DESC=		GOST using ASN.1
PYTHON_DESC=		Build with Python utilities
START_LATE_DESC=	Start BIND late in the boot process
MINCACHE_DESC=		Use the mincachettl patch
PORTREVISION_DESC=	Show PORTREVISION in the version string
FETCHLIMIT_DESC=	Enable the query quotas for resolvers
QUERYTRACE_DESC=	Enable the very verbose query tracelogging

LINKS_DESC=		Create conf file symlinks in ${PREFIX}
NEWSTATS_DESC=		Enable alternate xml statistics channel format
RPZ_NSIP_DESC=		Enable RPZ NSIP trigger rules
RPZ_NSDNAME_DESC=	Enable RPZ NSDNAME policy records
RRL_DESC=		Response Rate Limiting
DLZ_DESC=		Dynamically Loadable Zones
DLZ_POSTGRESQL_DESC=	DLZ Postgres driver
DLZ_MYSQL_DESC=		DLZ MySQL driver (no threading)
DLZ_BDB_DESC=		DLZ BDB driver
DLZ_LDAP_DESC=		DLZ LDAP driver
DLZ_FILESYSTEM_DESC=	DLZ filesystem driver
DLZ_STUB_DESC=		DLZ stub driver
GSSAPI_BASE_DESC=	Using Heimdal in base
GSSAPI_HEIMDAL_DESC=	Using security/heimdal
GSSAPI_MIT_DESC=	Using security/krb5
GSSAPI_NONE_DESC=	Disable
MINCACHE_EXTRA_PATCHES=	${FILESDIR}/extrapatch-bind-min-override-ttl
FETCHLIMIT_CONFIGURE_ENABLE=	fetchlimit
QUERYTRACE_CONFIGURE_ENABLE=	querytrace

SSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
SSL_USE=		openssl=yes
SSL_CONFIGURE_OFF=	--disable-openssl-version-check --without-openssl

NEWSTATS_CONFIGURE_ENABLE=	newstats

IDN_USES=		iconv
IDN_CONFIGURE_ON=	--with-idn=${LOCALBASE} ${ICONV_CONFIGURE_BASE}
IDN_LIB_DEPENDS=	libidnkit.so:dns/idnkit
IDN_CONFIGURE_OFF=	--without-idn

LARGE_FILE_CONFIGURE_ENABLE=	largefile

SIGCHASE_CONFIGURE_ON=	STD_CDEFINES="-DDIG_SIGCHASE=1"

IPV6_CONFIGURE_ENABLE=	ipv6

FILTER_AAAA_CONFIGURE_ENABLE=	filter-aaaa

NATIVE_PKCS11_CONFIGURE_ENABLE=	native-pkcs11

GEOIP_CONFIGURE_WITH=	geoip
GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP

GOST_CONFIGURE_ON=	--with-gost
GOST_ASN1_CONFIGURE_ON=	--with-gost=asn1

PYTHON_CONFIGURE_WITH=	python=${PYTHON_CMD}
PYTHON_USES=	python
PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply

DLZ_POSTGRESQL_CONFIGURE_ON=	--with-dlz-postgres=yes
DLZ_POSTGRESQL_USES=		pgsql

FIXED_RRSET_CONFIGURE_ENABLE=	fixed-rrset

RPZ_NSIP_CONFIGURE_ENABLE=	rpz-nsip

RPZ_NSDNAME_CONFIGURE_ENABLE=	rpz-nsdname

RRL_CONFIGURE_ENABLE=	rrl

DLZ_MYSQL_CONFIGURE_ON=	--with-dlz-mysql=yes
DLZ_MYSQL_USE=		mysql=yes

DLZ_BDB_CONFIGURE_ON=	--with-dlz-bdb=yes
DLZ_BDB_USE=		bdb=yes

DLZ_LDAP_CONFIGURE_ON=	--with-dlz-ldap=yes
DLZ_LDAP_USE=		openldap=yes

DLZ_FILESYSTEM_CONFIGURE_ON=	--with-dlz-filesystem=yes

DLZ_STUB_CONFIGURE_ON=	--with-dlz-stub=yes

START_LATE_SUB_LIST=	NAMED_REQUIRE="SERVERS cleanvar" \
			NAMED_BEFORE="LOGIN"
START_LATE_SUB_LIST_OFF=NAMED_REQUIRE="NETWORKING ldconfig syslogd" \
			NAMED_BEFORE="SERVERS"

GSSAPI_BASE_USES=	gssapi
GSSAPI_BASE_CONFIGURE_ON= \
	--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON= \
	--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_MIT_CONFIGURE_ON= \
	--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MGOST} && !${PORT_OPTIONS:MGOST_ASN1}
CONFIGURE_ARGS+=	--without-gost
.endif

.if !${PORT_OPTIONS:MLINKS}
PKGINSTALL=${NONEXISTENT}
.endif

.if ${PORT_OPTIONS:MTHREADS} && !${PORT_OPTIONS:MDLZ_MYSQL}
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if ${OPSYS} == DragonFly || (${OPSYS} == FreeBSD && ${OSVERSION} >= 1000100)
PKGINSTALL=	${NONEXISTENT}
PLIST_SUB+=	NOBASE="" BASE="@comment "
SUB_LIST+=	NOBASE="" BASE="@comment "
USE_RC_SUBR+=	named
SUB_FILES+=	named.conf
.else
PLIST_SUB+=	NOBASE="@comment " BASE=""
SUB_LIST+=	NOBASE="@comment " BASE=""
.endif

PKGDEINSTALL=	${PKGINSTALL}


PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ( ${PORT_OPTIONS:MGOST} || ${PORT_OPTIONS:MGOST_ASN1} ) && defined(WITH_OPENSSL_BASE)
BROKEN=	OpenSSL from the base system does not support GOST, add \
	WITH_OPENSSL_PORT=yes to your /etc/make.conf and rebuild everything \
	that needs SSL.
.endif

post-extract:
	echo "SRCID=${HASH}" > ${WRKSRC}/srcid

post-patch:
	@${REINPLACE_CMD} -e '/RELEASETYPE=/s#$$#-${HASH}#' \
		${WRKSRC}/version
	@${REINPLACE_CMD} -e 's|readline/readline.h|editline/readline.h|; \
		s|readline/history.h|histedit.h|' \
		${WRKSRC}/bin/dig/nslookup.c ${WRKSRC}/bin/nsupdate/nsupdate.c
.  for FILE in check/named-checkconf.8 named/named.8 nsupdate/nsupdate.1 \
	rndc/rndc.8
	@${REINPLACE_CMD} -e 's#/etc/named.conf#${ETCDIR}/named.conf#g' \
		-e 's#/etc/rndc.conf#${ETCDIR}/rndc.conf#g' \
		-e "s#/var\/run\/named\/named.pid#/var/run/named/pid#" \
		${WRKSRC}/bin/${FILE}
.  endfor

.if ${PORTREVISION:N0}
post-patch-PORTREVISION-on:
	@${REINPLACE_CMD} -e '/EXTENSIONS/s#=$$#=_${PORTREVISION}#' \
		${WRKSRC}/version
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/*.html ${STAGEDIR}${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/FAQ \
		${WRKSRC}/HISTORY ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.if ${OPSYS} == DragonFly || (${OPSYS} == FreeBSD && ${OSVERSION} >= 1000100)
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mtree
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for i in dynamic master slave working
	@${MKDIR} ${STAGEDIR}${ETCDIR}/$i
.endfor
	${INSTALL_DATA} ${WRKDIR}/named.conf ${STAGEDIR}${ETCDIR}/named.conf.sample
	${INSTALL_DATA} ${FILESDIR}/named.root ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/empty.db ${STAGEDIR}${ETCDIR}/master
	${INSTALL_DATA} ${FILESDIR}/localhost-forward.db ${STAGEDIR}${ETCDIR}/master
	${INSTALL_DATA} ${FILESDIR}/localhost-reverse.db ${STAGEDIR}${ETCDIR}/master
	${INSTALL_DATA} ${FILESDIR}/BIND.chroot.dist ${STAGEDIR}${PREFIX}/etc/mtree
	${INSTALL_DATA} ${FILESDIR}/BIND.chroot.local.dist ${STAGEDIR}${PREFIX}/etc/mtree
.endif
	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf \
		${STAGEDIR}${ETCDIR}/rndc.conf.sample

# Can't use USE_PYTHON=autoplist
post-install-PYTHON-on:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -type f | ${SED} -e 's|${STAGEDIR}||' >> ${TMPPLIST}

.include <bsd.port.post.mk>
