# $FreeBSD$

PORTNAME=	bind
PORTVERSION=	${ISCVERSION:S/-P/P/}
PORTREVISION=	5
CATEGORIES=	dns net ipv6
MASTER_SITES=	ISC/bind9/${ISCVERSION}
PKGNAMESUFFIX=	98
DISTNAME=	${PORTNAME}-${ISCVERSION}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	BIND DNS suite with updated DNSSEC and DNS64

LICENSE=	ISCL

# ISC releases things like 9.8.0-P1, which our versioning doesn't like
ISCVERSION=	9.8.7-P1

PORTSCOUT=	limit:^9.8.

MAKE_JOBS_UNSAFE=	yes

USES=	cpe

CPE_VENDOR=	isc
CPE_VERSION=	${ISCVERSION:C/-.*//}
.if ${ISCVERSION:M*-*}
CPE_UPDATE=	${ISCVERSION:C/.*-//:tl}
.endif

DEPRECATED=	Will be EOL as of September 2014.
EXPIRATION_DATE=	2014-09-30

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps \
		--disable-symtable \
		--with-libxml2=${LOCALBASE} \
		--with-randomdev=/dev/random
ETCDIR=		${PREFIX}/etc/namedb

CONFLICTS=	bind9*-9.[45679].* bind9*-sdb-9.[45679].* bind-tools-9.*

OPTIONS_DEFAULT=	IPV6 SSL THREADS GSSAPI_NONE RPZRRL_PATCH
OPTIONS_DEFINE=		SSL LINKS IDN REPLACE_BASE LARGE_FILE \
			FIXED_RRSET RPZ_NSIP RPZ_NSDNAME RPZRRL_PATCH \
			SIGCHASE IPV6 THREADS FILTER_AAAA DOCS GOST
OPTIONS_GROUP=		DLZ
OPTIONS_GROUP_DLZ=	DLZ_POSTGRESQL DLZ_MYSQL DLZ_BDB \
			DLZ_LDAP DLZ_FILESYSTEM DLZ_STUB
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

SSL_DESC=		Build with OpenSSL (Required for DNSSEC)
LINKS_DESC=		Create conf file symlinks in ${PREFIX}
REPLACE_BASE_DESC=	Replace base BIND (FreeBSD 9.x and earlier)
LARGE_FILE_DESC=	64-bit file support
SIGCHASE_DESC=		dig/host/nslookup will do DNSSEC validation
FIXED_RRSET_DESC=	Enable fixed rrset ordering
RPZ_NSIP_DESC=		Enable RPZ NSIP trigger rules
RPZ_NSDNAME_DESC=	Enable RPZ NSDNAME policy records
RPZRRL_PATCH_DESC=	RPZ improvements + RRL patch (experimental)
FILTER_AAAA_DESC=	Enable filtering of AAAA records
GOST_DESC=		Enable GOST ciphers (DSO incompatible with chroot) 
DLZ_DESC=		Dynamically Loadable Zones
DLZ_POSTGRESQL_DESC=	DLZ Postgres driver
DLZ_MYSQL_DESC=		DLZ MySQL driver (no threading)
DLZ_BDB_DESC=		DLZ BDB driver
DLZ_LDAP_DESC=		DLZ LDAP driver
DLZ_FILESYSTEM_DESC=	DLZ filesystem driver
DLZ_STUB_DESC=		DLZ stub driver
GSSAPI_BASE_DESC=	${GSSAPI_DESC} (Heimdal in base)
GSSAPI_HEIMDAL_DESC=	${GSSAPI_DESC} (security/heimdal)
GSSAPI_MIT_DESC=	${GSSAPI_DESC} (security/krb5)
GSSAPI_NONE_DESC=	No ${GSSAPI_DESC}

SSL_CONFIGURE_ON=	--with-openssl=${OPENSSLBASE}
SSL_USE=	openssl=yes
SSL_CONFIGURE_OFF=	--disable-openssl-version-check --without-openssl

IDN_USES=		iconv
IDN_CONFIGURE_ON=	--with-idn=${LOCALBASE} ${ICONV_CONFIGURE_BASE}
IDN_CONFIGURE_OFF=	--without-idn
IDN_LIB_DEPENDS=	libidnkit.so:${PORTSDIR}/dns/idnkit

LARGE_FILE_CONFIGURE_ENABLE=	largefile

SIGCHASE_CONFIGURE_ON=	STD_CDEFINES="-DDIG_SIGCHASE=1"

IPV6_CONFIGURE_ENABLE=	ipv6

FILTER_AAAA_CONFIGURE_ENABLE=	filter-aaaa

FIXED_RRSET_CONFIGURE_ENABLE=	fixed-rrset

RPZ_NSIP_CONFIGURE_ENABLE=	rpz-nsip

RPZ_NSDNAME_CONFIGURE_ENABLE=	rpz-nsdname

RPZRRL_PATCH_PATCHFILES=	9.8.7-P1-rpz2+rl.14038.05.patch:vix
RPZRRL_PATCH_PATCH_SITES=	http://ss.vix.su/~vjs/:vix ${MASTER_SITE_LOCAL:S/%SUBDIR%/mat\/bind/:S/$/:vix/}

GOST_CONFIGURE_WITH=	gost

DLZ_POSTGRESQL_CONFIGURE_ON=	--with-dlz-postgres=yes
DLZ_POSTGRESQL_USE=	pgsql=yes

DLZ_MYSQL_CONFIGURE_ON=	--with-dlz-mysql=yes
DLZ_MYSQL_USE=		mysql=yes

DLZ_BDB_CONFIGURE_ON=	--with-dlz-bdb=yes
DLZ_BDB_USE=		bdb=yes

DLZ_LDAP_CONFIGURE_ON=	--with-dlz-ldap=yes
DLZ_LDAP_USE=		openldap=yes

DLZ_FILESYSTEM_CONFIGURE_ON=	--with-dlz-filesystem=yes

DLZ_STUB_CONFIGURE_ON=	--with-dlz-stub=yes

GSSAPI_BASE_USES=	gssapi
GSSAPI_BASE_CONFIGURE_ON= \
	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON= \
	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_MIT_CONFIGURE_ON= \
	--with-gssapi=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MLINKS} || ${PORT_OPTIONS:MREPLACE_BASE}
PKGINSTALL=${NONEXISTENT}
.endif

.if ${PORT_OPTIONS:MTHREADS} && !${PORT_OPTIONS:MDLZ_MYSQL}
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if ${PORT_OPTIONS:MREPLACE_BASE}
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000100
IGNORE=		REPLACE_BASE option is not supported on this release
.endif # >= 10.0
PKGNAMESUFFIX=	-base
PREFIX=		/usr
PLIST_SUB+=	SHARE_MAN="share/"
NO_MTREE=	yes
BIND_DESTETC=	/etc/namedb
.else # REPLACE_BASE
PLIST_SUB+=	SHARE_MAN=""
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000100
BIND_DESTETC=	${PREFIX}/etc/namedb
PKGINSTALL=	${NONEXISTENT}
.else # >= 10.0
BIND_DESTETC=	${PREFIX}/etc
.endif # >= 10.0
.endif # REPLACE_BASE

PKGDEINSTALL=	${PKGINSTALL}

CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--sysconfdir=${BIND_DESTETC}
SUB_LIST+=	BIND_DESTETC="${BIND_DESTETC}"

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000100
PLIST_SUB+=	NOBASE="" BASE="@comment "
USE_RC_SUBR+=	named
SUB_FILES+=	named.conf
.if ${PORT_OPTIONS:MGOST}
WITH_OPENSSL_PORT=yes
.endif
.else
PLIST_SUB+=	NOBASE="@comment " BASE=""
.if ${PORT_OPTIONS:MSSL}
WITH_OPENSSL_PORT=	yes
.endif
.endif

post-patch:
.for FILE in check/named-checkconf.8 named/named.8 nsupdate/nsupdate.1 \
	rndc/rndc.8
	@${MV} ${WRKSRC}/bin/${FILE} ${WRKSRC}/bin/${FILE}.Dist
	@${SED} -e 's#/etc/named.conf#${BIND_DESTETC}/named.conf#g' \
		-e 's#/etc/rndc.conf#${BIND_DESTETC}/rndc.conf#g' \
		-e "s#/var\/run\/named\/named.pid#/var/run/named/pid#" \
		${WRKSRC}/bin/${FILE}.Dist > ${WRKSRC}/bin/${FILE}
.endfor
	@${MV} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.Dist
	@${SED} -e 's#.*bind\.keys.*##' ${WRKSRC}/Makefile.in.Dist > \
		${WRKSRC}/Makefile.in
	@${MV} ${WRKSRC}/bin/named/Makefile.in ${WRKSRC}/bin/named/Makefile.in.Dist
	@${SED} -e 's/$${PERL}/#/' -e 's/bind.keys.h/#/g' -e 's/bind9.xsl.h/#/g' \
		${WRKSRC}/bin/named/Makefile.in.Dist > \
		${WRKSRC}/bin/named/Makefile.in

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif
post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/arm ${STAGEDIR}${DOCSDIR}/misc
	${INSTALL_DATA} ${WRKSRC}/doc/arm/*.html ${STAGEDIR}${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/misc/[a-z]* ${STAGEDIR}${DOCSDIR}/misc
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/FAQ \
		${WRKSRC}/HISTORY ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000100
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for i in dynamic master slave working
	@${MKDIR} ${STAGEDIR}${ETCDIR}/$i
.endfor
	${INSTALL_DATA} ${WRKDIR}/named.conf ${STAGEDIR}${ETCDIR}/named.conf.sample
	${INSTALL_DATA} ${FILESDIR}/named.root ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/empty.db ${STAGEDIR}${ETCDIR}/master
	${INSTALL_DATA} ${FILESDIR}/localhost-forward.db ${STAGEDIR}${ETCDIR}/master
	${INSTALL_DATA} ${FILESDIR}/localhost-reverse.db ${STAGEDIR}${ETCDIR}/master
	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf ${STAGEDIR}${ETCDIR}/rndc.conf.sample
.endif

.include <bsd.port.mk>
