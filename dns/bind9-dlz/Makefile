# New ports collection makefile for:	bind-dlz
# Date Created:				08 Jun 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	bind9
PORTVERSION=	${ISCVERSION}+${DLZVERSION}
PORTREVISION=	2
CATEGORIES=	dns ipv6
MASTER_SITES=	${MASTER_SITE_ISC} \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,dns/bind9/${ISCVERSION}/,} \
		${MASTER_SITES_DLZ:S/$/:dlz/}
MASTER_SITE_SUBDIR=	bind-dlz/:dlz
PKGNAMESUFFIX=	-dlz
DISTFILES=	bind-${ISCVERSION}.tar.gz \
	   	DLZ-${DLZVERSION}${EXTRACT_SUFX}:dlz

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	bind9/${ISCVERSION}
PATCHFILES=	patch.9.2.2-P1
PATCH_DIST_STRIP=	-p1

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	The Berkeley Internet Name Daemon, with DLZ extensions

CONFLICTS?=	bind-8.* bind84-8.* bind9-9.* bind9-sdb-mysql-* host-* skalibs-*
POSTGRESQL_PORT?=	databases/postgresql7
MASTER_SITES_DLZ=	${MASTER_SITE_SOURCEFORGE}

ISCVERSION=	9.2.2
DLZVERSION=	0.6.0
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps
PATCH_STRIP=	-p1

# use user config if possible
.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.else
.if defined(BATCH)
# default package, can be configured in /etc/make.conf
BINDDLZ_OPTIONS?=	\"OpenSSL\" \"PostgreSQL\" \"FileSystem\"
.endif
# make INDEX match
NO_DESCRIBE=yes
.endif

.if defined(WITH_POSTGRESQL_DRIVER)
.if !defined(WITHOUT_POSTGRESQL_DRIVER)
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-dlz-postgres
.endif
.endif

.if defined(WITH_MYSQL_DRIVER)
MYSQL_PORT?=	databases/mysql323-client
LIB_DEPENDS+=	mysqlclient:${PORTSDIR}/${MYSQL_PORT}
CONFIGURE_ARGS+=	--with-dlz-mysql
.endif

.if defined(WITH_LDAP)
LDAP_PORT?=	net/openldap20-client
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/${LDAP_PORT}
LIB_DEPENDS+=	lber.2:${PORTSDIR}/${LDAP_PORT}
CONFIGURE_ARGS+=	--with-dlz-ldap
.endif

.if defined(WITH_BERKLEYDB_DRIVER)
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
EXTRA_PATCHES=	${WRKDIR}/dlz.patch
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
MAN5=	rndc.conf.5
MAN8=	dnssec-keygen.8 dnssec-makekeyset.8 dnssec-signkey.8 dnssec-signzone.8 \
	lwresd.8 named-checkconf.8 named-checkzone.8 named.8 nsupdate.8 \
	rndc-confgen.8 rndc.8

pre-everything::
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
.for i in ${DOCS}
	@${ECHO_CMD} `${BASENAME} ${i}` | \
	${SED}  -e "s=^=%%EXTRA_DOCSDIR%%/=" >>${PLIST}
.endfor
	@(cd ${WRKSRC}/.. && ${FIND} dlz_docs -type f ) | \
	${SED}  -e "s=^=%%EXTRA_DOCSDIR%%/=" >>${PLIST}
	@(cd ${WRKSRC}/.. && ${FIND} -d dlz_docs -type d ) | \
	${SED} -e "s=^=@dirrm %%EXTRA_DOCSDIR%%/=" >>${PLIST}
	@${ECHO_CMD} "@dirrm %%EXTRA_DOCSDIR%%" >>${PLIST}
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
	${MKDIR} ${PREFIX}/${EXTRA_DOCSDIR}
	@cd ${WRKDIR} && ${INSTALL_DATA} ${DOCS} ${PREFIX}/${EXTRA_DOCSDIR}/
	${CP} -R ${WRKSRC}/../dlz_docs ${PREFIX}/${EXTRA_DOCSDIR}/dlz_docs
	@cd ${WRKDIR} && ${INSTALL_DATA} ${DOCS} ${PREFIX}/${EXTRA_DOCSDIR}/
.endif

post-clean:
	@ ${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500030
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if defined(NO_DESCRIBE)
describe:
.if defined(BATCH)
	@ ${SETENV} ${SCRIPTS_ENV} ${SH} ${FILESDIR}/configure.bind9-dlz
.endif
	@cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} BATCH=yes ${.TARGET}
.endif

.include <bsd.port.post.mk>
