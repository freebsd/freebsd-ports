# Created by: Stephane Legrand
# $FreeBSD$

PORTNAME?=	proftpd
PORTVERSION?=	1.3.4d
PORTREVISION?=	2
CATEGORIES?=	ftp
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/source/ \
		https://github.com/downloads/proftpd/proftpd.github.com/ \
		ftp://proftpd.networkedsystems.co.uk/distrib/source/ \
		http://www.mirrorservice.org/sites/ftp.proftpd.org/distrib/source/ \
		https://codeload.github.com/jbenden/mod_clamav/legacy.tar.gz/v0.13rc2?dummy=/:clamav
.if defined(_BUILDING_PROFTPD_MODULE)
DISTNAME=	proftpd-${PORTVERSION}
.endif

MAINTAINER?=	mm@FreeBSD.org
COMMENT?=	Highly configurable FTP daemon

LICENSE?=	GPLv2
LICENSE_FILE?=	${WRKSRC}/COPYING

.if defined(_BUILDING_PROFTPD_MODULE)
BUILD_DEPENDS+=	${LOCALBASE}/sbin/proftpd:${PORTSDIR}/ftp/proftpd
RUN_DEPENDS+=	${LOCALBASE}/sbin/proftpd:${PORTSDIR}/ftp/proftpd
.endif

.if defined(_BUILDING_PROFTPD_MODULE)
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY+=	${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/proftpd-${PORTVERSION}
. if defined(_PROFTPD_MODULE_EXTRACT_ONLY)
EXTRACT_ONLY+=	${_PROFTPD_MODULE_EXTRACT_ONLY}
. endif
. if defined(_PROFTPD_MODULE_DISTFILES)
DISTFILES+=	${_PROFTPD_MODULE_DISTFILES}
. endif
.endif

.if !defined(_BUILDING_PROFTPD_MODULE)
PORTDOCS=	*
.endif

MAKE_JOBS_UNSAFE=	yes
USES=		gmake
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes

.if !defined(_BUILDING_PROFTPD_MODULE)
USE_OPENSSL=	yes
USE_RC_SUBR=	proftpd
.endif

LOCALSTATEDIR?=	/var/run

CONFIGURE_ARGS=--localstatedir=${LOCALSTATEDIR} \
		--libexecdir=${PREFIX}/libexec/proftpd \
		--with-pkgconfig=libdata/pkgconfig \
		--sysconfdir=${PREFIX}/etc \
		--enable-ctrls \
		--enable-dso \
		--disable-sendfile

.if defined(_BUILDING_PROFTPD_MODULE)
MODULES=		${_BUILDING_PROFTPD_MODULE}
.for m in ${MODULES}
__MODULES:=${__MODULES}:${m}
.endfor
CONFIGURE_ARGS+=	--with-shared=${__MODULES:C/^://g}
INCLUDEDIRS:=${INCLUDEDIRS}:${LOCALBASE}/include/proftpd
ALL_TARGET=	shared
BUILD_WRKSRC=	${WRKSRC}/modules
INSTALL_WRKSRC=	${WRKSRC}/modules
PLIST=		${WRKDIR}/PLIST
.for m in ${MODULES}
PLIST_FILES+=	libexec/proftpd/${m}.a \
		libexec/proftpd/${m}.la \
		libexec/proftpd/${m}.so
.endfor
PLIST_DIRSTRY+=	libexec/proftpd
.else
OPTIONS_DEFINE=	HTMLDOCS IPV6 NLS MEMCACHE PCRE CLAMAV
OPTIONS_DEFAULT=	IPV6 NLS PCRE

CLAMAV_DESC=		Include mod_clamav
HTMLDOCS_DESC=		Include HTML documentation
MEMCACHE_DESC=		Memcache support using libmemcached

PLIST_SUB+=	LOCALSTATEDIR="${LOCALSTATEDIR}"

.endif #!defined(_BUILDING_PROFTPD_MODULE)

.include <bsd.port.options.mk>

.if defined(USE_OPENSSL)
CFLAGS+=	-DHAVE_OPENSSL -I${OPENSSLINC}
PROFTPD_LIBS+=	-lssl -lcrypto -L${OPENSSLLIB}
.endif

.if !defined(_BUILDING_PROFTPD_MODULE)
LIBDIRS?=	${LOCALBASE}/lib
INCLUDEDIRS?=	${LOCALBASE}/include

# Always built modules
MODULES+=	mod_ban \
		mod_copy \
		mod_ctrls_admin \
		mod_deflate \
		mod_dynmasq \
		mod_exec \
		mod_ifsession \
		mod_ifversion \
		mod_qos \
		mod_quotatab \
		mod_quotatab_file \
		mod_quotatab_radius \
		mod_quotatab_sql \
		mod_radius \
		mod_ratio \
		mod_readme \
		mod_rewrite \
		mod_sftp \
		mod_sftp_pam \
		mod_sftp_sql \
		mod_shaper \
		mod_site_misc \
		mod_sql \
		mod_sql_passwd \
		mod_tls \
		mod_tls_shmcache \
		mod_unique_id \
		mod_wrap2 \
		mod_wrap2_file \
		mod_wrap2_sql

# FreeBSD-SA-11:07.chroot
.if ${OSVERSION} < 800000
CHROOT_TEST !=	${GREP} __FreeBSD_libc_enter_restricted_mode \
	/usr/include/unistd.h > /dev/null || ${ECHO_CMD} error
. if ${CHROOT_TEST} == "error"
BROKEN=__FreeBSD_libc_enter_restricted_mode is not supported
. endif
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-7-src-fsio.c
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-8-src-fsio.c
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
USES+=	gettext
PROFTPD_LIBS+=	-lintl -L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=		pcre:${PORTSDIR}/devel/pcre
CONFIGURE_ARGS+=	--enable-pcre
.else
CONFIGURE_ARGS+=	--disable-pcre
.endif

.if ${PORT_OPTIONS:MCLAMAV} || make(makesum) || defined(FETCH_ALL)
DISTFILES+=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		mod_clamav-v0.13rc2${EXTRACT_SUFX}:clamav
USE_CLAMAV=	yes
MODULES+=	mod_clamav
RUN_DEPENDS+=	clamd:${PORTSDIR}/security/clamav
PLIST_SUB+=	CLAMAV=""
.else
PLIST_SUB+=	CLAMAV="@comment " 
.endif

.if ${PORT_OPTIONS:MMEMCACHE}
MODULES+=		mod_memcache \
			mod_tls_memcache
LIB_DEPENDS+=		memcached:${PORTSDIR}/databases/libmemcached
CONFIGURE_ARGS+=	--enable-memcache
PROFTPD_LIBS+=		-lmemcached -lmemcachedutil
PLIST_SUB+=	MEMCACHE=""
.else
CONFIGURE_ARGS+=	--disable-memcache
PLIST_SUB+=	MEMCACHE="@comment "
.endif

# Generate modules configuration string
.for m in ${MODULES}
_MODULES:=${_MODULES}:${m}
.endfor

# Keep this here below, in case similar constructs need to be made
CONFIGURE_ENV+=		LIBS="${PROFTPD_LIBS}"
CONFIGURE_ARGS+=	--with-shared=${_MODULES:C/^://g}

.endif #!defined(_BUILDING_PROFTPD_MODULE)

CONFIGURE_ARGS+=	--with-includes=${INCLUDEDIRS}
CONFIGURE_ARGS+=	--with-libraries=${LIBDIRS}

.if !defined(_BUILDING_PROFTPD_MODULE)

post-patch:
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|-lsupp|-lsupp -lintl|g' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|proftpd\.conf|proftpd.conf.sample|g' ${WRKSRC}/Makefile.in

pre-configure:
.if ${PORT_OPTIONS:MCLAMAV}
	@${CP} ${WRKDIR}/jbenden-mod_clamav-0b524e3/mod_clamav.* ${WRKSRC}/contrib
.endif
	@${ECHO_MSG} "==> Configuring with following modules:"
	@${ECHO_MSG} "${MODULES:C/^://g}"

post-configure:
	${REINPLACE_CMD} -e 's: -lnsl::' ${WRKSRC}/Make.rules
	${REINPLACE_CMD} -e 's:/usr/sbin:${PREFIX}/sbin:' \
		-e 's:/usr/bin:${PREFIX}/bin:' \
		${WRKSRC}/src/proftpd.8 ${WRKSRC}/utils/ftpshut.8 \
		${WRKSRC}/utils/ftpcount.1

.endif #!defined(_BUILDING_PROFTPD_MODULE)

.if defined(_BUILDING_PROFTPD_MODULE)
pre-build:
	@cd ${WRKSRC} && ${MAKE} include/buildstamp.h

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/proftpd

.else
post-install:
	@cd  ${STAGEDIR}${PREFIX}/etc/ && ${CP} -n proftpd.conf.sample proftpd.conf || ${TRUE}
	@${MKDIR} ${STAGEDIR}${LOCALSTATEDIR}/proftpd
	@cd  ${STAGEDIR}${PREFIX}/etc/proftpd && ${CP} -n dhparams.pem.sample dhparams.pem || ${TRUE}
	@cd  ${STAGEIDR}${PREFIX}/etc/proftpd && ${CP} -n blacklist.dat.sample blacklist.dat || ${TRUE}
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${CP} README* RELEASE_NOTES ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} license.txt ${STAGEDIR}${DOCSDIR}
. if ${PORT_OPTIONS:MHTMLDOCS}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}/html
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} Configuration.html faq.html ${STAGEDIR}${DOCSDIR}/html
	@${CP} -RP ${WRKSRC}/doc/contrib ${STAGEDIR}${DOCSDIR}/html/contrib
	@${CP} -RP ${WRKSRC}/doc/modules ${STAGEDIR}${DOCSDIR}/html/modules
	@${CP} -RP ${WRKSRC}/doc/howto ${STAGEDIR}${DOCSDIR}/html/howto
. endif
.endif
	@${INSTALL_MAN} ${WRKSRC}/src/ftpdctl.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/
.endif #!defined(_BUILDING_PROFTPD_MODULE)

.include <bsd.port.mk>
