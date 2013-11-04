# $FreeBSD$

PORTNAME?=	bind99
PORTVERSION=	9.9.4
PORTREVISION?=	0
CATEGORIES=	dns net ipv6
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	bind9/${ISCVERSION}
DISTNAME=	bind-${ISCVERSION}

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	BIND DNS suite with updated DNSSEC and DNS64

LICENSE=	ISCL

# ISC releases things like 9.8.0-P1, which our versioning doesn't like
ISCVERSION=	9.9.4

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps \
		--disable-symtable \
		--with-randomdev=/dev/random \
		--without-python

CONFLICTS=	bind9*-9.[45678].* bind9*-sdb-9.[45678].* bind-tools-9.*

OPTIONS_DEFAULT=	IPV6 SSL LINKS XML THREADS
OPTIONS_DEFINE=		SSL IDN REPLACE_BASE LARGE_FILE \
			FIXED_RRSET SIGCHASE IPV6 THREADS GSSAPI FILTER_AAAA
.if !defined(BIND_TOOLS_SLAVE)
OPTIONS_DEFINE+=	LINKS XML RPZ_NSIP RPZ_NSDNAME RRL
OPTIONS_GROUP=		DLZ
OPTIONS_GROUP_DLZ=	DLZ_POSTGRESQL DLZ_MYSQL DLZ_BDB \
			DLZ_LDAP DLZ_FILESYSTEM DLZ_STUB
.endif	# BIND_TOOLS_SLAVE

SSL_DESC=		Build with OpenSSL (Required for DNSSEC)
REPLACE_BASE_DESC=	Replace base BIND (FreeBSD 9.x and earlier)
LARGE_FILE_DESC=	64-bit file support
FIXED_RRSET_DESC=	Enable fixed rrset ordering
SIGCHASE_DESC=		dig/host/nslookup will do DNSSEC validation
FILTER_AAAA_DESC=	Enable filtering of AAAA records

.if !defined(BIND_TOOLS_SLAVE)
LINKS_DESC=		Create conf file symlinks in ${PREFIX}
XML_DESC=		Support for xml statistics output
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

CONFLICTS+=		bind-tools-9.*
.endif	# BIND_TOOLS_SLAVE

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
USE_OPENSSL=		yes
.else
CONFIGURE_ARGS+=	--disable-openssl-version-check
CONFIGURE_ARGS+=	--without-openssl
.endif

.if ${PORT_OPTIONS:MXML} && !defined(BIND_TOOLS_SLAVE)
CONFIGURE_ARGS+=	--with-libxml2=${LOCALBASE}
LIB_DEPENDS+=		xml2.5:${PORTSDIR}/textproc/libxml2
.else
CONFIGURE_ARGS+=	--without-libxml2
.endif

.if ${PORT_OPTIONS:MIDN}
USES+=			iconv
CONFIGURE_ARGS+=	--with-idn=${LOCALBASE} ${ICONV_CONFIGURE_BASE}
LIB_DEPENDS+=		idnkit.1:${PORTSDIR}/dns/idnkit
.else
CONFIGURE_ARGS+=	--without-idn
.endif

.if ${PORT_OPTIONS:MLINKS} && empty(PORT_OPTIONS:MREPLACE_BASE)
PLIST_SUB+=	LINKS=""
.else
PLIST_SUB+=	LINKS="@comment "
.endif

.if ${PORT_OPTIONS:MLARGE_FILE}
CONFIGURE_ARGS+=	--enable-largefile
.endif

.if ${PORT_OPTIONS:MSIGCHASE}
CONFIGURE_ARGS+=	STD_CDEFINES="-DDIG_SIGCHASE=1"
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${PORT_OPTIONS:MFILTER_AAAA}
CONFIGURE_ARGS+=	--enable-filter-aaaa
.endif

.if ${PORT_OPTIONS:MDLZ_POSTGRESQL}
CONFIGURE_ARGS+=	--with-dlz-postgres=yes
USE_PGSQL=		yes
.endif

.if ${PORT_OPTIONS:MFIXED_RRSET}
CONFIGURE_ARGS+=	--enable-fixed-rrset
.endif

.if ${PORT_OPTIONS:MRPZ_NSIP}
CONFIGURE_ARGS+=	--enable-rpz-nsip
.endif

.if ${PORT_OPTIONS:MRPZ_NSDNAME}
CONFIGURE_ARGS+=	--enable-rpz-nsdname
.endif

.if ${PORT_OPTIONS:MRRL}
CONFIGURE_ARGS+=	--enable-rrl
.endif

.if ${PORT_OPTIONS:MDLZ_MYSQL}
CONFIGURE_ARGS+=	--with-dlz-mysql=yes
USE_MYSQL=		yes
.endif

.if ${PORT_OPTIONS:MDLZ_BDB}
CONFIGURE_ARGS+=	--with-dlz-bdb=yes
USE_BDB=		yes
.endif

.if ${PORT_OPTIONS:MDLZ_LDAP}
CONFIGURE_ARGS+=	--with-dlz-ldap=yes
USE_OPENLDAP=		yes
.endif

.if ${PORT_OPTIONS:MDLZ_FILESYSTEM}
CONFIGURE_ARGS+=	--with-dlz-filesystem=yes
.endif

.if ${PORT_OPTIONS:MDLZ_STUB}
CONFIGURE_ARGS+=	--with-dlz-stub=yes
.endif

.if ${PORT_OPTIONS:MTHREADS} && empty(PORT_OPTIONS:MDLZ_MYSQL)
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if ${PORT_OPTIONS:MGSSAPI}
CONFIGURE_ARGS+=	--with-gssapi
.else
CONFIGURE_ARGS+=        --without-gssapi
.endif

.if ${PORT_OPTIONS:MREPLACE_BASE}
.if ${OSVERSION} >= 1000500
IGNORE=		REPLACE_BASE option is not supported on this release
.endif
PKGNAMESUFFIX=	-base
PREFIX=		/usr
BIND_DESTETC=	/etc/namedb
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--sysconfdir=${BIND_DESTETC}
.else
BIND_DESTETC=	${PREFIX}/etc
.endif

PLIST_SUB+=	BIND_DESTETC="${BIND_DESTETC}"

MAN1?=	arpaname.1 dig.1 host.1 isc-config.sh.1 nslookup.1 nsupdate.1
.if !defined(BIND_TOOLS_SLAVE)
MAN3=	lwres.3 lwres_addr_parse.3 lwres_buffer.3 lwres_buffer_add.3 \
	lwres_buffer_back.3 lwres_buffer_clear.3 lwres_buffer_first.3 \
	lwres_buffer_forward.3 lwres_buffer_getmem.3 lwres_buffer_getuint16.3 \
	lwres_buffer_getuint32.3 lwres_buffer_getuint8.3 lwres_buffer_init.3 \
	lwres_buffer_invalidate.3 lwres_buffer_putmem.3 \
	lwres_buffer_putuint16.3 lwres_buffer_putuint32.3 \
	lwres_buffer_putuint8.3 lwres_buffer_subtract.3 lwres_conf_clear.3 \
	lwres_conf_get.3 lwres_conf_init.3 lwres_conf_parse.3 \
	lwres_conf_print.3 lwres_config.3 lwres_context.3 \
	lwres_context_allocmem.3 lwres_context_create.3 \
	lwres_context_destroy.3 lwres_context_freemem.3 \
	lwres_context_initserial.3 lwres_context_nextserial.3 \
	lwres_context_sendrecv.3 lwres_endhostent.3 lwres_endhostent_r.3 \
	lwres_freeaddrinfo.3 lwres_freehostent.3 lwres_gabn.3 \
	lwres_gabnrequest_free.3 lwres_gabnrequest_parse.3 \
	lwres_gabnrequest_render.3 lwres_gabnresponse_free.3 \
	lwres_gabnresponse_parse.3 lwres_gabnresponse_render.3 \
	lwres_gai_strerror.3 lwres_getaddrinfo.3 lwres_getaddrsbyname.3 \
	lwres_gethostbyaddr.3 lwres_gethostbyaddr_r.3 lwres_gethostbyname.3 \
	lwres_gethostbyname2.3 lwres_gethostbyname_r.3 lwres_gethostent.3 \
	lwres_gethostent_r.3 lwres_getipnode.3 lwres_getipnodebyaddr.3 \
	lwres_getipnodebyname.3 lwres_getnamebyaddr.3 lwres_getnameinfo.3 \
	lwres_getrrsetbyname.3 lwres_gnba.3 lwres_gnbarequest_free.3 \
	lwres_gnbarequest_parse.3 lwres_gnbarequest_render.3 \
	lwres_gnbaresponse_free.3 lwres_gnbaresponse_parse.3 \
	lwres_gnbaresponse_render.3 lwres_herror.3 lwres_hstrerror.3 \
	lwres_inetntop.3 lwres_lwpacket_parseheader.3 \
	lwres_lwpacket_renderheader.3 lwres_net_ntop.3 lwres_noop.3 \
	lwres_nooprequest_free.3 lwres_nooprequest_parse.3 \
	lwres_nooprequest_render.3 lwres_noopresponse_free.3 \
	lwres_noopresponse_parse.3 lwres_noopresponse_render.3 \
	lwres_packet.3 lwres_resutil.3 lwres_sethostent.3 \
	lwres_sethostent_r.3 lwres_string_parse.3
MAN5=	named.conf.5 rndc.conf.5
MAN8=	ddns-confgen.8 dnssec-dsfromkey.8 dnssec-keyfromlabel.8 \
	dnssec-keygen.8 dnssec-revoke.8 dnssec-settime.8 dnssec-signzone.8 \
	dnssec-verify.8 \
	genrandom.8 isc-hmac-fixup.8 lwresd.8 named-checkconf.8 \
	named-checkzone.8 named-journalprint.8 named.8 nsec3hash.8 \
	rndc-confgen.8 rndc.8
MLINKS=	named-checkzone.8 named-compilezone.8
.endif	# BIND_TOOLS_SLVE

.if !defined(BIND_TOOLS_SLAVE)
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
	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf \
		${BIND_DESTETC}/rndc.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/arm ${DOCSDIR}/misc
	${INSTALL_DATA} ${WRKSRC}/doc/arm/*.html ${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM.pdf ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/misc/[a-z]* ${DOCSDIR}/misc
	${CP} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/FAQ \
		${WRKSRC}/HISTORY ${WRKSRC}/README ${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MLINKS} && empty(PORT_OPTIONS:MREPLACE_BASE)
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

	@${CAT} ${PKGMESSAGE}

.endif	# BIND_TOOLS_SLAVE

.include <bsd.port.mk>
