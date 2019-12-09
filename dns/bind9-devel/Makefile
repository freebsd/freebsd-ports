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

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libuv.so:devel/libuv
.if !defined(BIND_TOOLS_SLAVE)
RUN_DEPENDS=	bind-tools>0:dns/bind-tools
.endif

# XXX: remove tar:bz2
USES=	compiler:c11 cpe libedit pkgconfig ssl tar:bz2
# ISC releases things like 9.8.0-P1, which our versioning doesn't like
ISCVERSION=	9.15.6a0.2019.12.09
# XXX: Remove gitlab
USE_GITLAB=	yes
GL_SITE=	https://gitlab.isc.org
GL_ACCOUNT=	isc-projects
GL_PROJECT=	bind9
GL_COMMIT=	edd6a084f0588f3512f48def223f54b6fe75cef0

CPE_VENDOR=	isc
CPE_VERSION=	${ISCVERSION:C/-.*//}
.if ${ISCVERSION:M*-*}
CPE_UPDATE=	${ISCVERSION:C/.*-//:tl}
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps \
		--with-libxml2 \
		--with-readline="-L${LOCALBASE}/lib -ledit" \
		--with-dlopen=yes \
		--with-openssl=${OPENSSLBASE} \
		--sysconfdir=${ETCDIR}
ETCDIR=		${PREFIX}/etc/namedb

.if defined(BIND_TOOLS_SLAVE)
CONFIGURE_ARGS+=	--disable-shared
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-bind-tools
.else
USE_RC_SUBR=	named
SUB_FILES=	pkg-message named.conf
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-no-bind-tools

PORTDOCS=	*

# XXX: Add -devel
CONFLICTS=	bind911 bind912 bind913 bind914
.endif	# BIND_TOOLS_SLAVE

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFAULT=	DLZ_FILESYSTEM GSSAPI_NONE IDN JSON \
			LMDB PYTHON SIGCHASE TCP_FASTOPEN
OPTIONS_DEFINE=		DNSTAP DOCS FIXED_RRSET IDN JSON LARGE_FILE \
			LMDB OVERRIDECACHE PORTREVISION PYTHON QUERYTRACE \
			SIGCHASE START_LATE TCP_FASTOPEN TUNING_LARGE GEOIP

OPTIONS_RADIO=	CRYPTO
OPTIONS_RADIO_CRYPTO=	NATIVE_PKCS11

OPTIONS_GROUP=		DLZ
OPTIONS_GROUP_DLZ=	DLZ_POSTGRESQL DLZ_MYSQL DLZ_BDB \
			DLZ_LDAP DLZ_FILESYSTEM DLZ_STUB

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

.if defined(BIND_TOOLS_SLAVE)
OPTIONS_EXCLUDE=	DOCS ${OPTIONS_GROUP_DLZ} \
			OVERRIDECACHE PORTREVISION QUERYTRACE LMDB DNSTAP \
			START_LATE TUNING_LARGE TCP_FASTOPEN GEOIP
.else
OPTIONS_EXCLUDE=	PYTHON
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
PYTHON_DESC=		Build with Python utilities
QUERYTRACE_DESC=	Enable the very verbose query tracelogging
SIGCHASE_DESC=		dig/host/nslookup will do DNSSEC validation
START_LATE_DESC=	Start BIND late in the boot process (see help)
TCP_FASTOPEN_DESC=	RFC 7413 support
TUNING_LARGE_DESC=	Tune named for large systems (**READ HELP**)

DLZ_BDB_CONFIGURE_ON=	--with-dlz-bdb=yes
DLZ_BDB_USES=		bdb

DLZ_FILESYSTEM_CONFIGURE_ON=	--with-dlz-filesystem=yes

DLZ_LDAP_CONFIGURE_ON=	--with-dlz-ldap=yes
DLZ_LDAP_USE=		openldap=yes

DLZ_MYSQL_CONFIGURE_ON=	--with-dlz-mysql=yes
DLZ_MYSQL_USES=		mysql

DLZ_POSTGRESQL_CONFIGURE_ON=	--with-dlz-postgres=yes
DLZ_POSTGRESQL_USES=		pgsql

DLZ_STUB_CONFIGURE_ON=	--with-dlz-stub=yes

DNSTAP_CONFIGURE_ENABLE=	dnstap
DNSTAP_LIB_DEPENDS=	libfstrm.so:devel/fstrm \
			libprotobuf-c.so:devel/protobuf-c

FIXED_RRSET_CONFIGURE_ENABLE=	fixed-rrset

GEOIP_CONFIGURE_ENABLE=	geoip
GEOIP_CONFIGURE_WITH=	maxminddb
GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

GSSAPI_BASE_CONFIGURE_ON=\
	--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_BASE_USES=	gssapi

GSSAPI_HEIMDAL_CONFIGURE_ON=\
	--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_HEIMDAL_USES=	gssapi:heimdal

GSSAPI_MIT_CONFIGURE_ON=\
	--with-gssapi=${GSSAPIBASEDIR} KRB5CONFIG="${KRB5CONFIG}"
GSSAPI_MIT_USES=	gssapi:mit

GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi

IDN_CONFIGURE_OFF=	--without-libidn2
IDN_CONFIGURE_ON=	--with-libidn2=${LOCALBASE} ${ICONV_CONFIGURE_BASE}
IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2
IDN_USES=		iconv

JSON_CONFIGURE_WITH=	json-c
JSON_LIB_DEPENDS=	libjson-c.so:devel/json-c
JSON_LDFLAGS=		-L${LOCALBASE}/lib -ljson-c

LARGE_FILE_CONFIGURE_ENABLE=	largefile

LMDB_CONFIGURE_WITH=	lmdb=${LOCALBASE}
LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb

OVERRIDECACHE_EXTRA_PATCHES=	${FILESDIR}/extrapatch-bind-min-override-ttl

NATIVE_PKCS11_CONFIGURE_ENABLE=	native-pkcs11

PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply@${PY_FLAVOR}
PYTHON_CONFIGURE_WITH=	python=${PYTHON_CMD}
PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply@${PY_FLAVOR}
PYTHON_USES=	python

QUERYTRACE_CONFIGURE_ENABLE=	querytrace

SIGCHASE_CONFIGURE_ON=	STD_CDEFINES="-DDIG_SIGCHASE=1"

START_LATE_SUB_LIST=	NAMED_REQUIRE="SERVERS cleanvar" \
			NAMED_BEFORE="LOGIN"
START_LATE_SUB_LIST_OFF=NAMED_REQUIRE="NETWORKING ldconfig syslogd" \
			NAMED_BEFORE="SERVERS"

TCP_FASTOPEN_CONFIGURE_ENABLE=	tcp-fastopen

TUNING_LARGE_CONFIGURE_ON=	--with-tuning=large
TUNING_LARGE_CONFIGURE_OFF=	--with-tuning=default

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-symtable \
			--enable-developer
USES+=	perl5
USE_PERL5=	build
BUILD_DEPENDS+=	cmocka>0:sysutils/cmocka
.else
CONFIGURE_ARGS+=	--disable-symtable
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
	@${REINPLACE_CMD} -e '/RELEASETYPE=/s#$$#-${GL_COMMIT}#' \
		${WRKSRC}/version
.for FILE in check/named-checkconf.8 named/named.8 nsupdate/nsupdate.1 \
	rndc/rndc.8
	@${REINPLACE_CMD} -e 's#/etc/named.conf#${ETCDIR}/named.conf#g' \
		-e 's#/etc/rndc.conf#${ETCDIR}/rndc.conf#g' \
		-e "s#/var\/run\/named\/named.pid#/var/run/named/pid#" \
		${WRKSRC}/bin/${FILE}
.endfor

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
.else

# Can't use USE_PYTHON=autoplist
post-install-PYTHON-on:
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -type f | ${SED} -e 's|${STAGEDIR}||' >> ${TMPPLIST}
.endif	# BIND_TOOLS_SLAVE

.include <bsd.port.post.mk>
