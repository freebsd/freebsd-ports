# $FreeBSD$

PORTNAME=	bind96
PORTVERSION=	9.6.3.2.ESV.R10
CATEGORIES=	dns net ipv6
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	bind9/${ISCVERSION}
DISTNAME=	bind-${ISCVERSION}

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	BIND DNS suite with updated DNSSEC and threads

LICENSE=	ISCL

# ISC releases things like 9.4.0b3, which our versioning doesn't like
ISCVERSION=	9.6-ESV-R10

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps \
		--with-randomdev=/dev/random

CONFLICTS=	bind9*-9.[45789].* bind9*-sdb-9.[45789].* bind-tools-9.*
DEPRECATED=	EOL in January 2014, consider moving to Bind 9.8 or 9.9
EXPIRATION_DATE=	2014-01-31

OPTIONS_DEFAULT=	IPV6 SSL XML THREADS
OPTIONS_DEFINE=		SSL LINKS XML IDN REPLACE_BASE LARGE_FILE \
			SIGCHASE IPV6 THREADS FIXED_RRSET
OPTIONS_GROUP=		DLZ
OPTIONS_GROUP_DLZ=	DLZ_POSTGRESQL DLZ_MYSQL DLZ_BDB \
			DLZ_LDAP DLZ_FILESYSTEM DLZ_STUB

SSL_DESC=		Build with OpenSSL (Required for DNSSEC)
LINKS_DESC=		Create conf file symlinks in ${PREFIX}
XML_DESC=		Support for xml statistics output
REPLACE_BASE_DESC=	Replace base BIND (FreeBSD 9.x and earlier)
LARGE_FILE_DESC=	64-bit file support
SIGCHASE_DESC=		dig/host/nslookup will do DNSSEC validation
FIXED_RRSET=		Enable fixed rrset ordering
DLZ_DESC=		Dynamically Loadable Zones
DLZ_POSTGRESQL_DESC=	DLZ Postgres driver
DLZ_MYSQL_DESC=		DLZ MySQL driver (no threading)
DLZ_BDB_DESC=		DLZ BDB driver
DLZ_LDAP_DESC=		DLZ LDAP driver
DLZ_FILESYSTEM_DESC=	DLZ filesystem driver
DLZ_STUB_DESC=		DLZ stub driver

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

.if ${PORT_OPTIONS:MXML}
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

.if ${PORT_OPTIONS:MFIXED_RRSET}
CONFIGURE_ARGS+=	--enable-fixed-rrset
.endif

.if ${PORT_OPTIONS:MDLZ_POSTGRESQL}
CONFIGURE_ARGS+=	--with-dlz-postgres=yes
USE_PGSQL=		yes
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

.if ${PORT_OPTIONS:MREPLACE_BASE}
.if ${OSVERSION} >= 1000500
IGNORE=		REPLACE_BASE option not supported on this release
.endif
PKGNAMESUFFIX=	-base
PREFIX=		/usr
BIND_DESTETC=	/etc/namedb
.else
.if ${OSVERSION} >= 1000500
BIND_DESTETC=	${PREFIX}/etc/namedb
.else
BIND_DESTETC=	${PREFIX}/etc
.endif
.endif

CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--sysconfdir=${BIND_DESTETC}
PLIST_SUB+=	BIND_DESTETC="${BIND_DESTETC}"

.if ${OSVERSION} >= 1000500
PLIST_SUB+=	NOBASE=""
.else
PLIST_SUB+=	NOBASE="@comment "
.endif

MAN1=	dig.1 host.1 isc-config.sh.1 nslookup.1 nsupdate.1
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
MAN8=	dnssec-dsfromkey.8 dnssec-keyfromlabel.8 dnssec-keygen.8 \
	dnssec-signzone.8 lwresd.8 named-checkconf.8 named-checkzone.8 \
	named.8 rndc-confgen.8 rndc.8
MLINKS=	named-checkzone.8 named-compilezone.8

post-patch:
.for FILE in check/named-checkconf.8 named/named.8 nsupdate/nsupdate.1 \
	rndc/rndc.8
	@${MV} ${WRKSRC}/bin/${FILE} ${WRKSRC}/bin/${FILE}.Dist
	@${SED} -e 's#/etc/named.conf#${BIND_DESTETC}/named.conf#g' \
		-e 's#/etc/rndc.conf#${BIND_DESTETC}/rndc.conf#g' \
		-e "s#/var\/run\/named\/named.pid#/var/run/named/pid#" \
		${WRKSRC}/bin/${FILE}.Dist > ${WRKSRC}/bin/${FILE}
.endfor

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif
post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/arm ${DOCSDIR}/misc
	${INSTALL_DATA} ${WRKSRC}/doc/arm/*.html ${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM.pdf ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/misc/[a-z]* ${DOCSDIR}/misc
	${CP} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/FAQ \
	    ${WRKSRC}/NSEC3-NOTES ${WRKSRC}/README* ${DOCSDIR}/
.endif
.if ${OSVERSION} >= 1000500
.for FILE in named named.conf
	${SED} -e 's#%%PREFIX%%#${PREFIX}#g' \
		-e 's#%%BIND_DESTETC%%#${BIND_DESTETC}#g' \
		${FILESDIR}/${FILE} > ${WRKDIR}/${FILE}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/named ${PREFIX}/etc/rc.d
	${MKDIR} ${BIND_DESTETC}
.for DIR in dynamic master slave working
	${MKDIR} ${BIND_DESTETC}/${DIR}
.endfor
.for DIR in dynamic slave working
	${CHOWN} bind:bind ${BIND_DESTETC}/${DIR}
.endfor
	${INSTALL_DATA} ${WRKDIR}/named.conf ${BIND_DESTETC}
	${INSTALL_DATA} ${FILESDIR}/named.root ${BIND_DESTETC}
	${INSTALL_DATA} ${FILESDIR}/empty.db ${BIND_DESTETC}/master
	${INSTALL_DATA} ${FILESDIR}/localhost-forward.db ${BIND_DESTETC}/master
	${INSTALL_DATA} ${FILESDIR}/localhost-reverse.db ${BIND_DESTETC}/master
.elif ${PORT_OPTIONS:MLINKS} && empty(PORT_OPTIONS:MREPLACE_BASE)
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf \
		${BIND_DESTETC}/rndc.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
