# New ports collection makefile for:	proftpd
# Date created:		26 January 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

PORTNAME?=	proftpd
PORTVERSION?=	1.3.4b
#PORTREVISION?=	0
CATEGORIES?=	ftp
MASTER_SITES=	ftp://ftp.proftpd.org/distrib/source/ \
		https://github.com/downloads/proftpd/proftpd.github.com/ \
		ftp://proftpd.networkedsystems.co.uk/distrib/source/ \
		http://www.mirrorservice.org/sites/ftp.proftpd.org/distrib/source/ \
		http://labratsoftware.com/mod_sql_tds/:sql_tds \
		LOCAL/beech:sql_tds
#		https://secure.thrallingpenguin.com/redmine/attachments/download/1/:clam
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
MAN1=	ftpcount.1 ftpmail.1 ftpasswd.1 ftpquota.1 ftpwho.1 ftptop.1
MAN5=	xferlog.5
MAN8=	proftpd.8 ftpscrub.8 ftpshut.8 ftpdctl.8

PORTDOCS=	*
.endif

MAKE_JOBS_UNSAFE=	yes
USE_GMAKE=	yes
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
OPTIONS_DEFINE=	HTMLDOCS IPV6 NLS MEMCACHE PCRE
OPTIONS_DEFAULT=	IPV6 NLS PCRE

#CLAMAV_DESC=		Include mod_clamav
HTMLDOCS_DESC=		Include HTML documentation
MEMCACHE_DESC=		Memcache support using libmemcached

PLIST_SUB+=	LOCALSTATEDIR="${LOCALSTATEDIR}"

.endif #!defined(_BUILDING_PROFTPD_MODULE)

.include <bsd.port.pre.mk>

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
USE_GETTEXT=yes
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

.if make(makesum) || defined(FETCH_ALL)
DISTFILES+=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		mod_sql_tds-4.13${EXTRACT_SUFX}:sql_tds
.endif

#.if ${PORT_OPTIONS:MCLAMAV} || make(makesum) || defined(FETCH_ALL)
#DISTFILES+=	mod_clamav-0.11rc.tar.gz:clam
#EXTRA_PATCHES+=	${FILESDIR}/extra-patch-modules_mod_xfer.c
#USE_CLAMAV=	yes
#MODULES+=	mod_clamav
#LIB_DEPENDS+=	clamav.7:${PORTSDIR}/security/clamav
#PLIST_SUB+=	CLAMAV=""
#PROFTPD_LIBS+=	-lclamav
#.else
PLIST_SUB+=	CLAMAV="@comment "
#.endif

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
#post-extract:
#.if ${PORT_OPTIONS:MCLAMAV}
#	(cd ${WRKDIR} && ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/mod_clamav-0.11rc.tar.gz ${EXTRACT_AFTER_ARGS})
#	@${CP} ${WRKDIR}/mod_clamav-0.11rc/mod_clamav.* ${WRKSRC}/contrib
#.endif

post-patch:
.if ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|-lsupp|-lsupp -lintl|g' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|proftpd\.conf|proftpd.conf.sample|g' ${WRKSRC}/Makefile.in

pre-configure:
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
.else
post-install:
	@cd  ${PREFIX}/etc/ && ${CP} -n proftpd.conf.sample proftpd.conf
	@${MKDIR} ${LOCALSTATEDIR}/proftpd
	@cd  ${PREFIX}/etc/proftpd && ${CP} -n dhparams.pem.sample dhparams.pem
	@cd  ${PREFIX}/etc/proftpd && ${CP} -n blacklist.dat.sample blacklist.dat
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${CP} README* RELEASE_NOTES ${DOCSDIR}
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} license.txt ${DOCSDIR}
. if ${PORT_OPTIONS:MHTMLDOCS}
	@${INSTALL} -d ${DOCSDIR}/html
	@cd ${WRKSRC}/doc/ && ${INSTALL_DATA} Configuration.html faq.html ${DOCSDIR}/html
	@${CP} -RP ${WRKSRC}/doc/contrib ${DOCSDIR}/html/contrib
	@${CP} -RP ${WRKSRC}/doc/modules ${DOCSDIR}/html/modules
	@${CP} -RP ${WRKSRC}/doc/howto ${DOCSDIR}/html/howto
. endif
.endif
	@${INSTALL_MAN} ${WRKSRC}/src/ftpdctl.8 ${MAN8PREFIX}/man/man8/
.endif #!defined(_BUILDING_PROFTPD_MODULE)

.include <bsd.port.post.mk>
