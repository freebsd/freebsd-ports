# New ports collection makefile for:	samba
# Date created:				27 Dec 1999
# Whom:					Shinya Sasaki <pcmaster@osk3.3web.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	samba
PORTVERSION=	${SAMBA_VERSION}.j${SAMBA_JA_VERSION}
CATEGORIES=	japanese net
MASTER_SITES=	ftp://ftp.samba.gr.jp/pub/samba-jp/%SUBDIR%/ \
		ftp://ftp.iij.ad.jp/pub/SAMBA/samba-jp/%SUBDIR%/ \
		ftp://SunSITE.sut.ac.jp/pub/archives/packages/samba/samba-jp/%SUBDIR%/ \
		ftp://ftp.plathome.co.jp/pub/samba/samba-jp/%SUBDIR%/ \
		ftp://ftp2.samba.gr.jp/pub/samba-jp/%SUBDIR%/ \
		ftp://ftp.tutrp.tut.ac.jp/pub/mirror/samba-jp/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${SAMBA_VERSION}-ja
DISTNAME=	${PORTNAME}-${SAMBA_VERSION}-ja-${SAMBA_JA_VERSION}

MAINTAINER=	nakaji@jp.FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

SAMBA_VERSION=		2.2.2
SAMBA_JA_VERSION=	1.0

# directories
VARDIR=		/var
SAMBA_SPOOL=	${VARDIR}/spool/samba
SAMBA_LOGDIR=	${VARDIR}/log
SAMBA_PRIVATE=	${PREFIX}/private
SAMBA_CONFDIR=	${PREFIX}/etc
# sample files
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${SAMBA_CONFDIR}/smb.conf.default

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-i18n-swat --with-included-gettext \
		--libdir=${SAMBA_CONFDIR} \
		--localstatedir=${VARDIR} --with-swatdir=${PREFIX}/share/swat \
		--with-lockdir=${VARDIR}/db/samba \
		--with-privatedir=${SAMBA_PRIVATE} \
		--prefix=${PREFIX}

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=--with-krb5=${KRB5_HOME}
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/source

MAN1=		findsmb.1 nmblookup.1 rpcclient.1 smbcacls.1 \
		smbcontrol.1 smbstatus.1 smbclient.1 smbrun.1 smbtar.1 \
		testparm.1 testprns.1 make_smbcodepage.1 smbsh.1 \
		make_unicodemap.1 wbinfo.1
MAN5=		smb.conf.5 smbpasswd.5 lmhosts.5
MAN7=		samba.7
MAN8=		smbd.8 nmbd.8 smbpasswd.8 swat.8 smbspool.8 \
		smbmnt.8 smbmount.8 smbumount.8 winbindd.8
MANLANG=	"" ja

post-build:
	${SED} 's:/usr/local:${PREFIX}:g' ${FILESDIR}/samba.sh.sample \
		> ${WRKDIR}/samba.sh.sample

post-install:
	@${STRIP_CMD} ${PREFIX}/sbin/smbd ${PREFIX}/sbin/nmbd ${PREFIX}/sbin/swat
	@${STRIP_CMD} ${PREFIX}/bin/smbclient ${PREFIX}/bin/smbspool
	@${STRIP_CMD} ${PREFIX}/bin/testparm ${PREFIX}/bin/testprns ${PREFIX}/bin/testprns ${PREFIX}/bin/smbstatus ${PREFIX}/bin/smbcontrol ${PREFIX}/bin/make_printerdef
	@${STRIP_CMD} ${PREFIX}/bin/smbpasswd ${PREFIX}/bin/make_smbcodepage ${PREFIX}/bin/rpcclient ${PREFIX}/bin/make_unicodemap ${PREFIX}/bin/make_nftable ${PREFIX}/bin/smbcacls ${PREFIX}/bin/nmblookup
	@${MKDIR} ${PREFIX}/share/examples/samba
	@cd ${WRKDIR}/${DISTNAME}/examples; \
		${TAR}  --exclude .cvsignore -cf - . | ${TAR} -xf - -C ${PREFIX}/share/examples/samba
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
	@${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/source/script/mksmbpasswd.sh ${PREFIX}/bin/make_smbpasswd

	@${MKDIR} -p -m 500 ${SAMBA_PRIVATE}
	@${CHOWN} root:wheel ${SAMBA_PRIVATE}
	@${CAT} /etc/passwd | ${PREFIX}/bin/make_smbpasswd > ${SAMBA_PRIVATE}/smbpasswd.default
	@if [ ! -e ${SAMBA_PRIVATE}/smbpasswd ]; then	\
		${CP} -p ${SAMBA_PRIVATE}/smbpasswd.default ${SAMBA_PRIVATE}/smbpasswd ;	\
	fi
	@${CHMOD} 600 ${SAMBA_PRIVATE}/smbpasswd*

	@${CHOWN} root:wheel ${PREFIX}/bin/smbpasswd
	@${CHMOD} 111 ${PREFIX}/bin/smbpasswd

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/samba
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${PREFIX}/share/doc/samba
	@for i in ${WRKDIR}/${DISTNAME}/README				\
			${WRKDIR}/${DISTNAME}/COPYING			\
			${WRKDIR}/${DISTNAME}/Manifest			\
			${WRKDIR}/${DISTNAME}/Read-Manifest-Now		\
			${WRKDIR}/${DISTNAME}/Roadmap			\
			${WRKDIR}/${DISTNAME}/WHATSNEW.txt; do		\
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba ;		\
	done
	@cd ${WRKDIR}/${DISTNAME}/docs; \
		${TAR}  --exclude .cvsignore -cf - . | ${TAR} -xf - -C ${PREFIX}/share/doc/samba
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/swat/README ${PREFIX}/share/doc/samba/README.swat
.endif

	@if [ -f ${VARDIR}/spool/lock/browse.dat ]; then \
		${RM} -f ${VARDIR}/spool/lock/browse.dat; \
	fi

.include <bsd.port.mk>
