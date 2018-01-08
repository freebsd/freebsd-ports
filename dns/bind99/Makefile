# $FreeBSD$
# pkg-help formatted with fmt 59 63

PORTNAME=	bind
PORTVERSION=	${ISCVERSION:S/-P/P/:S/b/.b/:S/a/.a/:S/rc/.rc/}
PORTREVISION=	5
CATEGORIES=	dns net ipv6
MASTER_SITES=	ISC/bind9/${ISCVERSION}
PKGNAMESUFFIX=	99
DISTNAME=	${PORTNAME}-${ISCVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	BIND DNS suite with updated DNSSEC and DNS64

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

DEPRECATED=	Going out of support, please migrate to dns/bind911
EXPIRATION_DATE=	2018-06-30

# ISC releases things like 9.8.0-P1, which our versioning doesn't like
ISCVERSION=	9.9.11

USES=	cpe libedit

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

CONFLICTS=	bind-tools bind9-devel bind910 bind911

SUB_FILES=	pkg-message named.conf
USE_RC_SUBR=	named

MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	*

OPTIONS_DEFAULT=	SSL THREADS SIGCHASE IDN GSSAPI_NONE RRL DLZ_FILESYSTEM \
			RPZ_NSIP RPZ_NSDNAME PYTHON
OPTIONS_DEFINE=		SSL IDN LARGE_FILE FIXED_RRSET SIGCHASE \
			IPV6 THREADS FILTER_AAAA GOST PYTHON START_LATE MINCACHE \
			RPZ_NSIP RPZ_NSDNAME RRL DOCS NEWSTATS \
			PORTREVISION FETCHLIMIT QUERYTRACE
OPTIONS_GROUP=		DLZ
OPTIONS_GROUP_DLZ=	DLZ_POSTGRESQL DLZ_MYSQL DLZ_BDB \
			DLZ_LDAP DLZ_FILESYSTEM DLZ_STUB
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

OPTIONS_SUB=	yes

DLZ_BDB_DESC=		DLZ BDB driver
DLZ_DESC=		Dynamically Loadable Zones
DLZ_FILESYSTEM_DESC=	DLZ filesystem driver
DLZ_LDAP_DESC=		DLZ LDAP driver
DLZ_MYSQL_DESC=		DLZ MySQL driver (no threading)
DLZ_POSTGRESQL_DESC=	DLZ Postgres driver
DLZ_STUB_DESC=		DLZ stub driver
FETCHLIMIT_DESC=	Enable the query quotas for resolvers
FILTER_AAAA_DESC=	Enable filtering of AAAA records
FIXED_RRSET_DESC=	Enable fixed rrset ordering
GOST_DESC=		Enable GOST ciphers, needs SSL
GSSAPI_BASE_DESC=	${GSSAPI_DESC} (Heimdal in base)
GSSAPI_HEIMDAL_DESC=	${GSSAPI_DESC} (security/heimdal)
GSSAPI_MIT_DESC=	${GSSAPI_DESC} (security/krb5)
GSSAPI_NONE_DESC=	No ${GSSAPI_DESC}
LARGE_FILE_DESC=	64-bit file support
MINCACHE_DESC=		Use the mincachettl patch
NEWSTATS_DESC=		Enable alternate xml statistics channel format
PORTREVISION_DESC=	Show PORTREVISION in the version string
PYTHON_DESC=		Build with Python utilities
QUERYTRACE_DESC=	Enable the very verbose query tracelogging
RPZ_NSDNAME_DESC=	Enable RPZ NSDNAME policy records
RPZ_NSIP_DESC=		Enable RPZ NSIP trigger rules
RRL_DESC=		Response Rate Limiting
SIGCHASE_DESC=		dig/host/nslookup will do DNSSEC validation
SSL_DESC=		Build with OpenSSL (Required for DNSSEC)
START_LATE_DESC=	Start BIND late in the boot process (see help)

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

FETCHLIMIT_CONFIGURE_ENABLE=	fetchlimit

FILTER_AAAA_CONFIGURE_ENABLE=	filter-aaaa

FIXED_RRSET_CONFIGURE_ENABLE=	fixed-rrset

GOST_CONFIGURE_WITH=	gost

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

LARGE_FILE_CONFIGURE_ENABLE=	largefile

MINCACHE_EXTRA_PATCHES=	${FILESDIR}/extrapatch-bind-min-override-ttl

NEWSTATS_CONFIGURE_ENABLE=	newstats

PYTHON_CONFIGURE_WITH=	python=${PYTHON_CMD}
PYTHON_USES=	python

QUERYTRACE_CONFIGURE_ENABLE=	querytrace

RPZ_NSDNAME_CONFIGURE_ENABLE=	rpz-nsdname

RPZ_NSIP_CONFIGURE_ENABLE=	rpz-nsip

RRL_CONFIGURE_ENABLE=	rrl

SIGCHASE_CONFIGURE_ON=	STD_CDEFINES="-DDIG_SIGCHASE=1"

SSL_CONFIGURE_OFF=	--disable-openssl-version-check --without-openssl
SSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
SSL_USES=		ssl

START_LATE_SUB_LIST=	NAMED_REQUIRE="SERVERS cleanvar" \
			NAMED_BEFORE="LOGIN"
START_LATE_SUB_LIST_OFF=NAMED_REQUIRE="NETWORKING ldconfig syslogd" \
			NAMED_BEFORE="SERVERS"

THREADS_CONFIGURE_ENABLE=	threads

.include <bsd.port.pre.mk>

.if ( ${PORT_OPTIONS:MGOST} ) && ${SSL_DEFAULT} == base
BROKEN=	OpenSSL from the base system does not support GOST, add \
	DEFAULT_VERSIONS+=ssl=openssl to your /etc/make.conf and rebuild everything \
	that needs SSL.
.endif

post-patch:
.for FILE in check/named-checkconf.8 named/named.8 nsupdate/nsupdate.1 \
	rndc/rndc.8
	@${REINPLACE_CMD} -e 's#/etc/named.conf#${ETCDIR}/named.conf#g' \
		-e 's#/etc/rndc.conf#${ETCDIR}/rndc.conf#g' \
		-e "s#/var\/run\/named\/named.pid#/var/run/named/pid#" \
		${WRKSRC}/bin/${FILE}
.endfor

.if ${PORTREVISION:N0}
post-patch-PORTREVISION-on:
	@${REINPLACE_CMD} -e '/EXTENSIONS/s#=$$#=_${PORTREVISION}#' \
		${WRKSRC}/version
.endif

post-configure:
	@${REINPLACE_CMD} -e '/^SO_LDFLAGS/s/-Wl,-rpath,/-rpath /' ${WRKSRC}/bin/tests/system/dlzexternal/Makefile

post-install:
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
	${INSTALL_DATA} ${FILESDIR}/BIND.chroot.dist ${STAGEDIR}${PREFIX}/etc/mtree/BIND.chroot.dist.sample
	${INSTALL_DATA} ${FILESDIR}/BIND.chroot.local.dist ${STAGEDIR}${PREFIX}/etc/mtree/BIND.chroot.local.dist.sample
	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf \
		${STAGEDIR}${ETCDIR}/rndc.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/*.html ${STAGEDIR}${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/FAQ* \
		${WRKSRC}/HISTORY* ${WRKSRC}/README* ${STAGEDIR}${DOCSDIR}

# Can't use USE_PYTHON=autoplist
post-install-PYTHON-on:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -type f | ${SED} -e 's|${STAGEDIR}||' >> ${TMPPLIST}

.include <bsd.port.post.mk>
