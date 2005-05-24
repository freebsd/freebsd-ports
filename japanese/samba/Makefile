# New ports collection makefile for:	samba
# Date created:				27 Dec 1999
# Whom:					Shinya Sasaki <pcmaster@osk3.3web.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	samba
PORTVERSION=	${SAMBA_VERSION}.j${SAMBA_JA_VERSION}
PORTREVISION=	2
CATEGORIES=	japanese net
MASTER_SITES=	ftp://ftp.samba.gr.jp/pub/samba-jp/%SUBDIR%/ \
		ftp://ftp.iij.ad.jp/pub/SAMBA/samba-jp/%SUBDIR%/ \
		ftp://SunSITE.tus.ac.jp/pub/archives/packages/samba/samba-jp/%SUBDIR%/ \
		ftp://ftp.plathome.co.jp/pub/samba/samba-jp/%SUBDIR%/ \
		ftp://ftp2.samba.gr.jp/pub/samba-jp/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${SAMBA_VERSION}-ja/beta
DISTNAME=	${PORTNAME}-${SAMBA_VERSION}-ja-${SAMBA_JA_VERSION}

MAINTAINER=	nakaji@jp.FreeBSD.org
COMMENT=	A free SMB and CIFS client and server for UNIX

CONFLICTS=	samba-2.2.* samba-3.0.* sharity-light-1.*

SAMBA_VERSION=		2.2.12
SAMBA_JA_VERSION=	1.0beta1

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=	253

# directories
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

AUDIT?=		"@comment "
RECYCLE?=	"@comment "
LIBSAMBA?=	"@comment "
BUILD_VFS?=	"@comment "
LDAPSAM?=	"@comment "
WINBIND?=	"@comment "
SMBSH?=		"@comment "

VARDIR=		/var
SAMBA_SPOOL=	${VARDIR}/spool/samba
SAMBA_LOGDIR=	${VARDIR}/log
SAMBA_RUNDIR=	${VARDIR}/run
SAMBA_LOCKDIR=	${VARDIR}/db/samba
SAMBA_PRIVATE=	${PREFIX}/private
SAMBA_CONFDIR=	${PREFIX}/etc
SAMBA_SWATDIR=	${PREFIX}/share/swat
SAMBA_VFSDIR=	${PREFIX}/lib/samba
SAMBA_CONFIG=	${SAMBA_CONFDIR}/smb.conf

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		CAT="${CAT}" \
		SAMBA_OPTIONS="${SAMBA_OPTIONS}" \
		REALCURDIR="${.CURDIR}"
# sample files
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh
SAMPLE_CONFIG=	${SAMBA_CONFDIR}/smb.conf.default

OPTIONS+=	SYSLOG		"With Syslog support" on \
		SSL		"With SSL support" on \
		LDAP		"With LDAP2 support" off \
		CUPS		"With CUPS" off \
		ACL		"With ACL support" off \
		UTMP		"With UTMP support" on \
		MSDFS		"With MSDFS support" on \
		QUOTA		"With Quota support" on \
		RECYCLE		"With Recycle Bin" on \
		AUDIT		"With Audit" on \
		WINBIND		"With Winbind" on \
		WBAUTH		"With Winbind Auth Challenge" on \
		SMBSH		"With Smbsh and smbwrapper" on

.include <bsd.port.pre.mk>

USE_RC_SUBR=	yes

CONFIGURE_ARGS=	--with-i18n-swat \
		--libdir=${SAMBA_CONFDIR} \
		--localstatedir=${VARDIR} --with-swatdir=${SAMBA_SWATDIR} \
		--with-lockdir=${SAMBA_LOCKDIR} \
		--with-logfilebase=${SAMBA_LOGDIR} \
		--with-privatedir=${SAMBA_PRIVATE} \
		--with-piddir=${VARDIR}/run \
		--with-pam --with-pam_smbpass \
		--with-included-popt

.if defined(WITH_AUDIT)
.if ${ARCH} == "i386"
AUDIT=		""
LIBSAMBA=	""
BUILD_VFS=	""
.else
BROKEN=		"VFS related feature is available for i386 only"
.endif
.endif

.if defined(WITH_RECYCLE)
.if ${ARCH} == "i386"
RECYCLE=	""
LIBSAMBA=	""
BUILD_VFS=	""
.else
BROKEN=		"VFS related feature is available for i386 only"
.endif
.endif

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--with-syslog
.endif

.if defined(WITH_SSL)
CONFIGURE_ARGS+=	--with-ssl --with-sslinc=/usr/include/openssl --with-ssllib=/usr/lib
.endif

.if defined(WITH_QUOTAS)
CONFIGURE_ARGS+=	--with-quotas
.endif

.if defined(WITH_UTMP)
CONFIGURE_ARGS+=	--with-utmp
.endif

.if defined(WITH_MSDFS)
CONFIGURE_ARGS+=	--with-msdfs
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldapsam
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
LDAPSAM=	""
.endif

.if defined(WITH_WINBIND)
CONFIGURE_ARGS+=	--with-winbind
WINBIND=	""
WINBIND_FILTER=	${SED} -e 's|%%WINBIND%%||g'
.else
WINBIND_FILTER=	${GREP} -v '^%%WINBIND%%'
.endif

.if defined(WITH_WINBIND_AUTH_CHALLENGE)
CONFIGURE_ARGS+=	--with-winbind-auth-challenge
.endif

.if defined(WITH_SMBSH)
CONFIGURE_ARGS+=	--with-smbwrapper --with-libsmbclient
SMBSH=		""
.endif

# malloc.h check is not needed.
CONFIGURE_ENV+=	ac_cv_header_malloc_h=no

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if defined(WITH_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=--disable-cups
.endif

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=--with-krb5=${KRB5_HOME}
.endif

.if defined(WITH_ACL_SUPPORT)
.if ${OSVERSION} < 500018
BROKEN=	"ACL support requires a recent FreeBSD 5.0-CURRENT"
.else
CONFIGURE_ARGS+=	--with-acl-support
.endif
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/source

MAN1=		findsmb.1 nmblookup.1 rpcclient.1 smbcacls.1 \
		smbcontrol.1 smbstatus.1 smbclient.1 smbtar.1 \
		testparm.1 testprns.1 make_smbcodepage.1 smbsh.1 \
		make_unicodemap.1 wbinfo.1
MAN5=		smb.conf.5 smbpasswd.5 lmhosts.5
MAN7=		samba.7
MAN8=		smbd.8 nmbd.8 smbpasswd.8 swat.8 smbspool.8 \
		smbmnt.8 smbmount.8 smbumount.8 winbindd.8 \
		pdbedit.8
MANLANG=	"" ja

SED_PLIST=	${SED} -e 's!${PREFIX}!%D!g'

PLIST_SUB=	AUDIT=${AUDIT} \
		RECYCLE=${RECYCLE} \
		LIBSAMBA=${LIBSAMBA} \
		BUILD_VFS=${BUILD_VFS} \
		LDAPSAM=${LDAPSAM} \
		WINBIND=${WINBIND} \
		SMBSH=${SMBSH}

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		CUPS=${CUPS} \
		RC_SUBR=${RC_SUBR} \
		SAMBA_CONFDIR=${SAMBA_CONFDIR} \
		SAMBA_CONFIG=${SAMBA_CONFIG} \
		SAMBA_LOGDIR=${SAMBA_LOGDIR} \
		SAMBA_RUNDIR=${SAMBA_RUNDIR} \
		SAMBA_LOCKDIR=${SAMBA_LOCKDIR} \
		SAMBA_SPOOL=${SAMBA_SPOOL}

post-patch:
	${FIND} ${WRKSRC}/.. -name '*.orig' -delete

pre-build:
	${RM} -fr ${WRKSRC}/include/proto.h
	(cd ${WRKSRC} && make proto)

post-build:
	${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
	   ${FILESDIR}/samba.sh.sample | ${WINBIND_FILTER} > ${WRKDIR}/samba.sh.sample
.if defined(WITH_RECYCLE) || defined(WITH_AUDIT)
	cd ${WRKSRC}/../examples/VFS; \
		./configure;${MAKE}; \
		${RM} -f config.cache config.log config.status
.endif

post-install:
.if defined(WITH_AUDIT) || defined(WITH_RECYCLE)
	@test -d ${SAMBA_VFSDIR} || ${MKDIR} ${SAMBA_VFSDIR}
.if defined(WITH_AUDIT)
	@${INSTALL_PROGRAM} ${WRKSRC}/../examples/VFS/audit.so ${SAMBA_VFSDIR}
.endif
.if defined(WITH_RECYCLE)
	@${INSTALL_PROGRAM} ${WRKSRC}/../examples/VFS/recycle/recycle.so ${SAMBA_VFSDIR}
.endif
.endif
	@${MKDIR} ${PREFIX}/share/examples/samba
	@-${RM} -f ${WRKSRC}/../examples/libsmbclient/*.o
	@cd ${WRKSRC}/../examples; \
		${TAR}  --exclude .cvsignore --exclude .libs --exclude '*.o' --exclude '*.lo' -cf - . | ${TAR} -xf - -C ${PREFIX}/share/examples/samba
	@${STRIP_CMD} ${PREFIX}/sbin/smbd ${PREFIX}/sbin/nmbd ${PREFIX}/sbin/swat
	@${STRIP_CMD} ${PREFIX}/bin/smbclient ${PREFIX}/bin/smbspool
	@${STRIP_CMD} ${PREFIX}/bin/testparm ${PREFIX}/bin/testprns ${PREFIX}/bin/testprns ${PREFIX}/bin/smbstatus ${PREFIX}/bin/smbcontrol ${PREFIX}/bin/make_printerdef
	@${STRIP_CMD} ${PREFIX}/bin/smbpasswd ${PREFIX}/bin/make_smbcodepage ${PREFIX}/bin/rpcclient ${PREFIX}/bin/make_unicodemap ${PREFIX}/bin/smbcacls ${PREFIX}/bin/nmblookup
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file." ;	\
		${INSTALL_SCRIPT} ${WRKDIR}/samba.sh.sample 		\
			${STARTUP_SCRIPT} ;				\
	fi
	@test -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && ${CHMOD} 1777 ${SAMBA_SPOOL}
	@test -d ${VARDIR}/db/samba || ${MKDIR} ${VARDIR}/db/samba && ${CHMOD} 0755 ${VARDIR}/db/samba
	@if [ ! -f ${SAMPLE_CONFIG} ]; then				\
		${SED} -e 's!%%SAMBA_SPOOL%%!${SAMBA_SPOOL}!'		\
			-e 's!%%SAMBA_LOGDIR%%!${SAMBA_LOGDIR}!'	\
			-e 's!%%SAMBA_CONFDIR%%!${SAMBA_CONFDIR}!'	\
			${FILESDIR}/smb.conf.default			\
			> ${SAMPLE_CONFIG} ;				\
	fi
	@${INSTALL_SCRIPT} ${WRKSRC}/../source/script/mksmbpasswd.sh ${PREFIX}/bin/make_smbpasswd

	@${MKDIR} -m 500 ${SAMBA_PRIVATE}
	@${CHOWN} root:wheel ${SAMBA_PRIVATE}

	@${CHOWN} root:wheel ${PREFIX}/bin/smbpasswd
	@${CHMOD} 111 ${PREFIX}/bin/smbpasswd
	@${ECHO_CMD} "@exec ${TEST} -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && ${CHMOD} 1777 ${SAMBA_SPOOL}" | ${SED_PLIST} >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RM} -rf ${SAMBA_SPOOL}" | ${SED_PLIST} >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${MKDIR} -m 500 ${SAMBA_PRIVATE}" | ${SED_PLIST} >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} root:wheel ${SAMBA_PRIVATE}" | ${SED_PLIST} >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CAT} /etc/passwd | ${GREP} -v "^#" | ${PREFIX}/bin/make_smbpasswd > ${SAMBA_PRIVATE}/smbpasswd.default" | ${SED_PLIST} >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TEST} -e ${SAMBA_PRIVATE}/smbpasswd || ${CP} -p ${SAMBA_PRIVATE}/smbpasswd.default ${SAMBA_PRIVATE}/smbpasswd" | ${SED_PLIST} >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 600 ${SAMBA_PRIVATE}/smbpasswd*" | ${SED_PLIST} >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec /usr/bin/cmp -s ${SAMBA_PRIVATE}/smbpasswd ${SAMBA_PRIVATE}/smbpasswd.default && ${RM} -f ${SAMBA_PRIVATE}/smbpasswd ${SAMBA_PRIVATE}/secrets.tdb || ${TRUE}" | ${SED_PLIST} >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RM} -f ${SAMBA_PRIVATE}/smbpasswd.default" | ${SED_PLIST} >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} ${SAMBA_PRIVATE} || (${ECHO_CMD} \"Warning: If you will *NOT* use this package anymore,\" && ${ECHO_CMD} \"         please remove ${SAMBA_PRIVATE} and its contents manually.\")" | ${SED_PLIST} >> ${TMPPLIST}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/samba
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${PREFIX}/share/doc/samba
	@for i in ${WRKSRC}/../README				\
			${WRKSRC}/../COPYING			\
			${WRKSRC}/../Manifest			\
			${WRKSRC}/../Read-Manifest-Now		\
			${WRKSRC}/../Roadmap			\
			${WRKSRC}/../WHATSNEW.txt; do		\
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba ;		\
	done
	@cd ${WRKSRC}/../docs; \
		${TAR}  --exclude .cvsignore -cf - . | ${TAR} -xf - -C ${PREFIX}/share/doc/samba
	@${INSTALL_DATA} ${WRKSRC}/../swat/README ${PREFIX}/share/doc/samba/README.swat
.endif

	@if [ -f ${VARDIR}/spool/lock/browse.dat ]; then \
		${RM} -f ${VARDIR}/spool/lock/browse.dat; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
