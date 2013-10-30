# Created by: Andrew Dolgov <fox@furry.spb.ru>
# $FreeBSD$

PORTNAME=	bforce
PORTVERSION=	0.22.8.7
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	SF/binkleyforce/${PORTNAME}/0.22.8.kst7
PKGNAMESUFFIX=	-kst
DISTNAME=	${PORTNAME}-0.22.8.kst7

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple ifcico like Fidonet technology mailer

USES=		gmake
GNU_CONFIGURE=	yes

CONTRIBS=	bfha/README bfha/bfha.pl bflan callout.sh outman timesync.tcl \
		u-srif/conf/report.footer u-srif/conf/report.header u-srif/conf/u-srif.aliases \
		u-srif/conf/u-srif.conf u-srif/conf/u-srif.dirs u-srif/lib/uconfig.py \
		u-srif/lib/udbase.py u-srif/lib/ufido.py u-srif/lib/unodestat.py \
		u-srif/lib/utmpl.py u-srif/lib/uutil.py u-srif/u-srif-index.py \
		u-srif/u-srif-lookup.py u-srif/u-srif.py

FIXME=		include/bforce.h include/util.h include/logger.h \
		bforce/bforce.c bforce/conf_proc.c bforce/conf_read.c bforce/daemon.c \
		bforce/daemon_branch.c bforce/daemon_call.c  bforce/daemon_lines.c \
		bforce/expression.y bforce/freq_proc.c bforce/freq_wazoo.c bforce/io_modem.c \
		bforce/io_tcpip.c bforce/io_unix_lock.c bforce/io_unix_modem.c \
		bforce/io_unix_tio.c bforce/io_unix_tty.c bforce/logger.c bforce/nodelist.c \
		bforce/os_unix.c bforce/outb_sysqueue.c bforce/prot_common.c bforce/prot_binkp.c \
		bforce/prot_binkp_misc.c bforce/prot_hydra.c bforce/prot_zmmisc.c \
		bforce/prot_zmrecv.c bforce/prot_zmsend.c bforce/prot_yoohoo.c \
		bforce/prot_yoohoo_api.c bforce/prot_emsi.c bforce/prot_emsi_misc.c \
		bforce/prot_emsi_api.c bforce/sess_call.c bforce/sess_answ.c bforce/sess_init.c \
		bforce/sess_main.c bforce/u_misc.c bforce/u_time.c bforce/u_recode.c \
		bforce/u_plock.c bfutil/bfindex.c

WRKSRC=		${WRKDIR}/${DISTNAME}/source

PORTDOCS=	CHANGES CHANGES.kst COPYING README README.kst

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
pre-configure:
	@${MKDIR} ${WRKSRC}/bin

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/bforce,/etc/fido/bforce,g' ${WRKSRC}/Makefile.in
.for i in ${FIXME}
	@${REINPLACE_CMD} -e 's,log(,bf_log(,g' ${WRKSRC}/${i}
.endfor

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${PREFIX}/etc/fido/bforce
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.conf ${PREFIX}/etc/fido/bforce/bforce.conf.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.passwd ${PREFIX}/etc/fido/bforce/bforce.passwd.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/bforce.subst ${PREFIX}/etc/fido/bforce/bforce.subst.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/freq.aliases ${PREFIX}/etc/fido/bforce/freq.aliases.sample
	${INSTALL_DATA} ${WRKSRC}/../examples/freq.dirs ${PREFIX}/etc/fido/bforce/freq.dirs.sample

	${MKDIR} ${DATADIR} ${DATADIR}/bfha ${DATADIR}/u-srif/conf ${DATADIR}/u-srif/lib
.for i in ${CONTRIBS}
	${INSTALL_DATA} ${WRKSRC}/../contrib/${i} ${DATADIR}/${i}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bforce ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bfindex ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bfstat ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nlookup ${PREFIX}/bin
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|' -e 's|%%CONFIGDIR%%|etc/fido/bforce|' ${PKGMESSAGE}

.include <bsd.port.mk>
