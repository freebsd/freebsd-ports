# New ports collection makefile for:	bind-dlz
# Date Created:				08 Jun 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	bind9
PORTVERSION=	${ISCVERSION}+${DLZVERSION}
CATEGORIES=	dns ipv6
MASTER_SITES=	${MASTER_SITE_ISC} \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,dns/bind9/${ISCVERSION}/,} \
		${MASTER_SITES_DLZ:S/$/:dlz/}
MASTER_SITE_SUBDIR=	bind9/${ISCVERSION} bind-dlz/:dlz
PKGNAMESUFFIX?=	-dlz${POSTGRESQL_SUFFIX}${MYSQL_SUFFIX}${BERKLEYDB_SUFFIX}${LDAP_SUFFIX}${PKGNAMESUFFIX2}
DISTFILES=	bind-${ISCVERSION}.tar.gz

PATCH_SITES=	${MASTER_SITES} http://projects.navynet.it/DLZ/:it 
PATCH_SITE_SUBDIR=	bind9/${ISCVERSION}
PATCHFILES=	
PATCH_DIST_STRIP=	-p1

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	The Berkeley Internet Name Daemon, with DLZ extensions

CONFLICTS?=	bind-8.* bind84-8.* bind9-9.* bind9-sdb-mysql-* host-* skalibs-*
MASTER_SITES_DLZ=	${MASTER_SITE_SOURCEFORGE}

DLZVERSION=	0.7.0
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps --with-openssl \
		--with-randomdev=/dev/random
PATCH_STRIP=	-p1

# use user config if possible
.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.else
.if defined(BATCH)
# default package, can be configured in /etc/make.conf
BINDDLZ_OPTIONS?=	\"Threads\" \"OpenSSL\" \"PostgreSQL\" \"FileSystem\"
.endif
# make INDEX match
NO_DESCRIBE=yes
.endif

.if defined(WITH_DLZ_OLD)
ISCVERSION=	9.2.2
DISTFILES+=  	DLZ-${DLZVERSION}${EXTRACT_SUFX}:dlz
PATCHFILES+=	patch.9.2.2-P1
PLIST_SUB+=	BIND922="" BIND931="@comment "
EXTRA_PATCHES+=	${WRKDIR}/dlz.patch ${FILESDIR}/db42-bind922.patch
.else
ISCVERSION=	9.3.1
PATCHFILES+=  	ctrix_dlz_${ISCVERSION}-1.patch.gz:it
EXTRA_PATCHES+=	${FILESDIR}/db42-bind931.patch
PLIST_SUB+=	BIND931="" BIND922="@comment "
.endif

.if defined(WITH_POSTGRESQL_DRIVER)
.if !defined(WITHOUT_POSTGRESQL_DRIVER)
POSTGRESQL_SUFFIX=	+postgres
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-dlz-postgres
.endif
.endif

.if defined(WITH_MYSQL_DRIVER)
MYSQL_SUFFIX=	+mysql
MYSQL_PORT?=	databases/mysql323-client
LIB_DEPENDS+=	mysqlclient:${PORTSDIR}/${MYSQL_PORT}
CONFIGURE_ARGS+=	--with-dlz-mysql
.endif

.if defined(WITH_LDAP)
LDAP_SUFFIX=	+ldap
.if defined(LDAP_PORT)
BUILD_DEPENDS+=	${LOCALBASE}/lib/${OPENLDAP_LIB}:${PORTSDIR}/${LDAP_PORT}
RUN_DEPENDS+=	${LOCALBASE}/lib/${OPENLDAP_LIB}:${PORTSDIR}/${LDAP_PORT}
.else
USE_OPENLDAP_VER?=	22
.endif
CONFIGURE_ARGS+=	--with-dlz-ldap
.endif

.if defined(WITH_BERKLEYDB_DRIVER)
BERKLEYDB_SUFFIX=	+db4
BERKLEYDB_PORT?=	databases/db41
BERKLEYDB_LIB?=		db41.1
CONFIGURE_ARGS+=	--with-dlz-bdb=${LOCALBASE}
LIB_DEPENDS+=		${BERKLEYDB_LIB}:${PORTSDIR}/${BERKLEYDB_PORT}
.endif

.if defined(WITH_FILESYSTEM_DRIVER)
.if !defined(WITHOUT_FILESYSTEM_DRIVER)
CONFIGURE_ARGS+=	--with-dlz-filesystem
.endif
.endif

.if defined(WITH_STUB_DRIVER)
CONFIGURE_ARGS+=	--with-dlz-stub
.endif

.if defined(WITH_OPENSSL)
.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif
.endif

WRKSRC=		${WRKDIR}/bind-${ISCVERSION}
PLIST=		${WRKDIR}/.PLIST.more
PLIST_SUB+=	EXTRA_DOCSDIR=${EXTRA_DOCSDIR}

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
	        CURDIR2="${.CURDIR}" \
		MKDIR="${MKDIR}" \
		DISTNAME="${DISTNAME}" \
		BINDDLZ_OPTIONS="${BINDDLZ_OPTIONS}"

DOCSDIR=	${PREFIX}/share/doc/bind9
EXTRA_DOCSDIR=	share/doc/bind9-dlz
DOCS=		README.txt bind_dlz.txt changelog.txt dlz.schema \
		dlz_interface.txt sdlz_helper.txt sdlz_interface.txt

MAN1=	dig.1 host.1
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
.if defined(WITH_DLZ_OLD)
MAN1=	dig.1 host.1
MAN5=	rndc.conf.5
MAN8=	dnssec-keygen.8 dnssec-makekeyset.8 dnssec-signkey.8 dnssec-signzone.8 \
	lwresd.8 named-checkconf.8 named-checkzone.8 named.8 nsupdate.8 \
	rndc-confgen.8 rndc.8
.else
MAN1=	dig.1 host.1 nslookup.1
MAN5=	named.conf.5 rndc.conf.5
MAN8=	dnssec-keygen.8 dnssec-signzone.8 lwresd.8 named-checkconf.8 \
	named-checkzone.8 named.8 nsupdate.8 rndc-confgen.8 rndc.8
.endif

pre-fetch:
	@ ${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/configure.bind9-dlz

pre-configure:
.for FILE in check/named-checkconf.8 named/named.8 nsupdate/nsupdate.8 \
	rndc/rndc.8
	${REINPLACE_CMD} -e 's#/etc/named.conf#${PREFIX}/etc/named.conf#g' \
		-e 's#/etc/rndc.conf#${PREFIX}/etc/rndc.conf#g' \
		${WRKSRC}/bin/${FILE}
.endfor
	${MV} -f ${WRKSRC}/bin/Makefile.in.orig ${WRKSRC}/bin/Makefile.in
	@${ECHO_CMD} "configure: ${CONFIGURE_ARGS}"
	${REINPLACE_CMD} -e "s=-lnsl==" \
		-e 's=-pthread=${PTHREAD_LIBS}=' \
		${WRKSRC}/configure
	${CHMOD} +x ${WRKSRC}/configure

pre-install:
	${CAT} ${MASTERDIR}/pkg-plist >${PLIST}
.if !defined(NOPORTDOCS)
.if defined(WITH_DLZ_OLD)
.for i in ${DOCS}
	@${ECHO_CMD} `${BASENAME} ${i}` | \
	${SED}  -e "s=^=%%EXTRA_DOCSDIR%%/=" >>${PLIST}
.endfor
	@${ECHO_CMD} "@dirrm %%EXTRA_DOCSDIR%%" >>${PLIST}
.endif
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf \
		${PREFIX}/etc/rndc.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/arm ${DOCSDIR}/misc
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM*html ${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/misc/[a-z]* ${DOCSDIR}/misc
	${CP} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/FAQ \
		${WRKSRC}/README ${DOCSDIR}/
.if defined(WITH_DLZ_OLD)
	${MKDIR} ${PREFIX}/${EXTRA_DOCSDIR}
	@cd ${WRKDIR} && ${INSTALL_DATA} ${DOCS} ${PREFIX}/${EXTRA_DOCSDIR}/
.endif
.endif

.if defined(WITH_BIND9_THREADS)
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

post-clean:
	@ ${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.pre.mk>

.if defined(NO_DESCRIBE)
describe:
.if defined(BATCH)
	@ ${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/configure.bind9-dlz
.endif
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} BATCH=yes ${.TARGET}
.endif

.include <bsd.port.post.mk>
