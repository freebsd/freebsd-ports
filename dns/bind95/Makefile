# New ports collection makefile for:	BIND 9.5.x
# Date created:				2 July 2008
# Whom:					dougb
#
# $FreeBSD$
#

# I stay very aware of developments with BIND in general, and with
# BIND 9 in particular. I frequently delay updating this port from
# a known-stable version due to concerns about stability of a newer
# version. If you are concerned about using the most recent ISC
# release you can generally build it cleanly from the source - Doug

PORTNAME=	bind95
PORTVERSION=	9.5.1.3
CATEGORIES=	dns net ipv6
MASTER_SITES=	${MASTER_SITE_ISC} \
		http://dougbarton.us/Downloads/%SUBDIR%/
MASTER_SITE_SUBDIR=	bind9/${ISCVERSION}
DISTNAME=	bind-${ISCVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	The BIND DNS suite with updated DNSSEC and threads

# ISC releases things like 9.4.0b3, which our versioning doesn't like
ISCVERSION=	9.5.1-P3

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps \
		--with-randomdev=/dev/random

CONFLICTS=	bind9*-9.[346].* bind9-sdb-* host-*

OPTIONS=	SSL "Building without OpenSSL removes DNSSEC" on \
		LINKS "Create conf file symlinks in ${PREFIX}" on \
		XML "Support for xml statistics output" on \
		IDN "Add IDN support to dig, host, etc." off \
		REPLACE_BASE "Replace base BIND with this version" off \
		LARGE_FILE "64-bit file support" off \
		SIGCHASE "dig/host/nslookup will do DNSSEC validation" off \
		IPV6 "IPv6 Support (autodetected by default)" off \
		DLZ_POSTGRESQL "DLZ Postgres driver" off \
		DLZ_MYSQL "DLZ MySQL driver (single-threaded BIND)" off \
		DLZ_BDB "DLZ BDB driver" off \
		DLZ_LDAP "DLZ LDAP driver" off \
		DLZ_FILESYSTEM "DLZ filesystem driver" off \
		DLZ_STUB "DLZ stub driver" off

# Just in case
USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

# We are ok by default from 7.0-RELEASE on
.if ${OSVERSION} >= 700055
OPTIONS+=	THREADS	"Compile with thread support" on
.else
OPTIONS+=	THREADS	"Compile w/threads (Not Recommended <FreeBSD-7)" off
.endif


.if !defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.else
CONFIGURE_ARGS+=	--disable-openssl-version-check
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !defined(WITHOUT_XML)
CONFIGURE_ARGS+=	--with-libxml2=${LOCALBASE}
LIB_DEPENDS+=		xml2.5:${PORTSDIR}/textproc/libxml2
.else
CONFIGURE_ARGS+=	--without-libxml2
.endif

.if defined(WITH_IDN)
CONFIGURE_ARGS+=	--with-idn=${LOCALBASE} --with-libiconv=${LOCALBASE}
LIB_DEPENDS+=		idnkit.1:${PORTSDIR}/dns/idnkit
.else
CONFIGURE_ARGS+=	--without-idn
.endif

.if !defined(WITHOUT_LINKS) && !defined(WITH_REPLACE_BASE)
PLIST_SUB+=	LINKS=""
.else
PLIST_SUB+=	LINKS="@comment "
.endif

.if defined(WITH_LARGE_FILE)
CONFIGURE_ARGS+=	--enable-largefile
.endif

.if defined(WITH_SIGCHASE)
CONFIGURE_ARGS+=	STD_CDEFINES="-DDIG_SIGCHASE=1"
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITH_DLZ_POSTGRESQL)
CONFIGURE_ARGS+=	--with-dlz-postgres=yes
USE_PGSQL=		yes
.endif

.if defined(WITH_DLZ_MYSQL)
CONFIGURE_ARGS+=	--with-dlz-mysql=yes
USE_MYSQL=		yes
WITHOUT_THREADS=	yes
.endif

.if defined(WITH_DLZ_BDB)
CONFIGURE_ARGS+=	--with-dlz-bdb=yes
USE_BDB=		yes
.endif

.if defined(WITH_DLZ_LDAP)
CONFIGURE_ARGS+=	--with-dlz-ldap=yes
USE_OPENLDAP=		yes
.endif

.if defined(WITH_DLZ_FILESYSTEM)
CONFIGURE_ARGS+=	--with-dlz-filesystem=yes
.endif

.if defined(WITH_DLZ_STUB)
CONFIGURE_ARGS+=	--with-dlz-stub=yes
.endif

# Has to be after the DLZ_MYSQL option
.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if defined(WITH_REPLACE_BASE)
PKGNAMESUFFIX=	-base
PREFIX=		/usr
BIND_DESTETC=	/etc/namedb
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--sysconfdir=${BIND_DESTETC}
.else
BIND_DESTETC=	${PREFIX}/etc
.endif

PLIST_SUB+=	BIND_DESTETC="${BIND_DESTETC}"

MAN1=	dig.1 host.1 nslookup.1 nsupdate.1
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
MAN8=	dnssec-keygen.8 dnssec-signzone.8 lwresd.8 named-checkconf.8 \
	named-checkzone.8 named.8 rndc-confgen.8 rndc.8
MLINKS=	named-checkzone.8 named-compilezone.8

verify:	checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

post-patch:
.for FILE in check/named-checkconf.8 named/named.8 nsupdate/nsupdate.1 \
	rndc/rndc.8
	@${MV} ${WRKSRC}/bin/${FILE} ${WRKSRC}/bin/${FILE}.Dist
	@${SED} -e 's#/etc/named.conf#${BIND_DESTETC}/named.conf#g' \
		-e 's#/etc/rndc.conf#${BIND_DESTETC}/rndc.conf#g' \
		${WRKSRC}/bin/${FILE}.Dist > ${WRKSRC}/bin/${FILE}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf \
		${BIND_DESTETC}/rndc.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/arm ${DOCSDIR}/misc
	${INSTALL_DATA} ${WRKSRC}/doc/arm/*.html ${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM.pdf ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/misc/[a-z]* ${DOCSDIR}/misc
	${CP} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/FAQ \
	${WRKSRC}/README ${WRKSRC}/README.idnkit \
	    ${DOCSDIR}/
.endif
.if !defined(WITHOUT_LINKS) && !defined(WITH_REPLACE_BASE)
	${MKDIR} /var/named${PREFIX}/etc
.for DIR in ${PREFIX}/etc /var/named${PREFIX}/etc
.for FILE in named.conf rndc.key
	${LN} -sf /etc/namedb/${FILE} ${DIR}/${FILE}
.endfor
.endfor
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
