# New ports collection makefile for:	samba
# Date created:				27 Dec 1999
# Whom:					Shinya Sasaki <pcmaster@osk3.3web.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	samba
PORTVERSION=	2.0.5a.2
CATEGORIES=	japanese net
MASTER_SITES=	ftp://ftp.samba.gr.jp/pub/samba-jp/${SAMBA_JP_NAME}/ \
		http://www3.osk.3web.ne.jp/~pcmaster/network/samba/
DISTNAME=	${SAMBA_JP_NAME}-1.3

MAINTAINER=	pcmaster@osk3.3web.ne.jp

Y2K=		http://us1.samba.org/samba/docs/sambay2k.html

SAMBA_JP_NAME=	${PORTNAME}-${PORTVERSION:R}-JP${PORTVERSION:E}

# directories
VARDIR=		/var
SAMBA_SPOOL=	${VARDIR}/spool/samba
SAMBA_LOGDIR=	${VARDIR}/log
SAMBA_PRIVATE=	${PREFIX}/private
SAMBA_CONFDIR=	${PREFIX}/etc
# sample files
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/samba.sh.sample
SAMPLE_CONFIG=	${SAMBA_CONFDIR}/smb.conf.default

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	 --libdir=${SAMBA_CONFDIR} \
		--localstatedir=${VARDIR} --with-swatdir=${PREFIX}/share/swat \
		--with-lockdir=${VARDIR}/spool/lock --with-privatedir=${SAMBA_PRIVATE}

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=--with-krb5=${KRB5_HOME}
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/source

MANLANG=	"" ja
MAN1=		nmblookup.1 smbstatus.1 smbclient.1 smbrun.1 smbtar.1 \
		testparm.1 testprns.1 make_smbcodepage.1 smbsh.1
MAN5=		smb.conf.5 smbpasswd.5 lmhosts.5
MAN7=		samba.7
MAN8=		smbd.8 nmbd.8 smbpasswd.8 swat.8 \
		smbmount.8 smbumount.8 smbmnt.8

post-extract:
	${MV} ${WRKDIR}/${SAMBA_JP_NAME} ${WRKDIR}/${DISTNAME}

post-install:
	${MKDIR} ${PREFIX}/share/examples/samba
	${CP} -rp ${WRKDIR}/${DISTNAME}/examples/* ${PREFIX}/share/examples/samba
	${CP} -rp ${WRKDIR}/${DISTNAME}/samba-jp/examples/* ${PREFIX}/share/examples/samba
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file." ;	\
		${INSTALL_SCRIPT} ${FILESDIR}/samba.sh.sample 		\
			${STARTUP_SCRIPT} ;				\
	fi
	@test -d ${SAMBA_SPOOL} || ${MKDIR} ${SAMBA_SPOOL} && ${CHMOD} 1777 ${SAMBA_SPOOL}
	@if [ ! -f ${SAMPLE_CONFIG} ]; then				\
		${SED} -e 's!%%SAMBA_SPOOL%%!${SAMBA_SPOOL}!'		\
			-e 's!%%SAMBA_LOGDIR%%!${SAMBA_LOGDIR}!'	\
			-e 's!%%SAMBA_CONFDIR%%!${SAMBA_CONFDIR}!'	\
			${FILESDIR}/smb.conf.default			\
			> ${SAMPLE_CONFIG} ;				\
	fi
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/source/script/mksmbpasswd.sh ${PREFIX}/bin/make_smbpasswd
	if [ ! -d ${SAMBA_PRIVATE} ] ; then				\
		${MKDIR} ${SAMBA_PRIVATE} ;				\
		${CHOWN} root.wheel ${SAMBA_PRIVATE} ;			\
	fi
	${CHMOD} 700 ${SAMBA_PRIVATE}
	if [ ! -f ${SAMBA_PRIVATE}/smbpasswd ] ; then			\
		${CAT} /etc/passwd | ${PREFIX}/bin/make_smbpasswd > ${SAMBA_PRIVATE}/smbpasswd ; \
		${CHMOD} 600 ${SAMBA_PRIVATE}/smbpasswd ;			\
	fi
	${CHMOD} 500 ${SAMBA_PRIVATE}
	${CHOWN} root.wheel ${PREFIX}/bin/smbpasswd
	${CHMOD} 111 ${PREFIX}/bin/smbpasswd

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/samba
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${PREFIX}/share/doc/samba
	for i in ${WRKDIR}/${DISTNAME}/README				\
			${WRKDIR}/${DISTNAME}/COPYING			\
			${WRKDIR}/${DISTNAME}/Manifest			\
			${WRKDIR}/${DISTNAME}/Read-Manifest-Now		\
			${WRKDIR}/${DISTNAME}/README-smbmount		\
			${WRKDIR}/${DISTNAME}/Roadmap			\
			${WRKDIR}/${DISTNAME}/WHATSNEW.txt		\
			${WRKDIR}/${DISTNAME}/WHATSNEW-jp		\
			${WRKDIR}/${DISTNAME}/WHATSNEW-jp.sjis.txt     	\
			${WRKDIR}/${DISTNAME}/samba-jp/reg/*.reg       	\
			${WRKDIR}/${DISTNAME}/docs/THANKS		\
			${WRKDIR}/${DISTNAME}/docs/announce		\
			${WRKDIR}/${DISTNAME}/docs/history ; do		\
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba ;		\
	done
	for i in faq htmldocs manpages textdocs yodldocs ; do		\
		${MKDIR} ${PREFIX}/share/doc/samba/$$i ;		\
		for j in ${WRKDIR}/${DISTNAME}/docs/$$i/* ; do		\
			${INSTALL_DATA} $$j ${PREFIX}/share/doc/samba/$$i ;\
		done							\
	done
	${MKDIR} ${PREFIX}/share/doc/samba/ja
	for i in ${WRKDIR}/${DISTNAME}/samba-jp/CREDITS.txt	       	\
			${WRKDIR}/${DISTNAME}/samba-jp/ML.txt		\
			${WRKDIR}/${DISTNAME}/samba-jp/PROGRESS.txt	\
			${WRKDIR}/${DISTNAME}/samba-jp/README.txt ; do	\
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/samba/ja ;\
	done
	for i in man docs ; do						\
		${MKDIR} ${PREFIX}/share/doc/samba/ja/$$i ;		\
		for j in ${WRKDIR}/${DISTNAME}/samba-jp/$$i/* ; do	\
			${INSTALL_DATA} $$j ${PREFIX}/share/doc/samba/ja/$$i ;\
		done							\
	done
	${MKDIR} ${PREFIX}/share/doc/samba
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/swat/README ${PREFIX}/share/doc/samba/README.swat
.endif

.include <bsd.port.mk>
